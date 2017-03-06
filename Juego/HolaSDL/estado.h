#pragma once
#include "Game.h" 

class Estado: public raizEstado
{
public:
	Estado(Game * j);
	~Estado();

	void draw();
	void update();
	void onClick(){ ; }
	void move(char c){ ; }

protected:

	Game* ptsjuego;

	std::vector <raizObjeto*> objetos; // objetos que contiene cada estado
	std::vector <raizObjeto*> balas; 

};

