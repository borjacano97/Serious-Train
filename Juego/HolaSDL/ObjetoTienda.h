#ifndef H_OBJETOTIENDA_H
#define H_OBJETOTIENDA_H

#include "Objeto.h"

class Tienda;

class ObjetoTienda :
	public Objeto
{
public:
	ObjetoTienda(Game* juego, Tienda*ti, float x, float y, int p, Game::Vagon_t tipo, bool est);
	~ObjetoTienda() {}
	bool onClick();
	void desbloquear() { bloqueado = false; Ttextura = desb; }
	bool getBloq() { return bloqueado; }
	int getPrecio() { return precio; }
	void rehacer() { usado = false; }
	void draw();
private:
	bool bloqueado = true;
	bool usado = false;
	bool estatico;
	Tienda*t;
	Texturas* puntosText;
	Texturas* tipoText;
	SDL_Color tipoTextColor;
	SDL_Color fontColor;

	int mpbx, mpby, precio; // pos raton
	std::string tipoVagon;

	Game::Texturas_t desb;
	Game::Vagon_t tip;
};

#endif