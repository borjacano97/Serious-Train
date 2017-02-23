#include "estado.h"
#include "play.h"

estado::estado(game * j)
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





void estado::update() {
	for (int i = 0; i < objetos.size(); i++) {
		objetos[i]->update();
	}
}

