#include "ObjetoTienda.h"



ObjetoTienda::ObjetoTienda(Game* juego, Game::Texturas_t bloq, Game::Texturas_t desbl, float x, float y, int p)
{
	juegootp = juego;
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
		bloqueado = false; 
		Ttextura = desb;
		return true;
	}
	else return false;
}