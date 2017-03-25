#include "Nivel2.h"
#include "enemigo.h"



Nivel2::Nivel2(Game * j) : Play(j)
{
	enem = 0;
	emax = 10;
}


Nivel2::~Nivel2()
{
}
void Nivel2::update(Uint32 delta) {

	if (enem < emax){
		aleatorio = rand() % 10000; //generar zombies aleatorios
		if (aleatorio >= 9980) {
			izq = rand() % 2;
			if (izq == 0) objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo2, 0, (ptsjuego->dm.h - 150) + 50, Game::Enemigo_t::ENormal));
			else objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo2, ptsjuego->dm.w, (ptsjuego->dm.h - 150) + 50, Game::Enemigo_t::ENormal));
			enem++;
		}
		else if (aleatorio >= 9975) {
			izq = rand() % 2;
			if (izq == 0) objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo, 0, (ptsjuego->dm.h - 150) + 50, Game::Enemigo_t::ERapido));
			else objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo, ptsjuego->dm.w, (ptsjuego->dm.h - 150) + 50, Game::Enemigo_t::ERapido));
			enem++;
		}
	}
	else if (emax == Play::getKilled()){
		Play::finish();
	}
	Play::update(delta);		
}
