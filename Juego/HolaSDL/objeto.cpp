#include "objeto.h"


objeto::objeto()
{
}


objeto::~objeto()
{
}
bool objeto::dentro(int x, int y) const{
	std::cout << x << "\n";
	return (x >= pimgx && x <= pimgx + ancho && y >= pimgy && y <= pimgy + alto);
	
}
