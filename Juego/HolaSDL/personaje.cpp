#include "personaje.h"
#include "bala.h"



personaje::personaje(game* juego, game::Texturas_t text, int x, int y)
{
	juegootp = juego;
	Ttextura = text;

	alto  = 50;
	ancho = 50;

	pimgx = x;
	pimgy = y;

	dir.x = 0;
	dir.y = 0;

	vel = 3;
}


personaje::~personaje()
{
}

void personaje::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;
		
	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);
	
}


void personaje::update() {
	pimgx += dir.x*vel;
	pimgy += dir.y*vel;
	if (pimgx < 580)
		pimgx = 580;
	else if (pimgx > 700)
		pimgx = 700;
	if (pimgy < 60)
		pimgy = 60;
	else if (pimgy > 560)
		pimgy = 560;
}

void personaje::onClick() {
}
void personaje::move(char c) {
	if (c == 'W' ){		
		dir.y = -1;
	}
	else if (c == 'S'){
		dir.y = 1;
	}
	if (c == 'A' ) {
		izq = true;
		dir.x = -1;
	}
	else if (c == 'D') {
		izq = false;
		dir.x = 1;
	}	
	if (c == 'N') {
		
		dir.x = 0;
		dir.y = 0;
	}
	
}