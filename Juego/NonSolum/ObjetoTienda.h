#ifndef H_OBJETOTIENDA_H
#define H_OBJETOTIENDA_H

#include "Objeto.h"

class Tienda;

class ObjetoTienda :
	public Objeto
{
public:
	ObjetoTienda();
	~ObjetoTienda() {}
	void desbloquear() { bloqueado = false; Ttextura = desb; }
	bool getBloq() { return bloqueado; }
	int getPrecio() { return precio; }
	void rehacer() { usado = false; }

protected:
	bool bloqueado = true;
	bool usado = false;
	bool estatico;

	Tienda*t;
	Texturas* puntosText;
	Texturas* tipoText;
	SDL_Color tipoTextColor;
	SDL_Color fontColor;

	int mpbx, mpby, precio; // pos raton

	Game::Texturas_t desb;
};

#endif