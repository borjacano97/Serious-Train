#include "Personaje.h"
#include "Bala.h"



Personaje::Personaje(Game* juego, Game::Texturas_t text, int x, int y)
{
	juegootp = juego;
	Ttextura = text;

	alto  = 50;
	ancho = 50;

	pimgx = x;
	pimgy = y;

	dir.x = 0;
	dir.y = 0;
	mira = 1;
	vel = 1;
}

void Personaje::update(Uint32 delta) {
	pimgx += dir.x*vel*delta;
	pimgy += dir.y*vel*delta;
	if (pimgx < 620)
		pimgx = 620;
	else if (pimgx > 740)
		pimgx = 740;
	if (pimgy < 60)
		pimgy = 60;
	else if (pimgy > 750)
		pimgy = 750;
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