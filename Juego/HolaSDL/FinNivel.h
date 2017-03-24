#ifndef H_FINNIVEL_H
#define H_FINNIVEL_H

#include "Estado.h"

class FinNivel :
	public Estado
{
public:
	FinNivel(Game* juego, bool v);
	~FinNivel();
	void onClick();
	void draw();
	void update(Uint32 delta);
	static void salir(Game * jg);
	static void jugar(Game * jg);
	char getEst(){ if (victory) return 'W'; else return 'L'; }
	
private: 
	bool victory;
};


#endif