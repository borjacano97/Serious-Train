#include "Estado.h"
#include "Play.h"

Estado::Estado(Game * j) :ptsjuego(j){};


Estado::~Estado()
{
}
void Estado::draw() {
	for (auto i : objetos) {
		if (i != nullptr) {
			i->draw();
		}
	}
}

void Estado::onClick() {
	bool clickeado = false;

	int i = objetos.size() - 1;
	while (!clickeado && i >= 0)
	{
		if (objetos[i]->onClick())
			clickeado = true;
		i--;
	}
}
