#pragma once
#include "Estado.h"
class Menu :
	public Estado
{
public:
	Menu(Game* juego);
	~Menu();
	void onClick();
	static void salir(Game * jg);
	static void jugar(Game * jg);
};

