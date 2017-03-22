#pragma once
#include "Estado.h"

class GameOver :
	public Estado
{
public:
	GameOver(Game* juego);
	~GameOver();
	void onClick();
	void draw();
	static void salir(Game * jg);
	static void jugar(Game * jg);

};

