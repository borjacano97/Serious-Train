#include "BotonTienda.h"
#include "Tienda.h"


BotonTienda::BotonTienda(Game* juego, Tienda*ti, ObjetoTienda*obj, Game::Texturas_t text, float x, float y, Game::Boton_t tipo)
{
	juegootp = juego;
	t = ti;
	o = obj;
	
	Ttextura = text;

	alto = 70;
	ancho = 170;

	pos.set(x, y);
	tip = tipo;
}

bool BotonTienda::onClick() {
	juegootp->getMousePos(mpbx, mpby);

	if (dentro(mpbx, mpby)) {
		switch (tip)
		{
		case Game::Comprar:
			if (o->getBloq() && o->getPrecio() <= juegootp->coins) t->comprar(o);			
			break;
		case Game::Jugar:
			t->jugar(juegootp);
			break;
		case Game::Recolocar:
			t->recolocar(juegootp);
			break;
		default:
			break;
		}			
		return true;
	}
	else return false;
}
