#include "Nivel1.h"
#include "Enemigo.h"


Nivel1::Nivel1(Game * j) : Play(j)
{
	enem = 0;
	emax = 5;
}


Nivel1::~Nivel1()
{
}
void Nivel1::update() {
	aleatorio = rand() % 10000; //generar zombies aleatorios
	if (enem < emax && aleatorio >= 9980) {
		izq = rand() % 2;
		if (izq == 0) objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo2, 0, rand() % 500 + 50, false));
		else objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo2, 1300, rand() % 500 + 50, false));
		enem++;
		
	}
	
    Play::update();
	
}