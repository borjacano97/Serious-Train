#ifndef H_ESTADO_H
#define H_ESTADO_H

#include "Game.h" 

class Estado: public RaizEstado
{
public:
	Estado(Game * j);
	~Estado();

	void draw(){}
	void update(){}
	void onClick(){}
	void move(char c){}
	// Estos m�todos solo se pueden quitar si TODOS los miembros que heredan de esto tienen
	// implementados dicho m�todo. Si hay alg�n estado que por ejemplo no necesita un onClick
	// lo coge directamente de esta clase, y por ello el cuerpo est� vac�o o tiene un cuerpo propio a 
	// todas las subclases
protected:

	Game* ptsjuego;
	std::vector <RaizObjeto*> objetos; // objetos que contiene cada estado	
};


#endif