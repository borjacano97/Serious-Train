#pragma once
#include "estado.h"
#include "personaje.h"

class play: public estado
{
public:
	play(game * j);
	~play();

	void onClick();
	void update();
	void move(char c);
private:
	bool initObjects(); //crear y destruir los objetos del juego
	void freeObjects();

};

