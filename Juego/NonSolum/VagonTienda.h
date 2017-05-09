#ifndef H_VAGONTIENDA_H
#define H_VAGONTIENDA_H

#include "ObjetoTienda.h"
#include "Hud.h"

class VagonTienda :
	public ObjetoTienda
{
public:
	VagonTienda(Game* juego, Tienda*ti, float x, float y, int p, Game::Vagon_t tipo, bool est);
	~VagonTienda(){}
	bool onClick();
	void draw();
private:
	Game::Vagon_t tip;
	std::string tipoVagon;

	Hud* tic;
};

#endif