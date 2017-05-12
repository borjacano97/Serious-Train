#include "Escenario.h"


Escenario::Escenario(Game* juego, Game::Texturas_t text, float x, float y)
{
	juegootp = juego;

	alto = 5000;
	ancho = 1280;

	Ttextura = text;
	pos.set(x, y);
}
void Escenario::update(Uint32 delta){
	if (pos.y >= 0) pos.y = -4280;
	else  pos.y += delta * 0.2;
}


