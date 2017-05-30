#ifndef H_FINNIVEL_H
#define H_FINNIVEL_H

#include "Estado.h"
#include "Sound.h"
#include "Hud.h"
#include "Creditos.h"
class FinNivel :
	public Estado
{
public:
	FinNivel(Game* juego, bool v);
	virtual ~FinNivel() { sound->stopMusic(); }
private:
	
	static void jugar(Game * jg);
	static void cred(Game * jg){
		jg->changeState(new Creditos(jg));
	}
	void draw();
	void update(Uint32 d);
	bool initLibraries();
	bool victory;

	Hud* fondo;
	Hud* letras;
	Sound* sound;
	Texturas* font;
	SDL_Color fontColor;
	string textoo;
	bool shown = false;
};


#endif