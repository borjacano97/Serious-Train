#include "estado.h"
#include "play.h"

Estado::Estado(Game * j)
{
	ptsjuego = j;
}


Estado::~Estado()
{
}

void Estado::draw() {
	for (unsigned int i = 0; i < objetos.size(); i++) {
		if (objetos[i] != nullptr)
		    objetos[i]->draw();
	}	
	for (unsigned int i = 0; i < balas.size(); i++) {
		if (balas[i] != nullptr)
			balas[i]->draw();
	}
}





void Estado::update() {
	for (unsigned int i = 0; i < objetos.size(); i++) {
		if (objetos[i] != nullptr)
		    objetos[i]->update();
	}
	for (unsigned int i = 0; i < balas.size(); i++) {
		if (balas[i] != nullptr)
			balas[i]->update();
	}
}

