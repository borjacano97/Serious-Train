#include "bala.h"


bala::bala(game* juego, game::Texturas_t text, int x, int y, bool i)
{

	juegootp = juego;
	Ttextura = text;

	alto = 50;
	ancho = 50;

	pimgx = x;
	pimgy = y;
	if (i)
		vel *= -1;
}


bala::~bala()
{
}
void bala::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;

	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);
}

void bala::onClick() {
}

void bala::update() {
	pimgx += vel;
}
void bala::move(char c){

}