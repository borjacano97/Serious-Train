#include "Play.h"
#include "Personaje.h"
#include "Bala.h"
#include "Enemigo.h"
#include "Vagon.h"
#include "BarraHP.h"
#include "GameOver.h"

#include <string>
#include<stdlib.h> // para nms aleatorios
#include<time.h>

Play::Play(Game * j) : Estado(j)
{
	//srand(time(NULL));
	//ptsjuego = j;
	initObjects();
	enem = 0;
	killed = 0;
}


Play::~Play()
{
	freeObjects();	
}

bool Play::initObjects() { // creación de los objetos dando un puntero, una textura y una posición (constructora de objs)
	for (unsigned int i = 0; i < vag; i++) {
		tren.emplace_back(new Tren(ptsjuego, Game::TTren, 25, 131*i, ""));
	}
	//train = new Tren(ptsjuego, Game::TTren, 25, 0, " ");// en el último hueco poner como string tipo de vagón
	player = new Personaje(ptsjuego, Game::TPersonaje, 650, 350);
	TrainHp = new barraHP(ptsjuego, Game::TBarra, 10, 15, 0);


	objetos.emplace_back(player);
	objetos.emplace_back(TrainHp);

	

	return true;
}

void Play::freeObjects() {
	// c++11
	for (auto o : objetos) { 
		delete o;
	}
	for (auto b : balas) {
		delete b;
	}	
}
void Play::draw() {
	for (unsigned int i = 0; i < tren.size(); i++) {
		if (tren[i] != nullptr)
			tren[i]->draw();
	}
	for (unsigned int i = 0; i < objetos.size(); i++) {
		if (objetos[i] != nullptr)
			objetos[i]->draw();
	}
	for (unsigned int i = 0; i < balas.size(); i++) {
		if (balas[i] != nullptr)
			balas[i]->draw();
	}
	
}

void Play::onClick(){
	//objetos[0]->onClick();
	balas.emplace_back(new Bala(ptsjuego, Game::TPersonaje, player->getx(), player->gety(), player->getMira()));
}
void Play::update() {  

	    for (unsigned int i = 0; i < tren.size(); i++) {
		    if (tren[i] != nullptr)
			    tren[i]->update();
	    } 
		for (unsigned int i = 0; i < objetos.size(); i++) {
			if (objetos[i] != nullptr)
				objetos[i]->update();
		}
		for (unsigned int i = 0; i < balas.size(); i++) {
			if (balas[i] != nullptr)
				balas[i]->update();
		}
		

	// si esto no puede (o no debe ser null) quitad esto
		if (TrainHp->getDest() || killed >= 5) {
			ptsjuego->changeState(new GameOver(ptsjuego));
		}
		
		else {
			// for guay aquí. cuidado con i = 2.
			for (unsigned int i = 2; i < objetos.size(); i++) {


				if (objetos[i] != nullptr  && objetos[i]->getId() == 'E'
					&& objetos[i]->getx() >= 500 && objetos[i]->getx() <= 745) {// detecta zombis que quitan vida al tren
					TrainHp->move('h');
				}
				for (unsigned int j = 0; j < balas.size(); j++) {
					// muerte por colisión de objetos exceptuando el personaje, tren y barra de vida, si va a haber choque entre zombies hay que poner
					// un booleano que identifique entre balas y sombis
					if (balas[j] != nullptr && balas[j]->getDest()){
						delete balas[j];
						balas[j] = nullptr;
					}

					// El Dios de la programación está llorando.
					// Amargamente.

					if (objetos[i] != nullptr && balas[j] != nullptr &&
						(objetos[i]->getx() - balas[j]->getx()) <= 30 && (objetos[i]->getx() - balas[j]->getx()) >= -30 &&
						(objetos[i]->gety() - balas[j]->gety()) <= 40 && (objetos[i]->gety() - balas[j]->gety()) >= -40) {
												
						delete balas[j];
						balas[j] = nullptr;		
						delete objetos[i];
						objetos[i] = nullptr;
						killed++;
					}					
				}
		}
			aleatorio = rand() % 10000; //generar zombies aleatorios
			if (enem < 5 && aleatorio >= 9985){
				if (izq == 0) objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo, 0, rand() % 500 + 50, false));
				else objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo, 1300, rand() % 500 + 50, false));
				enem++;
			}
			else if (enem < 5 && aleatorio >= 9980) {
				izq = rand() % 2;
				if (izq == 0) objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo2, 0, rand() % 500 + 50, true));
				else objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo2, 1300, rand() % 500 + 50, true));
				enem++;
			}
			
			Estado::update();
	}
	
}

void Play::move(char c){
	player->move(c); // El Dios de la programación quiere suicidarse. Pero no puede, es inmortal.
}