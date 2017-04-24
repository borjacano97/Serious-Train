#include "Trigger.h"


Trigger::Trigger(Game* juego, float x, float y)
{
	juegootp = juego;

	alto = 2000;  
	ancho = 170;

	pos.set(x, y);
}
