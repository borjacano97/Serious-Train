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
	char getEst(){ if (victory) return 'W'; else return 'L'; }
private:
	static void salir(Game * jg);
	static void jugar(Game * jg);
	bool initLibraries();
	bool victory;
	Sound* sound;
};


#endif