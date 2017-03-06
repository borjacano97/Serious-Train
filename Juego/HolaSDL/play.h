#pragma once
#include "Estado.h"
#include "Personaje.h"
#include "Tren.h"
#include "BarraHP.h"

class Play: public Estado
{
public:
	Play(Game * j);
	~Play();

	void onClick();
	void update();
	void move(char c);
private:
	int izq;
	int aleatorio;
	Personaje* player;
	Tren* train;
	barraHP* TrainHp;

	bool dest;
	bool initObjects(); //crear y destruir los objetos del juego
	void freeObjects();

};

