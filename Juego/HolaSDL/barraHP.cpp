#include "BarraHP.h"



barraHP::barraHP(Game* juego, Game::Texturas_t text, int x, int y, int extraHP)
{
	juegootp = juego;
	Ttextura = text;

	alto = 50;
	ancho = 200 + extraHP;

	pimgx = x;
	pimgy = y;

	cont = 0;
}


void barraHP::update(Uint32 delta) {
	if (ancho <= 0) destruido = true;
}
void barraHP::move(char c) {
	cont++;
	if (cont >= 50) {
		cont = 0;
		ancho--;
	}	
}
