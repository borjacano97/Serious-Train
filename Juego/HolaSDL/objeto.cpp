#include "objeto.h"


Objeto::Objeto()
{
}


Objeto::~Objeto()
{
}
bool Objeto::dentro(int x, int y) const{
	return (x >= pimgx && x <= pimgx + ancho && y >= pimgy && y <= pimgy + alto);	
}
