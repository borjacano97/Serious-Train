#include "Objeto.h"


Objeto::Objeto()
{
}


Objeto::~Objeto()
{
}
bool Objeto::dentro(int x, int y) const{
	return (x >= pimgx && x <= pimgx + ancho && y >= pimgy && y <= pimgy + alto);	
}

bool Objeto::collision(RaizObjeto* other){
	return dentro(other->getx(), other->gety());
}