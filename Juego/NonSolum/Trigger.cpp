#include "Trigger.h"
#include "Tienda.h"


Trigger::Trigger(Game* juego, Tienda* ti, float x, float y)
{
	juegootp = juego;

	if (ti == NULL) {
		alto = 2000;
		ancho = 165;
	}
	else {
		t = ti;
		alto = 130;
		ancho = 95;
	}

	pos.set(x, y);
}
bool Trigger::onClick() {
	juegootp->getMousePos(mpbx, mpby);

	if (dentro(mpbx, mpby)) {
		  t->select((pos.y-170)/130 +1);
		return true;
	}

	else return false;
}