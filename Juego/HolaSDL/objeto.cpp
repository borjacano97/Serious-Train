#include "Objeto.h"


Objeto::Objeto()
{
}


Objeto::~Objeto()
{
}
void Objeto::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;
	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);
}

bool Objeto::dentro(int x, int y) const{
	return (x >= pimgx && x <= pimgx + ancho && y >= pimgy && y <= pimgy + alto);	
}

bool Objeto::collision(RaizObjeto* other){
	return dentro(other->getx(), other->gety());
}