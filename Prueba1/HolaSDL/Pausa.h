#pragma once
#include "EstadoPG.h"
#include "Boton.h"

class Pausa: public  EstadoPG
{
public:
	Pausa(JuegoPG * juego);
	~Pausa();

private:
	static void resume(JuegoPG * jg);
	static void menu(JuegoPG * jg);
};

