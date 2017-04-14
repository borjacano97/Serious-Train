#include "Nivel1.h"
#include "Enemigo.h"


Nivel1::Nivel1(Game * j/*, std::vector <Game::Vagon_t> v*/) : Play(j)
{
	enem = 0;
	emax = 30;
	tren.emplace_back(new Vagon(ptsjuego, this, Game::TLocomotora, 580, -50, Game::Vagon_t::Locom));
	for (unsigned int i = 0; i < 4; i++) {
		tren.emplace_back(new Vagon(ptsjuego, this, Game::TVagon1, 580, 100 +150*i, Game::Vagon_t::Vacio));
	}	
}


Nivel1::~Nivel1()
{
}
void Nivel1::update(Uint32 delta) {
	
	if (enem < emax){
		aleatorio = rand() % 10000; //generar zombies aleatorios
		if (aleatorio >= 9970) {
			izq = rand() % 2;
			if (izq == 0) enems.emplace_back
			(new Enemigo(ptsjuego, Game::TEnemigo2, 0, (rand() % 550) +100, Game::Enemigo_t::Normal));
			else enems.emplace_back
			(new Enemigo(ptsjuego, Game::TEnemigo2,1300, (rand() % 550) +100, Game::Enemigo_t::Normal));
			enem++;
		}	
	}
	else if (emax == Play::getKilled()){
		Play::finish();
	}
	
	
	Play::update(delta);
	
}