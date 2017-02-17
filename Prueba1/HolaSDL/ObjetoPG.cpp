#include "ObjetoPG.h"


ObjetoPG::ObjetoPG()
{
}


ObjetoPG::~ObjetoPG()
{
}

bool ObjetoPG::dentro(int x, int y) const{
	if (x >= pimgx && x <= pimgx + ancho && y >= pimgy && y <= pimgy + alto){
		return true;
	}
	return false;
}

int ObjetoPG::damePuntos(){
	return puntos;
}

