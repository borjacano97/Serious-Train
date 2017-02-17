#pragma once
#include "Globo.h"
class GloboA : public Globo
{
public:
	GloboA(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y);
	~GloboA();
	// no es necesario poner todos los m�todos de Globo porque los hereda
	// en caso de ponerlos en el .h habr�a que ponerlos en el .cpp tambi�n 
	
	void update(); // solo cambia el m�todo update de los globos nuevos 
private:

	bool visible;
	bool explotado;

	int mx;
	int my;


	SDL_Rect rect;

	int puntos = 1;

	//constantes del juego
	static const int PVIS = 70;
	static const int PDES = 30;
	static const int DT = 5;
	static const int AP = 5;
};

