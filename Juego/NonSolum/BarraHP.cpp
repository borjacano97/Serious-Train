#include "BarraHP.h"



barraHP::barraHP(Game* juego, Game::Texturas_t text, float x, float y)
{
	juegootp = juego;
	Ttextura = text;

	alto = 50;
	ancho = 200 ;

	pos.set(x, y);

	cont = 0;
}


void barraHP::update(Uint32 delta) {
	if (ancho <= 0) destruido = true;
}
void barraHP::move(char c) {
	if (c == 'b'){ //daño por bala
		ancho -= 10;
	}
	if (c == 'z'){ // daño por zombie
		cont++;
		if (cont >= 50) {
			cont = 0;
			ancho--;
		}
	}
}
