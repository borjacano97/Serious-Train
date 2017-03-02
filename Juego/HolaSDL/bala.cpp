#include "bala.h"


Bala::Bala(game* juego, game::Texturas_t text, int x, int y, int mira)
{

	juegootp = juego;
	Ttextura = text;

	alto = 20;
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
	if (pimgx <= 100 || pimgx >=1200){
		destruido = true;	
	}
		
	pimgx += dir * vel;


}
void Bala::move(char c){

}