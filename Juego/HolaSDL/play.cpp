#include "play.h"
#include "estado.h"
#include "personaje.h"


play::play(Juego * j) : estado(j)
{
	initObjects();
}


play::~play()
{
	
}

bool play::initObjects() { // creación de los objetos dando un puntero, una textura y una posición (constructora de objs)

	objetos.emplace_back(new personaje(ptsjuego, Juego::TPersonaje, 650, 350));
	//objetos.emplace_back(new Enemigo(ptsjuego, Juego::TEnemigo, rand() % 700, 0));
	//objetos.emplace_back(new Tren(ptsjuego, Juego::TTren, 350, 350));

	return true;
}

void play::freeObjects() {
}

void play::update() {

	estado::update();
}

void play::move(char c){
	objetos[0]->move(c);
}