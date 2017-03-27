#include "Bala.h"


Bala::Bala(Game* juego, Game::Texturas_t text, int x, int y, int mira)
{
	juegootp = juego;
	Ttextura = text;

	alto = 20;  // "Esto para probar, luego..."
	ancho = 20;

	pimgx = x;
	pimgy = y;
	
	dir = mira;
}


void Bala::update(Uint32 delta) {
	pimgx += dir * vel*delta;
	
	if (pimgx <= 0 || pimgx >= juegootp->dm.w)
		destruido = true;
}