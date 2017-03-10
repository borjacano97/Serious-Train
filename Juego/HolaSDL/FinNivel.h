#pragma once
#include "Estado.h"

class FinNivel :
	public Estado
{
public:
	FinNivel(Game* juego, bool v);
	~FinNivel();
	void onClick();
	void draw();
	static void salir(Game * jg);
	static void jugar(Game * jg);
	char getEst(){ if (victory) return 'W'; else return 'L'; }

private: 
	bool victory;

};

