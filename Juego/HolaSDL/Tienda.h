#ifndef H_TIENDA_H
#define H_TIENDA_H

#include "estado.h"
class Tienda :
	public Estado
{
public:
	Tienda(Game* juego);
	~Tienda(){}
	char getEst(){  return 'T';}
private:
	static void recolocar(Game * jg);
	static void jugar(Game * jg);
	std::vector <Game::Vagon_t> vagonesNivel; // va a contener los tipos de vagones que pasarán a cada nvl
};

#endif