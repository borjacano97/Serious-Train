#include "Vagon.h"
#include <string>



Vagon::Vagon(Game* juego, Game::Texturas_t text, float x, float y, Game::Vagon_t t)
{
	juegootp = juego;
	Ttextura = text;

	alto = 151;
	ancho = 120;

	pos.set(x, y);

	tipo = t;
	
	disparo = false;
}

void Vagon::update(Uint32 delta) {
	switch (tipo)
	{
	case Game::VAutomatico:
		cont += delta;
		if (cont >= 1500) {
			disparo = true;
			cont = 0;
		}
		break;
	case Game::VLaser:
		cont += delta;
		if (cont >= 3000) {
			disparo = true;
			cont = 0;
		}
		break;
	default:
		break;
	}
}