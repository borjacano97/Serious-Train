#include "Vagon.h"
#include <string>



Tren::Tren(Game* juego, Game::Texturas_t text,  int x, int y, std::string t)
{
	juegootp = juego;
	Ttextura = text;

	alto = 130;
	ancho = 1200;

	pimgx = x;
	pimgy = y;

	tipo = t;
}


Tren::~Tren()
{
}


void Tren::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;

	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);
}

void Tren::update() {
	//hacer uso de la variable TIPO
}
bool Tren::onClick() {
	return true;
}
void Tren::move(char c) {

}