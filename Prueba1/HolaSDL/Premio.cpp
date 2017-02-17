#include "Premio.h"
#include "Mariposa.h"
#include "PlayPG.h"


Premio::Premio(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y)
{
	Ttextura = text;

	juegootp = juego;

	pimgx = x;
	pimgy = y;

	alto = 150;
	ancho = 100;

	visible = false;
}


Premio::~Premio()
{
	
}



void Premio::draw(){ // igual que el draw de globos
	if (visible){
		rect.h = alto;
		rect.w = ancho;
		rect.x = pimgx;
		rect.y = pimgy;

		SDL_Renderer*render = juegootp->getRender();
		juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);
	}

}

bool Premio::onClick(){ // igual que el onclick de globos
	juegootp->getMousePos(mx, my);
	if (dentro(mx, my)){
		visible = false;
		dynamic_cast<PlayPG*>(juegootp->topEstado())->newPuntos(this);
	}

	return (dentro(mx, my));

}

void Premio::update(){ 

	if (visible == true && cont != 0){
		if (!onClick()){
			puntos -= 50; // cada vez que pase tiempo baja la puntuacion del premio
			cont--;
		}
		else{
			visible = false;
			dynamic_cast<PlayPG*>(juegootp->topEstado())->newPremio();
		}
	}
	else if (cont == 0){
		visible = false;
	
	}
}

void Premio::reiniciaPremio(){ 
	pimgx = rand() % 700;
	pimgy = rand() % 700;
	puntos = 200;
	cont = 3;
	visible = true;
}
