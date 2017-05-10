#include "Nivel1.h"
#include "Enemigo.h"
#include "Escenario.h"


Nivel1::Nivel1(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a) : Play(j)
{
	enem = 0;
	emax = 10;
	for (unsigned int i = 0; i < 4; i++) {
		tren.emplace_back(new Vagon(ptsjuego, this, 580, 100 + 150 * i, v[i]));
	}
	arma = a;
	shootTimer = 0;
	spawnTimer = 0;
	cont = 0;
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
	case Game::Canon: cadencia = 1700;
		break;
	default:
		break;
	}

	//tray = new Hud(ptsjuego, 0, 0, Game::Hud_t::Trayecto);
	esc = new Escenario(ptsjuego, Game::Texturas_t::TFondo, 0, -4280);

	TTF_Init();

	textoIz = new Texturas();
	textoIz->loadFuente("../fonts/fuenteNumbers.ttf", 250);

	textoDer = new Texturas();
	textoDer->loadFuente("../fonts/fuenteNumbers.ttf", 250);

	colorTexto.r = 218;
	colorTexto.g = 165;
	colorTexto.b = 32;
}


	

void Nivel1::update(Uint32 delta) {

	shootTimer += delta;
	spawnTimer += delta;

	if (disparando && shootTimer >= cadencia) {
		balas.emplace_back(new Bala(ptsjuego, this, player->getPos().x, player->getPos().y + 10, player->getMira(), arma));
		shootTimer = 0;
	}
	if (!firstZombieTime && cont <= 6000){
		cont+=delta;
	}
	else firstZombieTime = true;
	if (enem < emax && firstZombieTime){
		//generar zombies aleatorios
		if (spawnTimer >= 1500){			
			if (rand()%2 == 0) {				
				if (rand() % 2 == 0) enems.emplace_back
					(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Normal));
				else enems.emplace_back
					(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Normal));
				enem++;
			}
			spawnTimer = 0;
		}				
	}
	else if (emax == Play::getKilled()){
		Play::finish();

	}


	Play::update(delta);

}
void Nivel1::draw() {
	Play::draw();

	font->loadFromText(ptsjuego->pRender, "$ " + std::to_string(ptsjuego->coins), fontColor);
	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, 50, 170, 53));	
	if (ptsjuego->spanish){
		if (enem < 1){
			textoIz->loadFromText(ptsjuego->pRender, "Meneate con WASD!", fontColor);
			textoIz->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, 400, 80, 180));
		}
		else if(enem >= 1 && enem <= 6){
			textoIz->loadFromText(ptsjuego->pRender, "Presiona el raton para flipar!", fontColor);
			textoIz->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, 400, 80, 180));
		}
	}
}