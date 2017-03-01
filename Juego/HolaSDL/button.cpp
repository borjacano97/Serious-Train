#include "button.h"


button::button(game* juego, game::Texturas_t text, int x, int y, CallBack_t * cbCons)
{
	juegootp = juego;

	pimgx = x;
	pimgy = y;

	alto = 100;
	ancho = 200;

	Ttextura = text;

	cb = cbCons;
}


button::~button()
{
}
void button::move(char c){

}

void button::draw(){
	rectb.h = alto;
	rectb.w = ancho;
	rectb.x = pimgx;
	rectb.y = pimgy;

	juegootp->getTextura(Ttextura)->draw(juegootp->getRender(), nullptr, &rectb);
}


bool button::onClick(){
	juegootp->getMousePos(mpbx, mpby);

	if (dentro(mpbx, mpby)){
		cb(juegootp);
		return true;
	}
	else return false;
}


void button::update(){

}