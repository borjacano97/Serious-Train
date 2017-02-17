#pragma once
#include "EstadoPG.h"
#include "Boton.h"


class GameOver: public EstadoPG
{
public:
	GameOver(JuegoPG * juego);
	~GameOver();

	

private:
	static void score(JuegoPG * jg);
	static void menu(JuegoPG * jg);
};
