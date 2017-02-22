#include "personaje.h"
#include "bala.h"


personaje::personaje(Juego* juego, Juego::Texturas_t text, int x, int y)
{
	juegootp = juego;
	Ttextura = text;

	alto  = 50;
	ancho = 50;

	pimgx = x;
	pimgy = y;
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

}

void personaje::onClick() {
}
void personaje::move(char c) {
	if (c == 'W'){
		if (pimgy >= 60)
			pimgy -= 5;
	}
	else if (c == 'S'){
		if (pimgy <= 540)
			pimgy += 5;
	}
	
}