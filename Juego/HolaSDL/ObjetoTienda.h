#ifndef H_OBJETOTIENDA_H
#define H_OBJETOTIENDA_H

#include "Objeto.h"

class Tienda;

class ObjetoTienda :
	public Objeto
{
public:
	ObjetoTienda(Game* juego, Tienda*ti, Game::Texturas_t bloq, Game::Texturas_t desblo, float x, float y, int p, Game::Vagon_t tipo);
	~ObjetoTienda(){}
	bool onClick();
	void desbloquear() { bloqueado = false; Ttextura = desb;}
	bool getBloq() { return bloqueado; }
	int getPrecio() { return precio; }
	void rehacer() { usado = false; }
private: 
	bool bloqueado = true;
	bool usado = false;
	Tienda*t;

	int mpbx, mpby, precio; // pos raton

	Game::Texturas_t desb;
	Game::Vagon_t tip;
};

#endif