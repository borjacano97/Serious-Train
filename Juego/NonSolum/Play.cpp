﻿#include "Play.h"
#include "Bala.h"
#include "Enemigo.h"
#include "Vagon.h"
#include "FinNivel.h"
#include "Trigger.h"

#include <string>
#include <stdlib.h> // para nºs aleatorios
#include <time.h>


Play::Play(Game * j) : Estado(j)
{
	//srand(time(NULL));
	//ptsjuego = j;
	initObjects();
	killed = 0;

	font = new Texturas(/*80, 80, 50, 50*/);
	font->loadFuente("../fonts/fuenteNumbers.ttf", 200);

	/*sonido = new Sound;
	sonido->playMusic("../sounds/prueba.mp3", 3, 20);
	/*soundLoss = new Sound;
	soundWon = new Sound;*/

	fontColor.r = 218;
	fontColor.g = 165;
	fontColor.b = 32;

	fin = false;

	j->sound->playEffect("../sounds/trainEffect.mp3", 300, 15, 1);
}


Play::~Play()
{
	freeObjects();
	
}

bool Play::initObjects() { // creaci�n de los objetos dando un puntero, una textura y una posici�n (constructora de objs)
	
	tg = new Trigger(ptsjuego, NULL, 530, -20);
	player = new Personaje(ptsjuego, Game::TPersonaje, 650, 500);
	TrainHp = new barraHP(ptsjuego, Game::TBarra, 10, 15);
	tren.emplace_back(new Vagon(ptsjuego, this, 580, -50, Game::Vagon_t::Locom));

	TTF_Init();
	/*if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}
	return true;*/
	return Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) != -1;
}

void Play::freeObjects() {
	// c++11
	TTF_Quit();
	for (auto o : tren) {
		delete o;
	}
	for (auto o : enems) {
		delete o;
	}
	for (auto b : balas) {
		delete b;
	}
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1;
}
void Play::draw() {
	esc->draw();	

	for (auto i : tren) {
		i->draw();
	}
	for (auto i : enems) {
		if (i != nullptr) {
			i->draw();
		}
	}
	for (auto i : balas) {
		if (i != nullptr) {
			i->draw();
		}
	}

	player->draw();
	TrainHp->draw();
	if (armaActual != nullptr) armaActual->draw(); // quitar comprobación de nullptr si se traslada al modo Historia
}


void Play::update(Uint32 delta) {
	esc->update(delta);
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


	if (TrainHp->getDest() || fin) {
		if (TrainHp->getDest()) {
			ptsjuego->changeState(new FinNivel(ptsjuego, false));
		soundLoss->playMusic("../sounds/lossLevel.mp3", 2, 20);
		}
		else {
			ptsjuego->incrNivel();
			ptsjuego->changeState(new FinNivel(ptsjuego, true));
			soundWon->playMusic("../sounds/wonLevel.mp3", 2, 20);
		}
	}

	else {
		for (unsigned int i = 0; i < enems.size(); i++) {

			if (enems[i] != nullptr) {
				
				if (tg->collision(enems[i])) {
					
					TrainHp->damage(Game::EnemyDmg_t::Simple);
					enems[i]->parar();
					esc->ralentizar(delta);
				}
				
				enems[i]->update(delta);
			}
			if (enems[i] != nullptr && enems[i]->getDest()) {
				if (!ptsjuego->survival) ptsjuego->addCoins(enems[i]->getPoints());
				delete enems[i];
				enems[i] = nullptr;
				killed++;
			}
		}
		for (unsigned int j = 0; j < balas.size(); j++) {

			if (balas[j] != nullptr && balas[j]->getDest()) {
				delete balas[j];
				balas[j] = nullptr;
			}
		}
	}
	Estado::update(delta);
}
void Play::move(char c) {
	player->move(c); // El Dios de la programaci�n quiere suicidarse. Pero no puede, es inmortal.
}