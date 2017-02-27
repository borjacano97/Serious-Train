#include "play.h"
#include "estado.h"
#include "personaje.h"
#include "bala.h"
#include "enemigo.h"
#include "tren.h"
#include "barraHP.h"

#include <string>
#include<stdlib.h> // para nms aleatorios
#include<time.h>

play::play(game * j) : estado(j)
{
	srand(time(NULL));
	initObjects();
}


play::~play()
{
	
}

bool play::initObjects() { // creaci�n de los objetos dando un puntero, una textura y una posici�n (constructora de objs)

	objetos.emplace_back(new tren(ptsjuego, game::TTren, 50, 0, " ")); // en el �ltimo hueco poner como string tipo de vag�n
	objetos.emplace_back(new personaje(ptsjuego, game::TPersonaje, 650, 350));
	objetos.emplace_back(new barraHP(ptsjuego, game::TBarra, 10, 0, 0));

	

	return true;
}

void play::freeObjects() {
	
}
void play::onClick(){
	//objetos[0]->onClick();
	balas.emplace_back(new bala(ptsjuego, game::TPersonaje, objetos[1]->getx(), objetos[1]->gety(), objetos[1]->getI()));
}
void play::update() {  
	for (int i = 3; i < objetos.size(); i++) {

		
		if (objetos[i] != nullptr  && objetos[i]->getId() == 'E' 
			&& objetos[i]->getx() >= 520 && objetos[i]->getx() <= 775) {// detecta zombis que quitan vida al tren
			objetos[2]->move('h');
		}
		for (int j = 0; j < balas.size(); j++) {
			// muerte por colisi�n de objetos exceptuando el personaje, tren y barra de vida, si va a haber choque entre zombies hay que poner
			// un booleano que identifique entre balas y sombis
			if (objetos[i] != nullptr && balas[j] != nullptr && 
				(objetos[i]->getx() - balas[j]->getx()) <= 30 && (objetos[i]->getx() - balas[j]->getx()) >= -30 &&
				 (objetos[i]->gety() - balas[j]->gety()) <= 40 && (objetos[i]->gety() - balas[j]->gety()) >= -40) {

			    delete objetos[i];
			    objetos[i] = nullptr;
				delete balas[j];
				balas[j] = nullptr;
		     }
		}
		
		
		
	}
	aleatorio = rand() % 10000; //generar zombies aleatorios
	if (aleatorio >= 9980) {
		izq = rand() % 2;
		if (izq == 0) objetos.emplace_back(new enemigo(ptsjuego, game::TEnemigo, 0, rand() % 500 + 50));
		else objetos.emplace_back(new enemigo(ptsjuego, game::TEnemigo, 1300, rand() % 500 + 50));
	}
	estado::update();
}

void play::move(char c){
	objetos[1]->move(c);
}