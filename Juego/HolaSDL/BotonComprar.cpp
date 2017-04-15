#include "BotonComprar.h"
#include "Tienda.h"


BotonComprar::BotonComprar(Game* juego, Tienda*ti, ObjetoTienda*obj, Game::Texturas_t text, float x, float y)
{
	juegootp = juego;
	t = ti;
	o = obj;
	
	Ttextura = text;

	alto = 70;
	ancho = 170;

	pos.set(x, y);
}

bool BotonComprar::onClick() {
	juegootp->getMousePos(mpbx, mpby);

	if (dentro(mpbx, mpby)) {
		if (o->getBloq() && o->getPrecio() <= juegootp->coins) {
			t->comprar(o);
		}
			
		return true;
	}
	else return false;
}
