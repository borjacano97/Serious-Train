#pragma once
#include "estado.h"
#include "personaje.h"
#include "tren.h"
#include "barraHP.h"

class play: public estado
{
public:
	play(game * j);
	~play();

	void onClick();
	void update();
	void move(char c);
private:
	int izq;
	int aleatorio;
	Personaje* player;
	Tren* train;
	barraHP* TrainHp;

	bool initObjects(); //crear y destruir los objetos del juego
	void freeObjects();

};

