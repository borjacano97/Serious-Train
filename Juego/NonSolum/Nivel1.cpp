#include "Nivel1.h"
#include "Enemigo.h"


Nivel1::Nivel1(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a) : Play(j)
{
	enem = 0;
	emax = 10;
	for (unsigned int i = 0; i < 4; i++) {
		tren.emplace_back(new Vagon(ptsjuego, this, 580, 100 + 150 * i, v[i]));
	}
	arma = a;
}

void Nivel1::onClick() {
	balas.emplace_back(new Bala(ptsjuego, this, Game::TRoca, player->getPos().x, player->getPos().y, player->getMira(), arma));
}
void Nivel1::update(Uint32 delta) {
	if (enem < emax){
		//generar zombies aleatorios
		aleatorio = rand() % 10000;
		if (aleatorio >= 9988) {
			izq = rand() % 2;
			if (izq == 0) enems.emplace_back
				(new Enemigo(ptsjuego, this, 0, (rand() % 550) -100, Game::Enemigo_t::Normal));
			else enems.emplace_back
				(new Enemigo(ptsjuego, this,  1300, (rand() % 550) - 100, Game::Enemigo_t::Normal));
			enem++;
		}
	}
	else if (emax == Play::getKilled()){
		Play::finish();
	}


	Play::update(delta);

}