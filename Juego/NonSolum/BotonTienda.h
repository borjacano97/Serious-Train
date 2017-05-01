#ifndef H_BOTONTIENDA_H
#define H_BOTONTIENDA_H

#include "Objeto.h"
#include "ObjetoTienda.h"

class Tienda;

class BotonTienda :
	public Objeto
{
public:
	BotonTienda(Game* juego, Tienda*ti, ObjetoTienda*obj, Game::Texturas_t t, float x, float y, Game::Boton_t tipo);
	~BotonTienda(){}
	bool onClick();
	void draw();
private:
	Tienda*t;
	ObjetoTienda*o;

	int mpbx, mpby;
	Game::Boton_t tip;

	Texturas* texto;
	SDL_Color fontColor;
	std::string textB;
};

#endif