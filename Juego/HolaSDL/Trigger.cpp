#include "Trigger.h"


Trigger::Trigger(Game* juego, Game::Texturas_t text, int x, int y)
{
	juegootp = juego;
	Ttextura = text;

	alto = 200;  
	ancho = 200;

	pimgx = x;
	pimgy = y;
}


void Trigger::update(Uint32 delta){
	//en principio nada aqui 
}