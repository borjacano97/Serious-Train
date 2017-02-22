#pragma once
#include "estado.h"
#include "personaje.h"

class play: public estado
{
public:
	play(Juego * j);
	~play();

	void update();
	void move(char c);
private:
	bool initObjects(); //crear y destruir los objetos del juego
	void freeObjects();

};

