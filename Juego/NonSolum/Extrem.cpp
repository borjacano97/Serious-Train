#include "Extrem.h"


Extrem::Extrem(Game * j) : Play(j)
{
	for (unsigned int i = 0; i < 4; i++) {
		tren.emplace_back(new Vagon(ptsjuego, this, 580, 100 + 150 * i, Game::Vagon_t::Vacio));
	}
	

	arma = Game::Bala_t::Minigun;
	cadencia = 100;

	shootTimer = 0;
	spawnTimer = 0;
	textInit = 0;

	contRondas = 1;

	enem = 0; // variable que cuenta los enemigos creados por ronda

	TTF_Init();
	textTut = new Texturas();
	textTut->loadFuente("../fonts/fuenteNumbers.ttf", 200);
}

void Extrem::update(Uint32 delta) {

	shootTimer += delta;
	spawnTimer += delta;

	if (disparando && shootTimer >= cadencia) {
		balas.emplace_back(new Bala(ptsjuego, this, player->getPos().x, player->getPos().y + 10, player->getMira(), arma));
		shootTimer = 0;
	}


	switch (contRondas % 6) // 6 tipos de enemigos
	{
	case (1) :
		spawn = 750 - (3*contRondas); // ha de variar entre rondas
		lastEnemy = 30 + (2 * contRondas);
		if (enem < lastEnemy && spawnTimer >= spawn) {
				if (rand() % 2 == 0) enems.emplace_back
					(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 300, Game::Enemigo_t::Normal));
				else enems.emplace_back
					(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 300, Game::Enemigo_t::Normal));
				enem++;
				spawnTimer = 0;
			}
			
		
		break;
	case (2) :
		spawn = 650 - (3 * contRondas);
		lastEnemy = 25 + (2 * contRondas);
		if (enem < lastEnemy && spawnTimer >= spawn) {
			if (newRonda) {
				spawn -= 9000;
				newRonda = false;
			}
			else{
				if (rand() % 2 == 0) enems.emplace_back
					(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
				else enems.emplace_back
					(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
				enem++;
				spawnTimer = 0;
			}
		}
		break;
	case (3) :
		spawn = 950 - (3 * contRondas);
		lastEnemy = 20 + (2 * contRondas);
		if (enem < lastEnemy && spawnTimer >= spawn) {
			if (newRonda) {
				spawn -= 9000;
				newRonda = false;
			}
			else{
				if (rand() % 2 == 0) enems.emplace_back
					(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 250, Game::Enemigo_t::Invisible));
				else enems.emplace_back
					(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 250, Game::Enemigo_t::Invisible));
				enem++;
				spawnTimer = 0;
			}
		}
		break;
	case (4) :
		spawn = 2950 - (3 * contRondas);
		lastEnemy = 7 + (2 * contRondas);
		if (enem < lastEnemy && spawnTimer >= spawn) {
			if (newRonda) {
				spawn -= 9000;
				newRonda = false;
			}
			else{
				if (rand() % 2 == 0) enems.emplace_back
					(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 300, Game::Enemigo_t::Tank));
				else enems.emplace_back
					(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 300, Game::Enemigo_t::Tank));
				enem++;
				spawnTimer = 0;
			}
		}
		break;
	case (5) :
		spawn = 1450 - (3 * contRondas);
		lastEnemy = 20 + (2 * contRondas);
		if (enem < lastEnemy && spawnTimer >= spawn) {
			if (newRonda) {
				spawn -= 9000;
				newRonda = false;
			}
			else{
				if (rand() % 2 == 0) enems.emplace_back
					(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 120, Game::Enemigo_t::Enano));
				else enems.emplace_back
					(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 120, Game::Enemigo_t::Enano));
				enem++;
				spawnTimer = 0;
			}
		}
		break;
	case (0) :
		spawn = 3350 - (3 * contRondas);
		lastEnemy = 5 +  (2 * contRondas);
		if (enem < lastEnemy && spawnTimer >= spawn) {
			if (newRonda) {
				spawn -= 9000;
				newRonda = false;
			}
			else{
				if (rand() % 2 == 0) enems.emplace_back
					(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 300, Game::Enemigo_t::Tocho));
				else enems.emplace_back
					(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 300, Game::Enemigo_t::Tocho));
				enem++;
				spawnTimer = 0;
			}
		}
		break;
	default:
		break;
	}


	if (killed >= lastEnemy) {

		enem = 0;
		spawnTimer = 0;
		killed = 0;

		newRonda = true;

		contRondas++;
		spawn += 9000; 
	}

	textInit += delta;
	Play::update(delta);
}
void Extrem::draw() {
	Play::draw();


	if (ptsjuego->spanish) {
		font->loadFromText(ptsjuego->pRender, " Ronda: " + std::to_string(contRondas), fontColor);
	}
	else {
		font->loadFromText(ptsjuego->pRender, " Round: " + std::to_string(contRondas), fontColor);
	}

	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, 90, 150, 53));


	if (newRonda && ptsjuego->spanish) {
		font->loadFromText(ptsjuego->pRender, " Nueva    Ronda:  " + std::to_string(contRondas), fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(220, 500, 400, 120));
	}
	if (newRonda && !ptsjuego->spanish) {
		font->loadFromText(ptsjuego->pRender, " New    Round:    " + std::to_string(contRondas), fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(220, 500, 400, 120));
	}
}