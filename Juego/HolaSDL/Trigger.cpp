#include "Trigger.h"


Trigger::Trigger(Game* juego, float x, float y)
{
	juegootp = juego;

	alto = 2000;  
	ancho = 100;

	pos.set(x, y);
}
