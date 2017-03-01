#include "enemigo.h"
#include "estado.h"
#include "game.h"



enemigo::enemigo(game* juego, game::Texturas_t text, int x, int y)
{
	juegootp = juego;
	Ttextura = text;

	alto = 50;
	ancho = 50;

	pimgx = x;
	pimgy = y;
}


enemigo::~enemigo()
{
}

void enemigo::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;

	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);

}

bool enemigo::onClick() {
	return true;
}
void enemigo::update() {
	cont++;
	if (cont >= 5 && pimgx >=775) {
		cont = 0;
		pimgx--;
	}
	if (cont >= 5 && pimgx <= 520) {
		cont = 0;
		pimgx++;
	}

}


void enemigo::move(char c) {

}


