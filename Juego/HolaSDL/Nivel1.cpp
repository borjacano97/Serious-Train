#include "Nivel1.h"
#include "Enemigo.h"


Nivel1::Nivel1(Game * j) : Play(j)
{
	enem = 0;
	emax = 20;
}


Nivel1::~Nivel1()
{
}
void Nivel1::update(Uint32 delta) {
	
	if (enem < emax){
		aleatorio = rand() % 10000; //generar zombies aleatorios
		if (aleatorio >= 9990) {
			izq = rand() % 2;
			if (izq == 0) objetos.emplace_back
			(new Enemigo(ptsjuego, Game::TEnemigo2, 0, (rand() % 550) +100, Game::Enemigo_t::ENormal));
			else objetos.emplace_back
			(new Enemigo(ptsjuego, Game::TEnemigo2,1300, (rand() % 550) +100, Game::Enemigo_t::ENormal));
			enem++;
		}	
	}
	else if (emax == Play::getKilled()){
		Play::finish();
	}
	
	
	Play::update(delta);
	
}