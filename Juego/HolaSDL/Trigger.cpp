#include "Trigger.h"


Trigger::Trigger(Game* juego, int x, int y)
{
	juegootp = juego;

	alto = 2000;  
	ancho = 200;

	pimgx = x;
	pimgy = y;
}


void Trigger::update(Uint32 delta){
	//en principio nada aqui 
}