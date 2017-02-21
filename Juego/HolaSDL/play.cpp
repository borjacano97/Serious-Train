#include "play.h"
#include "estado.h"


play::play(Juego * j) : estado(j)
{
	initObjects();
}


play::~play()
{
	
}

bool play::initObjects() { // creación de los objetos dando un puntero, una textura y una posición

	/*objetos.emplace_back(new Personaje(ptsjuego, Juego::TPersonaje, 350, 350));	
	objetos.emplace_back(new Enemigo(ptsjuego, Juego::TEnemigo, rand() % 700, 0));
	objetos.emplace_back(new Tren(ptsjuego, Juego::TTren, 350, 350));*/

	return true;
}

void play::freeObjects() {
}

void play::update() {

	estado::update();
}