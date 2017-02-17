#pragma once
#include "JuegoPG.h"
class ObjetoPG : public ObjetoJuego
{
public:
	ObjetoPG();
	~ObjetoPG();
	bool dentro(int x, int y) const;
	int damePuntos();
	// no es necesario poner los m�todos virtuales de ObjetoJuego porque los hereda
	// en caso de ponerlos en el .h habr�a que ponerlos en el .cpp tambi�n 
protected:
	JuegoPG* juegootp;

	JuegoPG::Texturas_t Ttextura;

	int alto;
	int ancho;

	int pimgx;
	int pimgy;

	int puntos = 0;

};

