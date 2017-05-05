#ifndef H_RAIZESTADO_H
#define H_RAIZESTADO_H
#include "Game.h"
enum class Estado_t { Pausa_t, Menu_t, Play_t, Tienda_t, Win_t, Lose_t, Controles_t };
class RaizEstado
{
public:
	
	RaizEstado()
	{
	}

	virtual ~RaizEstado()
	{
	}

	virtual void draw() = 0;
	virtual void update(Uint32 delta) = 0;
	virtual void onClick() = 0;
	virtual Estado_t getEstado() = 0;
	virtual bool handle_events(SDL_Event * evento) = 0;
};


#endif