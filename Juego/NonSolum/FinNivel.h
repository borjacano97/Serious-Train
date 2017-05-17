#ifndef H_FINNIVEL_H
#define H_FINNIVEL_H

#include "Estado.h"
#include "Sound.h"
class FinNivel :
	public Estado
{
public:
	FinNivel(Game* juego, bool v);
	~FinNivel() { sound->stopMusic(); }
	Estado_t getEst(){ if (victory) return Estado_t::Win_t; else return Estado_t::Lose_t; }
private:
	static void salir(Game * jg);
	static void jugar(Game * jg);
	bool initLibraries();
	bool handle_events(SDL_Event * e);
	bool victory;
	Sound* sound;
};


#endif