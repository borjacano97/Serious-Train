#ifndef H_PLAY_H
#define H_PLAY_H

#include "Estado.h"
#include "Personaje.h"
#include "Enemigo.h"
#include "Vagon.h"
#include "BarraHP.h"
#include "Trigger.h"
#include "Bala.h"

class Play : public Estado
{
public:
	Play(Game * j);
	~Play();

	void onClick();
	void draw();
	void update(Uint32 delta);
	void move(char c);
	char getEst() { return 'P'; }
	int getKilled() { return killed; }
	void finish() { fin = true; }
	std::vector <Bala*> balas; // TODO mirad estándares de código
	std::vector <Enemigo*> enems;
	int killed;

	Trigger* tg;
private:
	Personaje* player;
	barraHP* TrainHp;
	Texturas* font;
	SDL_Color fontColor;

	unsigned int vag = 5;
	bool fin;
	bool initObjects(); //crear y destruir los objetos del juego
	void freeObjects();


	std::vector <Vagon*> tren; // TODO mirad estándares de código

	int emax, enem;
};


#endif