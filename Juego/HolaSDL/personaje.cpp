#include "Personaje.h"
#include "Bala.h"



Personaje::Personaje(Game* juego, Game::Texturas_t text, float x, float y)
{
	juegootp = juego;
	Ttextura = text;

	alto  = 50;
	ancho = 50;

	pos.set(x, y);

	dir.x = 0;
	dir.y = 0;
	mira = 1;
	vel = 0.5;
}

void Personaje::update(Uint32 delta) {
	pos.x += dir.x*vel*delta;
	pos.y += dir.y*vel*delta;
	if (pos.x < 600)
		pos.x = 600;
	else if (pos.x > 650)
		pos.x = 650;
	if (pos.y < 130)
		pos.y = 130;
	else if (pos.y > 650)
		pos.y = 650;
}

void Personaje::move(char c) {
	if (c == 'W' ){		
		dir.y = -1;
	}
	else if (c == 'S'){
		dir.y = 1;
	}
	if (c == 'A' ) {
		mira = -1;
		dir.x = -1;
	}
	else if (c == 'D') {
		mira = 1;
		dir.x = 1;
	}	
	if (c == 'N') {
		dir.x = 0;
		dir.y = 0;
	}	
}