#include "Play.h"
#include "Personaje.h"
#include "Bala.h"
#include "Enemigo.h"
#include "Vagon.h"
#include "BarraHP.h"
#include "FinNivel.h"

#include <string>
#include <stdlib.h> // para nms aleatorios
#include <time.h>


Play::Play(Game * j) : Estado(j)
{
	//srand(time(NULL));
	//ptsjuego = j;
	initObjects();
	enem = 0;
	killed = 0;
	emax = 5 * ptsjuego->getNivel();

	fin = false;
	
	/*SDL_Surface *text;
	SDL_Color text_color = { 255, 255, 255 };
	text = TTF_RenderText_Solid(font,
		"A journey of a thousand miles begins with a single step.",
		text_color);*/
}


Play::~Play()
{
	freeObjects();	
}

bool Play::initObjects() { // creación de los objetos dando un puntero, una textura y una posición (constructora de objs)
	for (unsigned int i = 0; i < vag; i++) {
		tren.emplace_back(new Vagon(ptsjuego, Game::TTren, 25, 131*i, ""));
	}
	//train = new Tren(ptsjuego, Game::TTren, 25, 0, " ");// en el último hueco poner como string tipo de vagón
	player = new Personaje(ptsjuego, Game::TPersonaje, 650, 350);
	TrainHp = new barraHP(ptsjuego, Game::TBarra, 10, 15, 0);
	

	return true;
}

void Play::freeObjects() {
	// c++11
	for (auto o : tren) {
		delete o;
	}
	for (auto o : objetos) { 
		delete o;
	}
	for (auto b : balas) {
		delete b;
	}	
}
void Play::draw() {
	for (auto i : tren){
			i->draw();
	}
	for (auto i : objetos){
		if (i != nullptr){
			i->draw();
		}
	}
	for (auto i : balas){
		if (i != nullptr){
			i->draw();
		}
	}
	player->draw();
	TrainHp->draw();

}

void Play::onClick(){
	//objetos[0]->onClick();
	balas.emplace_back(new Bala(ptsjuego, Game::TPersonaje, player->getx(), player->gety(), player->getMira()));
}
void Play::update() {

	for (auto i : tren){
		i->update();
	}

	for (auto i : objetos){
		if (i != nullptr){
			i->update();
		}
	}
	for (auto i : balas){
		if (i != nullptr){
			i->update();
		}
	}
	player->update();
	TrainHp->update();
	// si esto no puede (o no debe ser null) quitad esto
	if (TrainHp->getDest() || fin) {
		if (TrainHp->getDest())	ptsjuego->changeState(new FinNivel(ptsjuego, false));
		else {
			ptsjuego->incrNivel();
			ptsjuego->changeState(new FinNivel(ptsjuego, true));
		}
	}

	else {
		//for (auto obj : objetos){
		//	if (obj != nullptr && obj->getx() >= 500 && obj->getx() <= 745) {// detecta zombis que quitan vida al tren
		//		TrainHp->move('h');
		//	}

		//	for (auto target : balas){	
		//		if (target != nullptr && target->getDest()){
		//			delete target;
		//			target = nullptr;
		//		}

		//		if (obj != nullptr && target != nullptr && obj->collision(target)){
		//			target->destroy();
		//			obj->destroy();
		//			if (obj->getId() == 'L') ptsjuego->addCoins(5);
		//			else  ptsjuego->addCoins(10);
		//			killed++;
		//		}
		//		if (obj != nullptr && obj->getDest()){
		//			delete obj;
		//			obj = nullptr;
		//		}
		//	}
		//}

		// esto va perfe
		for (unsigned int i = 0; i < objetos.size(); i++) {

			if (objetos[i] != nullptr && objetos[i]->getx() >= 500 && objetos[i]->getx() <= 745) {// detecta zombis que quitan vida al tren
				TrainHp->move('h');
			}
			for (unsigned int j = 0; j < balas.size(); j++) {
				// muerte por colisión de objetos exceptuando el personaje, tren y barra de vida, si va a haber choque entre zombies hay que poner
				// un booleano que identifique entre balas y sombis

				// El Dios de la programación está llorando.
				// Amargamente.
				if (balas[j] != nullptr && balas[j]->getDest()){
					delete balas[j];
					balas[j] = nullptr;
				}
				if (objetos[i] != nullptr && balas[j] != nullptr &&	objetos[i]->collision(balas[j])) {
					if (!objetos[i]->getDest()){
						objetos[i]->destroy();
						balas[j]->destroy();
					}
					else{
						objetos[i]->destroy();
						balas[j]->destroy();
						if (objetos[i]->getId() == 'L') ptsjuego->addCoins(5);
						else  ptsjuego->addCoins(10);
						killed++;
					}
				}
			}
			if (objetos[i] != nullptr && objetos[i]->getDest()){
				delete objetos[i];
				objetos[i] = nullptr;
			}
		}
	}
		Estado::update();
}
void Play::move(char c){
	player->move(c); // El Dios de la programación quiere suicidarse. Pero no puede, es inmortal.
}