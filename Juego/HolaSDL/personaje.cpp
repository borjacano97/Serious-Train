#include "personaje.h"



personaje::personaje(Juego* juego, Juego::Texturas_t text, int x, int y)
{
	juegootp = juego;
	Ttextura = text;

	alto  = 500;
	ancho = 500;

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
