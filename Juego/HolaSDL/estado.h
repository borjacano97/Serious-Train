#pragma once
#include "game.h" 

class estado: public raizEstado
{
public:
	estado(game * j);
	~estado();

	void draw();
	void update();

protected:

	game* ptsjuego;

	std::vector <raizObjeto*> objetos; // objetos que contiene cada estado
	std::vector <raizObjeto*> balas; 

};

