#include "Selector.h"



Selector::Selector(Game* juego, Game::Texturas_t text, float x, float y)
{
	juegootp = juego;

	alto = 200;
	ancho = 100;

	pos.set(x, y);
}

