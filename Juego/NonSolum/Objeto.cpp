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
	rect.x = pos.x;
	rect.y = pos.y;
	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);
}

bool Objeto::dentro(int x, int y) const{
	return (x >= pos.x && x <= pos.x + ancho && y >= pos.y && y <= pos.y + alto);	
}

bool Objeto::collision(RaizObjeto* other){
	return dentro(other->getPos().x, other->getPos().y);
}
