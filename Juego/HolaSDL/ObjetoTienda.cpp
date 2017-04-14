#include "ObjetoTienda.h"



ObjetoTienda::ObjetoTienda(Game* juego, Game::Texturas_t text, float x, float y, int p)
{
	juegootp = juego;
	//Ttextura = Game::Texturas_t::TBloqueado;
	desb = text;

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