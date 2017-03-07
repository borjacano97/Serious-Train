#pragma once
#include "Game.h" 

class Estado: public RaizEstado
{
public:
	Estado(Game * j);
	~Estado();

	void draw(){ ; }
	void update(){ ; }
	void onClick(){ ; }
	void move(char c){ ; }

protected:

	Game* ptsjuego;

	std::vector <RaizObjeto*> objetos; // objetos que contiene cada estado
	

};

