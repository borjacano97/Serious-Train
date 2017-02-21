#pragma once
#include "estado.h"

class play: public estado
{
public:
	play(Juego * j);
	~play();

	void update();

private:
	bool initObjects(); //crear y destruir los objetos del juego
	void freeObjects();
};

