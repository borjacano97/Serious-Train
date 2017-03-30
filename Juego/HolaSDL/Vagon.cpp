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
	if (tipo == Game::Vagon_t::VAutomatico) {
		cont += delta;
		if (cont >= 1500) {
			disparo = true;
			cont = 0;
		}
	}	
}