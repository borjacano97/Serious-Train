#include "Enemigo.h"
#include "Estado.h"
#include "Game.h"



Enemigo::Enemigo(Game* juego, Game::Texturas_t text, int x, int y, bool rap)
{
	juegootp = juego;
	Ttextura = text;

	alto = 50;
	ancho = 50;

	pimgx = x;
	pimgy = y;

	r = rap;
}


Enemigo::~Enemigo()
{
}

void Enemigo::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;

	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);

}

bool Enemigo::onClick() {
	return true;
}
void Enemigo::update(Uint32 delta) {

	cont++;
	if (cont >= 5 && pimgx >=745) { // ZAS, En TODA LA BOCA
		cont = 0;
		if (r) pimgx -= 2;
		else pimgx--;
	}
	if (cont >= 5 && pimgx <= 500) {
		cont = 0;
		if (r) pimgx += 2;
		else pimgx++;
	}

}


void Enemigo::move(char c) {

}


