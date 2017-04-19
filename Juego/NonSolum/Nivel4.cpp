#include "Nivel4.h"
#include "Enemigo.h"


Nivel4::Nivel4(Game * j, std::vector <Game::Vagon_t> v) : Play(j)
{
	enem = 0;
	emax = 20;
	for (unsigned int i = 0; i < 4; i++) {
		tren.emplace_back(new Vagon(ptsjuego, this, 580, 100 + 150 * i, v[i]));
	}
}


Nivel4::~Nivel4()
{
}
void Nivel4::update(Uint32 delta) {
	if (enem < emax-1){
		aleatorio = rand() % 10000; //generar zombies aleatorios
		if (aleatorio >= 9992) {
			izq = rand() % 2;
			if (izq == 0) enems.emplace_back(new Enemigo(ptsjuego, this, Game::TEnemigo2, 0, (rand() % 550) - 50, Game::Enemigo_t::Normal));
			else enems.emplace_back(new Enemigo(ptsjuego, this, Game::TEnemigo2, 1300, (rand() % 550) - 50, Game::Enemigo_t::Normal));
			enem++;
		}
		else if (aleatorio >= 9985) {
			izq = rand() % 2;
			if (izq == 0) enems.emplace_back(new Enemigo(ptsjuego, this, Game::TEnemigo, 0, (rand() % 550) + 50, Game::Enemigo_t::Rapido));
			else enems.emplace_back(new Enemigo(ptsjuego, this, Game::TEnemigo, 1300, (rand() % 550) + 50, Game::Enemigo_t::Rapido));
			enem++;
		}
	}
	else {
		if (!created){
			enems.emplace_back
				(new Enemigo(ptsjuego, this, Game::TEnemigo2, 0, (rand() % 550) - 50, Game::Enemigo_t::Tank));
			created = true;
		}

	}
	if (emax == Play::getKilled()){
		Play::finish();
	}


	Play::update(delta);

}