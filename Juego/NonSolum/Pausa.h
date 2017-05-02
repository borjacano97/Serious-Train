#ifndef H_PAUSA_H
#define H_PAUSA_H

#include "Estado.h"
#include "Sound.h"
#include "Controles.h"

class Pausa :
	public Estado
{
public:
	Pausa(Game* juego);
	~Pausa(){}
	char getEst(){  return 'S'; }	
private:
	static void salir(Game * jg);
	static void reanudar(Game * jg);
	static void control(Game * jg) { jg->pushState(new Controles(jg)); }
	bool initLibraries();
};


#endif
