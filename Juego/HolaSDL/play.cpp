#include "play.h"
#include "estado.h"
#include "personaje.h"
#include "bala.h"
#include "enemigo.h"

play::play(game * j) : estado(j)
{
	initObjects();
}


play::~play()
{
	
}

bool play::initObjects() { // creación de los objetos dando un puntero, una textura y una posición (constructora de objs)

	objetos.emplace_back(new personaje(ptsjuego, game::TPersonaje, 650, 350));
	objetos.emplace_back(new enemigo(ptsjuego, game::TEnemigo, 1200, 350));
	//objetos.emplace_back(new Enemigo(ptsjuego, Juego::TEnemigo, rand() % 700, 0));
	//objetos.emplace_back(new Tren(ptsjuego, Juego::TTren, 350, 350));

	return true;
}

void play::freeObjects() {
}
void play::onClick(){
	//objetos[0]->onClick();
	objetos.emplace_back(new bala(ptsjuego, game::TPersonaje, objetos[0]->getx(), objetos[0]->gety(), objetos[0]->getI()));
}
void play::update() {  
	for (int i = 1; i < objetos.size(); i++) {

		if(objetos[i] != nullptr && objetos[i]->getDest()){// si se destruye, se destruye
			delete objetos[i];
			objetos[i] = nullptr;
		}	
		
	}
	estado::update();
}

void play::move(char c){
	objetos[0]->move(c);
}