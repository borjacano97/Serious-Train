#pragma once
#include "Juego.h" 

class estado: public raizEstado
{
public:
	estado(Juego * j);
	~estado();

	void draw();
	void update();
	void onClick();

protected:

	Juego* ptsjuego;

	std::vector <raizObjeto*> objetos; // objetos que contiene cada estado
};

