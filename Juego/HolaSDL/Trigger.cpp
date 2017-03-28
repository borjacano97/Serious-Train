#include "Trigger.h"


Trigger::Trigger(Game* juego, float x, float y)
{
	juegootp = juego;

	alto = 2000;  
	ancho = 200;

	pos.set(x, y);
}


void Trigger::update(Uint32 delta){
	//en principio nada aqui 
}