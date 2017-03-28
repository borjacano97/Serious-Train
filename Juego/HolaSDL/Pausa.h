#ifndef H_PAUSA_H
#define H_PAUSA_H

#include "Estado.h"

class Pausa :
	public Estado
{
public:
	Pausa(Game* juego);
	~Pausa(){}
	void update(Uint32 delta);
	char getEst(){  return 'S'; }	

	static void salir(Game * jg);
	static void reanudar(Game * jg);
};


#endif
