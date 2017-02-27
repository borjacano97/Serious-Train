#include "barraHP.h"



barraHP::barraHP(game* juego, game::Texturas_t text, int x, int y, int extraHP)
{
	juegootp = juego;
	Ttextura = text;

	alto = 50;
	ancho = 200 + extraHP;

	pimgx = x;
	pimgy = y;

	cont = 0;
}


barraHP::~barraHP()
{
}
void barraHP::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;

	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);
}

void barraHP::update() {
	
}
void barraHP::onClick() {

}
void barraHP::move(char c) {
	cont++;
	if (cont >= 50) {
		cont = 0;
		ancho--;
	}
	
}
