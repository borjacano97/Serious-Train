#include "GloboA.h"
#include "PlayPG.h"


GloboA::GloboA(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y) : Globo(juego, text, x, y)
{
}


GloboA::~GloboA()
{
}


void GloboA::update(){
	if (!explotado){//desactivar para evaluacion
		
		// si no ha salido de la pantalla, el globo va hacia arriba 
		if (pimgy > 0)
			pimgy -=5;
		if (pimgy == 0)
			puntos -= 10;
		// si el pocentaje es mayor que el de desinchado baja su tamaño y aumenta su puntuacion
		if (rand() % 100 >= PDES){
			alto -= DT;
			ancho -= DT;
			puntos += AP;
		}
		//si el ancho es menor que 10 explotado es true y visible false
		if (ancho <= 10){
			explotado = true;
			visible = false;
			dynamic_cast<PlayPG*>(juegootp->topEstado())->newBaja(this);

		}
	}
}