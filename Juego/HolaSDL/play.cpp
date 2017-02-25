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

bool play::initObjects() { // creaci�n de los objetos dando un puntero, una textura y una posici�n (constructora de objs)

	objetos.emplace_back(new personaje(ptsjuego, game::TPersonaje, 650, 350));
	objetos.emplace_back(new enemigo(ptsjuego, game::TEnemigo, 1200, 50));
	objetos.emplace_back(new enemigo(ptsjuego, game::TEnemigo, 1200, 350));
	objetos.emplace_back(new enemigo(ptsjuego, game::TEnemigo, 1200, 550));
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
		for (int j = 1; j < objetos.size(); j++) {
			// muerte por colisi�n de objetos exceptuando el personaje que es objetos[0], si va a haber choque entre zombies hay que poner
			// un booleano que identifique entre balas y sombis
		     if (i!= j && objetos[i] != nullptr && objetos[j] != nullptr &&  objetos[i]->getx() == objetos[j]->getx() && 
				 (objetos[i]->gety() - objetos[j]->gety())<=50 && (objetos[i]->gety() - objetos[j]->gety()) >= -50) {

			    delete objetos[i];
			    objetos[i] = nullptr;
				delete objetos[j];
				objetos[j] = nullptr;
		     }
		}
		
	}
	estado::update();
}

void play::move(char c){
	objetos[0]->move(c);
}