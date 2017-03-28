#ifndef H_PLAY_H
#define H_PLAY_H

#include "Estado.h"
#include "Personaje.h"
#include "Vagon.h"
#include "BarraHP.h"
#include "Trigger.h"


class Play: public Estado
{
public:
	Play(Game * j);
	~Play();

	void onClick();
	void draw();
	void update(Uint32 delta);
	void move(char c);
	char getEst(){ return 'P'; }
	int getKilled(){ return killed; }
	void finish() { fin = true; }

private:
	Personaje* player;
	barraHP* TrainHp;
	Trigger* tg;

	unsigned int vag = 5;
	bool fin;
	bool initObjects(); //crear y destruir los objetos del juego
	void freeObjects();

	std::vector <RaizObjeto*> balas; // TODO mirad estándares de código
	std::vector <RaizObjeto*> tren; // TODO mirad estándares de código

	int emax, enem;
	int killed;
	Uint32 cont;
};


#endif