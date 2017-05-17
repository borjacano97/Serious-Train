#ifndef H_PLAY_H
#define H_PLAY_H

#include "Estado.h"
#include "Personaje.h"
#include "Enemigo.h"
#include "Vagon.h"
#include "BarraHP.h"
#include "Trigger.h"
#include "Bala.h"
#include "Sound.h"
#include "Escenario.h"
#include "ArmaTienda.h"

using namespace std;

class Play : public Estado
{
public:
	Play(Game * j);
	~Play();
	Estado_t getEstado() { return Estado_t::Play_t; }
	void draw();
	void update(Uint32 delta);
	bool handle_events(SDL_Event * evento);
	void move(char c);
	int getKilled() { return killed; }
	void finish() { fin = true; }

	vector <Bala*> balas;
	vector <Enemigo*> enems;
	vector <Vagon*> tren; 
	int killed;

	Trigger* tg;
	barraHP* TrainHp;
	Personaje* player;
protected:
	Game* game_ptr;
	Texturas* font;
	SDL_Color fontColor;
	Sound* soundLoss;
	Sound* soundWon;
	//Sound* sonido;
	ArmaTienda* armaActual;

	void dispara(bool disparando) {};
	bool fin;
	bool initObjects(); //crear y destruir los objetos del juego
	void freeObjects();

	Escenario*esc;
};


#endif