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
void Nivel2::update() {
	
		aleatorio = rand() % 10000; //generar zombies aleatorios
	if (enem < emax && aleatorio >= 9980) {
		izq = rand() % 2;
		if (izq == 0) objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo2, 0, rand() % 500 + 50, false));
		else objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo2, 1300, rand() % 500 + 50, false));
		enem++;
		
	}
	else if (enem < emax && aleatorio >= 9975) {
		izq = rand() % 2;
		if (izq == 0) objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo, 0, rand() % 500 + 50, true));
		else objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo, 1300, rand() % 500 + 50, true));
		enem++;
		
	}
	Play::update();		
}