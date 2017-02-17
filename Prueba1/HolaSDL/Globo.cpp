#include "Globo.h"
#include "PlayPG.h"


Globo::Globo(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y)
{
	Ttextura = text;

	juegootp = juego;

	ancho = 100;
	alto = 100;

	pimgx = x;
	pimgy = y;

	visible = true;
	explotado = false;
}


Globo::~Globo()
{
	
}

void Globo::draw(){
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;

	//si es visible llama al draw de texturasSDl
	if (visible && !explotado){
		SDL_Renderer* render = juegootp->getRender();
		juegootp->getTextura(Ttextura)->draw(render,nullptr, &rect);
	}
}
bool Globo::onClick(){ //captura la posicion donde se ha pinchado y ve si coincide con la superficie del globo
	juegootp->getMousePos(mx, my);
	if (visible && !explotado){
		if (dentro(mx, my)){
			explotado = true;
			dynamic_cast<PlayPG*>(juegootp->topEstado())->newBaja(this);
			dynamic_cast<PlayPG*>(juegootp->topEstado())->newPuntos(this);
		}
		return (dentro(mx, my));
	}
	else
		return false;
}

void Globo::update(){
	if (!explotado){//desactivar para evaluacion
		if (rand() % 100 >= PVIS)
			visible = true;
		else
			visible = false;

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

