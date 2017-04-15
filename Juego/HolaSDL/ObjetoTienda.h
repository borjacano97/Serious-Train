#ifndef H_OBJETOTIENDA_H
#define H_OBJETOTIENDA_H

#include "Objeto.h"

class Tienda;

class ObjetoTienda :
	public Objeto
{
public:
	ObjetoTienda(Game* juego, Tienda*ti, Game::Texturas_t bloq, Game::Texturas_t desblo, float x, float y, int p);
	~ObjetoTienda(){}
	bool onClick();
	void desbloquear() { bloqueado = false; Ttextura = desb;}
	int getPrecio() { return precio; }
private: 
	bool bloqueado = true;
	Tienda*t;
	int mpbx, mpby, precio; // pos raton
	Game::Texturas_t desb;
};

#endif