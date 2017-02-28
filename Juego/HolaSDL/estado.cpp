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
	for (unsigned int i = 0; i < objetos.size(); i++) {
		if (objetos[i] != nullptr)
		    objetos[i]->draw();
	}	
	for (unsigned int i = 0; i < balas.size(); i++) {
		if (balas[i] != nullptr)
			balas[i]->draw();
	}
}





void estado::update() {
	for (unsigned int i = 0; i < objetos.size(); i++) {
		if (objetos[i] != nullptr)
		    objetos[i]->update();
	}
	for (unsigned int i = 0; i < balas.size(); i++) {
		if (balas[i] != nullptr)
			balas[i]->update();
	}
}

