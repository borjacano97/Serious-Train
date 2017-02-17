#pragma once
#include "Globo.h"
class GloboA : public Globo
{
public:
	GloboA(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y);
	~GloboA();
	// no es necesario poner todos los métodos de Globo porque los hereda
	// en caso de ponerlos en el .h habría que ponerlos en el .cpp también 
	
	void update(); // solo cambia el método update de los globos nuevos 
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

