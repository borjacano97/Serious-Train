#ifndef H_ARMATIENDA_H
#define H_ARMATIENDA_H

#include "ObjetoTienda.h"


class ArmaTienda :
	public ObjetoTienda
{
public:
	ArmaTienda(Game* juego, Tienda*ti, float x, float y, int p, Game::Bala_t tipo, bool est);
	~ArmaTienda() {}
	bool onClick();
	void draw();
private:
	Game::Bala_t tip;
	std::string tipoArma;
};
#endif