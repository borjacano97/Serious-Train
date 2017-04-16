#ifndef H_ESTADO_H
#define H_ESTADO_H

#include "Game.h" 

class Estado: public RaizEstado
{
public:
	Estado(Game * j);
	~Estado();

	void draw();
	void onClick();
	void update(Uint32 d){}
	void move(char c){}
	void select(Uint32 n){}
	// Estos métodos solo se pueden quitar si TODOS los miembros que heredan de esto tienen
	// implementados dicho método. Si hay algún estado que por ejemplo no necesita un onClick
	// lo coge directamente de esta clase, y por ello el cuerpo está vacío o tiene un cuerpo propio a 
	// todas las subclases
	std::vector <RaizObjeto*> objetos; // objetos que contiene cada estado	
protected:

	Game* ptsjuego;
	
};


#endif