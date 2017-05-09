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
#include "Hud.h"

using namespace std;

class Play : public Estado
{
public:
	Play(Game * j);
	~Play();

	void draw();
	void update(Uint32 delta);
	void move(char c);
	char getEst() { return 'P'; }
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
	Texturas* font;
	SDL_Color fontColor;
	Sound* soundLoss;
	Sound* soundWon;
	//Sound* sonido;
	ArmaTienda* armaActual;

	int contWin = 0;
	bool fin;
	bool initObjects(); //crear y destruir los objetos del juego
	void freeObjects();

	Escenario*esc;
	Hud* h;
	Hud* tray;
};


#endif