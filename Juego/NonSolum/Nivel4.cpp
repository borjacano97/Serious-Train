#include "Nivel4.h"
#include "Enemigo.h"


Nivel4::Nivel4(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a) : Play(j)
{
	enem = 0;
	emax = 20;
	for (unsigned int i = 0; i < 4; i++) {
		tren.emplace_back(new Vagon(ptsjuego, this, 580, 100 + 150 * i, v[i]));
	}
	arma = a;
	timer = 0;
	//Falta por completar conforme se implementen las nuevas clases y me da palo hacerlo para nada ^^'
	switch (a)
	{

	case Game::Piedra: cadencia = 800;//0'8s || 800 ms 
		break;
	case Game::Escopeta: cadencia = 700;
		break;
	case Game::Pistola: cadencia = 600;//0'6s || 600 ms 
		break;
	case Game::Sniper: cadencia = 800;
		break;
	case Game::Metralleta: cadencia = 200;
		break;
	default:
		break;
	}
}

void Nivel4::onClick() {
	if (timer >= cadencia) {
		balas.emplace_back(new Bala(ptsjuego, this, player->getPos().x, player->getPos().y, player->getMira(), arma));
		timer = 0;
	}
}
void Nivel4::update(Uint32 delta) {
	timer += delta;
	if (enem < emax-1){
		aleatorio = rand() % 10000; //generar zombies aleatorios
		if (aleatorio >= 9992) {
			izq = rand() % 2;
			if (izq == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) - 100, Game::Enemigo_t::Normal));
			else enems.emplace_back(new Enemigo(ptsjuego, this,  1300, (rand() % 550) - 100, Game::Enemigo_t::Normal));
			enem++;
		}
		else if (aleatorio >= 9985) {
			izq = rand() % 2;
			if (izq == 0) enems.emplace_back(new Enemigo(ptsjuego, this,  0, (rand() % 550) + 50, Game::Enemigo_t::Rapido));
			else enems.emplace_back(new Enemigo(ptsjuego, this,  1300, (rand() % 550) + 50, Game::Enemigo_t::Rapido));
			enem++;
		}
	}
	else {
		if (!created){
			enems.emplace_back
				(new Enemigo(ptsjuego, this,  0, (rand() % 550) - 100, Game::Enemigo_t::Tank));
			created = true;
		}

	}
	if (emax == Play::getKilled()){
		Play::finish();
	}


	Play::update(delta);

}