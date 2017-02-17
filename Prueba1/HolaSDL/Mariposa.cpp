#include "Mariposa.h"
#include "Premio.h"
#include "PlayPG.h"


Mariposa::Mariposa(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y)
{
	Ttextura = text;

	juegootp = juego;

	ancho = 269 / 6;
	alto = 59;

	cont = 0;

	pimgx = x;
	pimgy = y;
	
}


Mariposa::~Mariposa()
{
	
}


void Mariposa::draw(){ //igual que el draw de globos
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;

	
	rectA.h = alto;
	rectA.w = ancho;
	rectA.x = i;
	rectA.y = 0;

	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, &rectA, &rect);

	
}

bool Mariposa::onClick(){ //igual que el onClick de globos pero con los datos de la mariposa
	juegootp->getMousePos(mx, my);
	if (dentro(mx, my)){
		cont++;
		pimgx = rand() % 700;
		pimgy = rand() % 700;
	}
	return (dentro(mx, my));

}

void Mariposa::update(){ //aquí localizamos el contador para que si se ha pinchado 3 veces cree un premio

	//utilizo una var auxiliar para ir avanzando en la imagen y crear movimiento 
	i += ancho;
	rectA.x = i;

	if (cont == 3){
		dynamic_cast<PlayPG*>(juegootp->topEstado())->newPremio();
		cont = 0;
	}

	if (i > 234){ 
		i = 0;
	}

}
