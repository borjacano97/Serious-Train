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
	Estado_t getEst(){ if (victory) return Win; else return Lose; }
private:
	static void salir(Game * jg);
	static void jugar(Game * jg);
	bool initLibraries();
	bool victory;
	Sound* sound;
};


#endif