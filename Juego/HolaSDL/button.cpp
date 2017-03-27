#include "Button.h"


Button::Button(Game* juego, Game::Texturas_t text, int x, int y, CallBack_t * cbCons)
{
	juegootp = juego;

	pimgx = x;
	pimgy = y;

	alto = 100;
	ancho = 200;

	Ttextura = text;

	cb = cbCons;
}

bool Button::onClick(){
	juegootp->getMousePos(mpbx, mpby);

	if (dentro(mpbx, mpby)){
		cb(juegootp);
		return true;
	}
	else return false;
}


void Button::update(Uint32 delta){

}