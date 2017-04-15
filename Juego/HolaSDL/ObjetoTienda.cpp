#include "ObjetoTienda.h"


ObjetoTienda::ObjetoTienda(Game* juego, Tienda* ti, Game::Texturas_t bloq, Game::Texturas_t desbl, float x, float y, int p)
{
	juegootp = juego;
	t = ti;

	Ttextura = bloq;
	desb = desbl;

	alto = 151;
	ancho = 120;
	precio = p;

	pos.set(x, y);
}
bool ObjetoTienda::onClick() {
	juegootp->getMousePos(mpbx, mpby);

	if (dentro(mpbx, mpby)) {
		if (!bloqueado); // aqui hay que llamar a un método de tienda para que se coloque el vagón en el tren
		return true;
	}
	else return false;
}