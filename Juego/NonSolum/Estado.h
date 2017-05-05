#ifndef H_ESTADO_H
#define H_ESTADO_H

#include "Game.h" 

class Estado: public RaizEstado
{
public:
	Estado(Game * j);
	~Estado();
	Estado_t getEstado() { return estado; }
	void draw();
	void onClick();
	void update(Uint32 d){}
	bool handle_events(SDL_Event * evento);
	// Estos métodos solo se pueden quitar si TODOS los miembros que heredan de esto tienen
	// implementados dicho método. Si hay algún estado que por ejemplo no necesita un onClick
	// lo coge directamente de esta clase, y por ello el cuerpo está vacío o tiene un cuerpo propio a 
	// todas las subclases
	std::vector <RaizObjeto*> objetos; // objetos que contiene cada estado	
protected:
	Estado_t estado;
	Game* ptsjuego;
};


#endif