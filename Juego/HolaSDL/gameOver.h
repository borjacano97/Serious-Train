#pragma once
#include "Estado.h"

class gameOver :
	public Estado
{
public:
	gameOver(Game* juego);
	~gameOver();
	void onClick();
	static void salir(Game * jg);
	static void jugar(Game * jg);
};

