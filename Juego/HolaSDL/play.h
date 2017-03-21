#pragma once
#include "Estado.h"
#include "Personaje.h"
#include "Vagon.h"
#include "BarraHP.h"

class Play: public Estado
{
public:
	Play(Game * j);
	~Play();

	void onClick();
	void draw();
	void update();
	void move(char c);
	char getEst(){ return 'P'; }
	int getKilled(){ return killed; }
	void finish() { fin = true; }

private:
	Personaje* player;
	barraHP* TrainHp;

	int vag = 5;
	bool fin;
	bool initObjects(); //crear y destruir los objetos del juego
	void freeObjects();

	std::vector <RaizObjeto*> balas; // TODO mirad est�ndares de c�digo
	std::vector <RaizObjeto*> tren; // TODO mirad est�ndares de c�digo

	int emax, enem;
	int killed;
};

