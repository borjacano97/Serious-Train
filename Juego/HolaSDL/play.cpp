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

bool Play::initObjects() { // creaci�n de los objetos dando un puntero, una textura y una posici�n (constructora de objs)
	for (unsigned int i = 0; i < vag; i++) {
		tren.emplace_back(new Vagon(ptsjuego, Game::TTren, 25, 131*i, ""));
	}
	//train = new Tren(ptsjuego, Game::TTren, 25, 0, " ");// en el �ltimo hueco poner como string tipo de vag�n
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
	for (auto i : tren){
			i->draw();
	}
	for (auto i : objetos){
		if (i != nullptr){
			i->draw();
		}
	}
	
}

void Play::onClick(){
	//objetos[0]->onClick();
	objetos.emplace_back(new Bala(ptsjuego, Game::TPersonaje, player->getx(), player->gety(), player->getMira()));
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

	// si esto no puede (o no debe ser null) quitad esto
		if (TrainHp->getDest() || killed >= emax) {
			if (TrainHp->getDest())	ptsjuego->changeState(new FinNivel(ptsjuego, false));
			else {
				ptsjuego->incrNivel();
				ptsjuego->changeState(new FinNivel(ptsjuego, true));
			}
		}
		
		else {
			// for guay aqu�. cuidado con i = 2.
			for (unsigned int i = 2; i < objetos.size(); i++) {


				if (objetos[i] != nullptr  && (objetos[i]->getId() == 'R' || objetos[i]->getId() == 'L')
					&& objetos[i]->getx() >= 500 && objetos[i]->getx() <= 745) {// detecta zombis que quitan vida al tren
					TrainHp->move('h');
				}
				for (unsigned int j = 0; j < objetos.size(); j++) {
					// muerte por colisi�n de objetos exceptuando el personaje, tren y barra de vida, si va a haber choque entre zombies hay que poner
					// un booleano que identifique entre balas y sombis
					if (objetos[j] != nullptr  && objetos[j]->getId() == 'B' && objetos[j]->getDest()){
						delete objetos[j];
						objetos[j] = nullptr;
					}

					// El Dios de la programaci�n est� llorando.
					// Amargamente.

					if (objetos[i] != nullptr && objetos[j] != nullptr && (objetos[i]->getId() == 'R' || objetos[i]->getId() == 'L') && objetos[j]->getId() == 'B' &&
						(objetos[i]->getx() - objetos[j]->getx()) <= 30 && (objetos[i]->getx() - objetos[j]->getx()) >= -30 &&
						(objetos[i]->gety() - objetos[j]->gety()) <= 40 && (objetos[i]->gety() - objetos[j]->gety()) >= -40) {
						
						if (objetos[i]->getId() == 'L') ptsjuego->addCoins(5);
						else  ptsjuego->addCoins(10);

						delete objetos[j];
						objetos[j] = nullptr;		
						delete objetos[i];
						objetos[i] = nullptr;
						killed++;
					}					
				}
		}
			aleatorio = rand() % 10000; //generar zombies aleatorios
			if (enem < emax && aleatorio >= 9980){
				izq = rand() % 2;
				if (izq == 0) objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo2, 0, rand() % 500 + 50, false));
				else objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo2, 1300, rand() % 500 + 50, false));
				enem++;
			}
			else if (enem < emax && aleatorio >= 9975) {
				izq = rand() % 2;
				if (izq == 0) objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo, 0, rand() % 500 + 50, true));
				else objetos.emplace_back(new Enemigo(ptsjuego, Game::TEnemigo, 1300, rand() % 500 + 50, true));
				enem++;
			}
			
			Estado::update();
	}
	
}

void Play::move(char c){
	player->move(c); // El Dios de la programaci�n quiere suicidarse. Pero no puede, es inmortal.
}