#include "tren.h"
#include <string>



tren::tren(game* juego, game::Texturas_t text, int x, int y, std::string t)
{
	juegootp = juego;
	Ttextura = text;

	alto = 700;
	ancho = 1200;

	pimgx = x;
	pimgy = y;

	tipo = t;
}


tren::~tren()
{
}


void tren::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;

	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);
}

void tren::update() {
	//hacer uso de la variable TIPO
}
bool tren::onClick() {
	return true;
}
void tren::move(char c) {

}