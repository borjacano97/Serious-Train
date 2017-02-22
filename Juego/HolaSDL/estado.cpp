#include "estado.h"
#include "play.h"

estado::estado(Juego * j)
{
	ptsjuego = j;
}


estado::~estado()
{
}

void estado::draw() {
	for (int i = 0; i < objetos.size(); i++) {
		objetos[i]->draw();
	}
}


void estado::onClick() {
	bool clickeado = false; 

	int i = objetos.size() - 1;
	while (!clickeado && i >= 0)
	{
		if (objetos[i]->onClick())
			clickeado = true;

		i--;
	}

}


void estado::update() {
	for (int i = 0; i < objetos.size(); i++) {
		objetos[i]->update();
	}
}

