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


Personaje::~Personaje()
{
}

void Personaje::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;
		
	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);
	
}


void Personaje::update() {
	pimgx += dir.x*vel;
	pimgy += dir.y*vel;
	if (pimgx < 555)
		pimgx = 555;
	else if (pimgx > 675)
		pimgx = 675;
	if (pimgy < 60)
		pimgy = 60;
	else if (pimgy > 560)
		pimgy = 560;
}

bool Personaje::onClick() {
	return true;
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