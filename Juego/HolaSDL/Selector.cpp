#include "Selector.h"



Selector::Selector(Game* juego, Game::Texturas_t text, float x, float y)
{
	juegootp = juego;

	Ttextura = text;

	alto = 130;
	ancho = 110;

	pos.set(x, y);
}
void Selector::update(Uint32 n) {
	pos.set(pos.x, pos.y*n);
}