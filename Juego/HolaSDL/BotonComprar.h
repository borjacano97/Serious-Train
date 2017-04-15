#ifndef H_BOTONCOMPRAR_H
#define H_BOTONCOMPRAR_H

#include "Objeto.h"
#include "ObjetoTienda.h"

class Tienda;

class BotonComprar :
	public Objeto
{
public:
	BotonComprar(Game* juego, Tienda*ti, ObjetoTienda*obj, Game::Texturas_t t, float x, float y);
	~BotonComprar(){}
	bool onClick();
private:
	Tienda*t;
	ObjetoTienda*o;
	int mpbx, mpby;
};

#endif