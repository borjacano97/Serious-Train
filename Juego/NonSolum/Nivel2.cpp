#include "Nivel2.h"
#include "Enemigo.h"


Nivel2::Nivel2(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a) : Play(j)
{
	enem = 0;
	emax = 15;
	for (unsigned int i = 0; i < 4; i++) {
		tren.emplace_back(new Vagon(ptsjuego, this, 580, 100 +150*i, v[i]));
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
	case Game::Sniper: cadencia = 1000;
		break;
	case Game::Metralleta: cadencia = 200;
		break;
	default:
		break;
	}
	initLibraries();
	sound = new Sound;
	sound->playMusic("../sounds/inGameMusic2.mp3", 1);
	esc = new Escenario(ptsjuego, Game::Texturas_t::TFondo, 0, -4200);
}
void Nivel2::onClick() {
	if (shootTimer >= cadencia) {
		shootTimer = 0;
		balas.emplace_back(new Bala(ptsjuego, this, player->getPos().x, player->getPos().y, player->getMira(), arma));
	}
}
void Nivel2::update(Uint32 delta) {
	shootTimer += delta;
	spawnTimer += delta;
	if (enem < emax){
		 //generar zombies aleatorios
		if (spawnTimer >= 1500){
			if (rand() % 2 == 0) {
				if (rand() % 2 == 0) enems.emplace_back
					(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 300, Game::Enemigo_t::Normal));
				else enems.emplace_back
					(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 300, Game::Enemigo_t::Normal));
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

bool Nivel2::initLibraries() {
	TTF_Init();
	/*if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
	return false;
	}
	return true;*/
	return Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) != -1;
}