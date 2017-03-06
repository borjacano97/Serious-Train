#include "Bala.h"


Bala::Bala(Game* juego, Game::Texturas_t text, int x, int y, int mira)
{

	juegootp = juego;
	Ttextura = text;

	alto = 20;  // "Esto para probar, luego..."
	ancho = 20;

	pimgx = x;
	pimgy = y;
	
	dir = mira;
}


Bala::~Bala()
{
}
void Bala::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;
	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);
	
	
}

bool Bala::onClick() {
	return true;
}

void Bala::update() {
	pimgx += dir * vel;
	
	if (pimgx <= 100 || pimgx >=1200)
		destruido = true;
}
void Bala::move(char c){

}