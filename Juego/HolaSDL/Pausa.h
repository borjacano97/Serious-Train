#ifndef H_PAUSA_H
#define H_PAUSA_H

#include "Estado.h"

class Pausa :
	public Estado
{
public:
	Pausa(Game* juego);
	~Pausa();
	void onClick();
	void draw();
	void update(Uint32 delta);
	static void salir(Game * jg);
	static void reanudar(Game * jg);
	char getEst(){  return 'S'; }

	
};


#endif
