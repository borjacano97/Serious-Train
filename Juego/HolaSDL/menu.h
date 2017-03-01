#pragma once
#include "estado.h"
class menu :
	public estado
{
public:
	menu(game* juego);
	~menu();
	void onClick();
	static void salir(game * jg);
	static void jugar(game * jg);
};

