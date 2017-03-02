#pragma once
#include "estado.h"
class Menu :
	public estado
{
public:
	Menu(game* juego);
	~Menu();
	void onClick();
	static void salir(game * jg);
	static void jugar(game * jg);
};

