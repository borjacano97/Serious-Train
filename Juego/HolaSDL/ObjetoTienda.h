#ifndef H_OBJETOTIENDA_H
#define H_OBJETOTIENDA_H

#include "Objeto.h"

class ObjetoTienda :
	public Objeto
{
public:
	ObjetoTienda(Game* juego, Game::Texturas_t bloq, Game::Texturas_t desblo, float x, float y, int p);
	~ObjetoTienda(){}
	Objeto_t getId() { return Objeto_t::OObjetoTienda; }
	bool onClick();
	bool getBloqueo() { return bloqueado; }
	int getPrecio() { return precio; }
private: 
	bool bloqueado = true;
	int mpbx, mpby, precio; // pos raton
	Game::Texturas_t desb;
};

#endif