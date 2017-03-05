#include "play.h"
#include "estado.h"
#include "personaje.h"
#include "bala.h"
#include "enemigo.h"
#include "tren.h"
#include "barraHP.h"
#include "gameOver.h"

#include <string>
#include<stdlib.h> // para nms aleatorios
#include<time.h>

Play::Play(Game * j) : Estado(j)
{
	//srand(time(NULL));
	//ptsjuego = j;
	initObjects();
}


Play::~Play()
{
	freeObjects();
	ptsjuego = nullptr;
	train = nullptr;
	player = nullptr;
	TrainHp = nullptr;
	
}

bool Play::initObjects() { // creación de los objetos dando un puntero, una textura y una posición (constructora de objs)

	train = new Tren(ptsjuego, Game::TTren, 25, 0, " ");// en el último hueco poner como string tipo de vagón
	player = new Personaje(ptsjuego, Game::TPersonaje, 650, 350);
	TrainHp = new barraHP(ptsjuego, Game::TBarra, 10, 0, 0);


	objetos.emplace_back(train); 
	objetos.emplace_back(player);
	objetos.emplace_back(TrainHp);

	

	return true;
}

void Play::freeObjects() {
	for (unsigned int i = 3; i < objetos.size(); i++) {
		delete objetos[i];
		objetos[i] = nullptr;
	}
	for (unsigned int i = 3; i < balas.size(); i++) {
		delete balas[i];
		balas[i] = nullptr;
	}

	
}
void Play::onClick(){
	//objetos[0]->onClick();
	balas.emplace_back(new Bala(ptsjuego, Game::TPersonaje, player->getx(), player->gety(), player->getMira()));
}
void Play::update() {  
	
		if (TrainHp != nullptr && TrainHp->getDest()) {
			ptsjuego->changeState(new gameOver(ptsjuego));
		}
		else {
			for (unsigned int i = 3; i < objetos.size(); i++) {


				if (objetos[i] != nullptr  && objetos[i]->getId() == 'E'
					&& objetos[i]->getx() >= 500 && objetos[i]->getx() <= 745) {// detecta zombis que quitan vida al tren
					TrainHp->move('h');
				}
				for (unsigned int j = 0; j < balas.size(); j++) {
					// muerte por colisión de objetos exceptuando el personaje, tren y barra de vida, si va a haber choque entre zombies hay que poner
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
				if (izq == 0) objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo, 0, rand() % 500 + 50));
				else objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo, 1300, rand() % 500 + 50));
			}
			Estado::update();
	}
	
}

void Play::move(char c){
	objetos[1]->move(c);
}