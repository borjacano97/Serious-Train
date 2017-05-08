#include "Tick.h"


Tick::Tick(Game* juego, float x, float y)
{
	juegootp = juego;
	pos.set(x, y);
	Ttextura = Game::Texturas_t::TTick;

	alto = 130;
	ancho = 95;
}

