#pragma once
#include "EstadoPG.h"
#include "Boton.h"

class MenuPG : public EstadoPG
{
public:
	MenuPG(JuegoPG * juego);
	~MenuPG();

	

private:
	static void salir(JuegoPG * jg);
	static void play(JuegoPG * jg);
	

};

