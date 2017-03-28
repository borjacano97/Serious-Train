#include "Bala.h"


Bala::Bala(Game* juego, Game::Texturas_t text, float x, float y, int mira)
{
	juegootp = juego;
	Ttextura = text;

	alto = 20;  // "Esto para probar, luego..."
	ancho = 20;

	pos.set(x, y);
	
	vel = 0.5;
	dir = mira;
}


void Bala::update(Uint32 delta) {
	pos.x += dir * vel*delta;
	
	if (pos.x <= 0 || pos.x >= juegootp->dm.w)
		destruido = true;
}