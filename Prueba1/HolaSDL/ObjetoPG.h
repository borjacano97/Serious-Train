#pragma once
#include "JuegoPG.h"
class ObjetoPG : public ObjetoJuego
{
public:
	ObjetoPG();
	~ObjetoPG();
	bool dentro(int x, int y) const;
	int damePuntos();
	// no es necesario poner los métodos virtuales de ObjetoJuego porque los hereda
	// en caso de ponerlos en el .h habría que ponerlos en el .cpp también 
protected:
	JuegoPG* juegootp;

	JuegoPG::Texturas_t Ttextura;

	int alto;
	int ancho;

	int pimgx;
	int pimgy;

	int puntos = 0;

};

