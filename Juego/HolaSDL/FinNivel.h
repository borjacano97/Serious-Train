#pragma once
#include "Estado.h"

class FinNivel :
	public Estado
{
public:
	FinNivel(Game* juego, bool v, int n);
	~FinNivel();
	void onClick();
	void draw();
	static void salir(Game * jg);
	static void jugar(Game * jg);
	char getEst(){ if (victory) return 'W'; else return 'L'; }
	
private: 

	static int nivel;
	bool victory;
};

