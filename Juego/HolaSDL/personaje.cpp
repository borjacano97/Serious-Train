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

	velx = 0;
	vely = 0;
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
	int aux1, aux2;
	aux1 = pimgx;
	aux2 = pimgy;
    pimgx += velx;
	pimgy += vely;
	if (pimgx < 580 || pimgx > 700)
		pimgx = aux1;
	if (pimgy < 60 || pimgy > 560)
		pimgy = aux2;
}

void personaje::onClick() {
}
void personaje::move(char c) {
	if (c == 'W' ){		
		vely = -1;
	}
	else if (c == 'S'){
		vely = 1;
	}
	if (c == 'A' ) {
		izq = true;
		velx = -1;
	}
	else if (c == 'D') {
		izq = false;
		velx = 1;
	}	
	if (c == 'N') {
		
		velx = 0;
		vely = 0;
	}
	
}