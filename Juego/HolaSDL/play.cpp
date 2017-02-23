#include "play.h"
#include "estado.h"
#include "personaje.h"
#include "bala.h"

play::play(game * j) : estado(j)
{
	initObjects();
}


play::~play()
{
	
}

bool play::initObjects() { // creación de los objetos dando un puntero, una textura y una posición (constructora de objs)

	objetos.emplace_back(new personaje(ptsjuego, game::TPersonaje, 650, 350));
	//objetos.emplace_back(new Enemigo(ptsjuego, Juego::TEnemigo, rand() % 700, 0));
	//objetos.emplace_back(new Tren(ptsjuego, Juego::TTren, 350, 350));

	return true;
}

void play::freeObjects() {
}
void play::onClick(){
	//objetos[0]->onClick();
	objetos.emplace_back(new bala(ptsjuego, game::TPersonaje, 650, 350, true));
}
void play::update() {

	estado::update();
}

void play::move(char c){
	objetos[0]->move(c);
}