#include "Nivel5.h"
#include "Enemigo.h"


Nivel5::Nivel5(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a) : Play(j)
{
	enem = 0;
	emax = 40;
	for (unsigned int i = 0; i < 4; i++) {
		tren.emplace_back(new Vagon(ptsjuego, this, 580, 100 + 150 * i, v[i]));
	}
	arma = a;
	shootTimer = 0;
	spawnTimer = 0;
	//Falta por completar conforme se implementen las nuevas clases y me da palo hacerlo para nada ^^'
	switch (a)
	{

	case Game::Piedra: cadencia = 800;//0'8s || 800 ms 
		break;
	case Game::Escopeta: cadencia = 700;
		break;
	case Game::Pistola: cadencia = 600;//0'6s || 600 ms 
		break;
	case Game::Metralleta: cadencia = 200;
		break;
	case Game::Sniper: cadencia = 1000;
		break;
	case Game::Minigun: cadencia = 100;
		break;
	default:
		break;
	}
	esc = new Escenario(ptsjuego, Game::Texturas_t::TFondo, 0, -4200);
}


void Nivel5::update(Uint32 delta) {
	shootTimer += delta;
	spawnTimer += delta;

	if (disparando && shootTimer >= cadencia) {
		balas.emplace_back(new Bala(ptsjuego, this, player->getPos().x, player->getPos().y + 10, player->getMira(), arma));
		shootTimer = 0;
	}

	if (enem < emax - 2) {
		if (spawnTimer >= 1380) {

			if (rand() % 2 == 0) {
				if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Normal));
				else  enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Normal));
				enem++;
			}
			else {
				if (rand() % 2 == 0) {
				     if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 140, Game::Enemigo_t::Rapido));
				     else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 140, Game::Enemigo_t::Rapido));
				     enem++;
				}
				else {
					if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 130, Game::Enemigo_t::ElQueDispara));
					else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 130, Game::Enemigo_t::ElQueDispara));
					enem++;
				}
			}
			spawnTimer = 0;
		}
	}
	else {
		if (!created) {
			enems.emplace_back
			(new Enemigo(ptsjuego, this, 0, 550, Game::Enemigo_t::Tank));
			created = true;
			enems.emplace_back
			(new Enemigo(ptsjuego, this, 1300, 650, Game::Enemigo_t::Tank));
			created = true;
		}


	}
	if (emax == Play::getKilled()) {
		Play::finish();

	}

	Play::update(delta);

}

void Nivel5::draw() {
	Play::draw();

	font->loadFromText(ptsjuego->pRender, "$ " + std::to_string(ptsjuego->coins), fontColor);
	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(60, 60, 50, 70));
}