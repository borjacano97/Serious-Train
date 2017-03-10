#include "Vagon.h"
#include <string>



<<<<<<< HEAD
<<<<<<< HEAD
Vagon::Vagon(Game* juego, Game::Texturas_t text, int x, int y, std::string t)
=======
Tren::Tren(Game* juego, Game::Texturas_t text,  int x, int y, std::string t)
>>>>>>> Sprites
=======
Vagon::Vagon(Game* juego, Game::Texturas_t text, int x, int y, std::string t)
>>>>>>> issue#2
{
	juegootp = juego;
	Ttextura = text;

	alto = 130;
	ancho = 1200;

	pimgx = x;
	pimgy = y;

	tipo = t;
}


Vagon::~Vagon()
{
}


void Vagon::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;

	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);
}

void Vagon::update() {
	//hacer uso de la variable TIPO
}
bool Vagon::onClick() {
	return true;
}
void Vagon::move(char c) {

}