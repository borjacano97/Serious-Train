#include "Play.h"
#include "Bala.h"
#include "Enemigo.h"
#include "Vagon.h"
#include "FinNivel.h"
#include "Trigger.h"

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
		"points",
		text_color);*/
}


Play::~Play()
{
	freeObjects();	
}

bool Play::initObjects() { // creaci�n de los objetos dando un puntero, una textura y una posici�n (constructora de objs)
	tren.emplace_back(new Vagon(ptsjuego, Game::TLocomotora, (ptsjuego->dm.w / 2) - 75, -50, Game::Vagon_t::VLocom));
	tren.emplace_back(new Vagon(ptsjuego, Game::TVagon1, (ptsjuego->dm.w / 2) - 75, 100, Game::Vagon_t::VAutomatico));
	for (unsigned int i = 2; i < vag; i++) {
		tren.emplace_back(new Vagon(ptsjuego, Game::TVagon1, (ptsjuego->dm.w / 2) - 75, 150 *i-50, Game::Vagon_t::VVacio));
	}	
	// en cuanto aparezca alg�n n�mero en las posiciones, va a ser siempre distinto al cambiar el tama�o de pantalla
	tg = new Trigger(ptsjuego, ptsjuego->dm.h/2 +180, 0); 
	player = new Personaje(ptsjuego, Game::TPersonaje, 650, 500);
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
	balas.emplace_back(new Bala(ptsjuego, Game::TRoca, player->getPos().x, player->getPos().y, player->getMira()));
}
void Play::update(Uint32 delta) {
		for (auto i : tren) {
			i->update(delta);
		}

		for (auto i : balas) {
			if (i != nullptr) {
				i->update(delta);
			}
		}

		//if (tg->collision(player))	player->update(delta); //fuck, no va por la fucking move que tenemos de player
		player->update(delta);
		TrainHp->update(delta);

		if (tren[1]->Disparo()) {
			balas.emplace_back(new Bala(ptsjuego, Game::TRoca, tren[1]->getPos().x + 120, tren[1]->getPos().y + 75, 1));
			balas.emplace_back(new Bala(ptsjuego, Game::TRoca, tren[1]->getPos().x, tren[1]->getPos().y + 75, -1));
			tren[1]->Stop();
		}
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

				if (objetos[i] != nullptr) {
					if (tg->collision(objetos[i])) TrainHp->move('h');
					else objetos[i]->update(delta);
				}
				for (unsigned int j = 0; j < balas.size(); j++) {
					// muerte por colisi�n de objetos exceptuando el personaje, tren y barra de vida, si va a haber choque entre zombies hay que poner
					// un booleano que identifique entre balas y sombis

					// El Dios de la programaci�n est� llorando.
					// Amargamente.
					if (balas[j] != nullptr && balas[j]->getDest()) {
						delete balas[j];
						balas[j] = nullptr;
					}
					if (objetos[i] != nullptr && balas[j] != nullptr &&	objetos[i]->collision(balas[j])) {
						if (!objetos[i]->getDest()) {
							objetos[i]->destroy();
							balas[j]->destroy();
						}
						else {
							ptsjuego->addCoins(objetos[i]->getPoints());
							objetos[i]->destroy();
							balas[j]->destroy();
							killed++;
						}
					}
				}
				if (objetos[i] != nullptr && objetos[i]->getDest()) {
					delete objetos[i];
					objetos[i] = nullptr;
				}
			}
		}
		Estado::update(delta);	
}
void Play::move(char c){
	player->move(c); // El Dios de la programaci�n quiere suicidarse. Pero no puede, es inmortal.
}