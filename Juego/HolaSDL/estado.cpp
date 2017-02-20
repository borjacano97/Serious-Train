#include "estado.h"


estado::estado(Juego * j)
{
	ptsjuego = j;
}


estado::~estado()
{
}

void raizEstado::draw() {
	for (int i = 0; i < objetos.size(); i++) { // da error porque aun no se ha añadido nada al vector
		objetos[i]->draw();
	}
}


void raizEstado::onClick() {
	bool clickeado = false; 

	int i = objetos.size() - 1;
	while (!clickeado && i >= 0)
	{
		if (objetos[i]->onClick())
			clickeado = true;

		i--;
	}

}


void raizEstado::update() {
	for (int i = 0; i < objetos.size(); i++) {
		objetos[i]->update();
	}
}