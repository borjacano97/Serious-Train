#include "ObjetoTienda.h"
#include "Tienda.h"

ObjetoTienda::ObjetoTienda(Game* juego, Tienda* ti, float x, float y, int p, Game::Vagon_t tipo, bool est)
{
	juegootp = juego;
	t = ti;
	
	Ttextura = Game::Texturas_t::TVacioBloq;

	alto = 130;
	ancho = 95;
	precio = p;

	pos.set(x, y);

	tip = tipo;

	estatico = est;
	switch (tipo)
	{	
	case Game::Automatico: desb = Game::Texturas_t::TVagonAuto;
		break;
	case Game::Laser: desb = Game::Texturas_t::TVagon1;
		break;
	case Game::Lanzallamas: desb = Game::Texturas_t::TVagon1;
		break;
	default:
		break;
	}
	if (estatico) Ttextura = desb;
}
bool ObjetoTienda::onClick() {
		juegootp->getMousePos(mpbx, mpby);

		if (dentro(mpbx, mpby)) {
			if (!bloqueado && !usado) {
				// aqui hay que llamar a un método de tienda para que se coloque el vagón en el tren
				usado = true;
				t->colocarVagon(tip);
			}
			return true;
		}
	
	else return false;	
}