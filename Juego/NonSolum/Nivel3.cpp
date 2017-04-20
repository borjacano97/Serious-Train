#include "Nivel3.h"
#include "enemigo.h"



Nivel3::Nivel3(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a) : Play(j)
{
	enem = 0;
	emax = 20;
	for (unsigned int i = 0; i < 4; i++) {
		tren.emplace_back(new Vagon(ptsjuego, this, 580, 100 + 150 * i, v[i]));
	}
	arma = a;
}
void Nivel3::onClick() {
	balas.emplace_back(new Bala(ptsjuego, this, Game::TRoca, player->getPos().x, player->getPos().y, player->getMira(), arma));
}
void Nivel3::update(Uint32 delta) {

	if (enem < emax){
		aleatorio = rand() % 10000; //generar zombies aleatorios
		if (aleatorio >= 9990) {
			izq = rand() % 2;
			if (izq == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) - 50, Game::Enemigo_t::Normal));
			else enems.emplace_back(new Enemigo(ptsjuego, this,  1300, (rand() % 550) - 50, Game::Enemigo_t::Normal));
			enem++;
		}
		else if (aleatorio >= 9985) {
			izq = rand() % 2;
			if (izq == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 50, Game::Enemigo_t::Rapido));
			else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 50, Game::Enemigo_t::Rapido));
			enem++;
		}
	}
	else if (emax == Play::getKilled()){
		Play::finish();
	}
	Play::update(delta);		
}
