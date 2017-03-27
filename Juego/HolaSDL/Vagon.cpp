#include "Vagon.h"
#include <string>



Vagon::Vagon(Game* juego, Game::Texturas_t text, int x, int y, std::string t)
{
	juegootp = juego;
	Ttextura = text;

	alto = 130;
	ancho = 1200;

	pimgx = x;
	pimgy = y;

	tipo = t;
}

void Vagon::update(Uint32 delta) {
	//hacer uso de la variable TIPO
}