#include "Enemigo.h"
#include "Estado.h"
#include "Game.h"

Enemigo::Enemigo(Game* juego, Game::Texturas_t text, float x, float y, Game::Enemigo_t clase)
{
	juegootp = juego;
	Ttextura = text;

	alto = 80;
	anchoc = 342;
	ancho = anchoc / 6;

	pos.set(x, y);

	_clase = clase;
	switch (_clase)
	{
	case Game::Enemigo_t::Normal:
		points = 5;
		vel = 0.1;
		break;
	case Game::Enemigo_t::Rapido:
		points = 10;
		vel = 0.3;
		break;
	default:
		break;
	}
	if (pos.x > 745) vel *=-1;//Programming God, please forgive us
}

void Enemigo::update(Uint32 delta) {
	
	j += delta;
	if (j >= 150) {
		i += ancho;
		rectA.x = i;

		if (i >= Enemigo::anchoc) i = ancho;
		j = 0;
	}
	if (!parado) {
		pos.y += (delta / 4) + 0.050;

		pos.x += vel*delta;//*dir //someday 
						   //me pone que puede haber perdida de datos porque vel es float y lo demas int xd
		
	}
}
void Enemigo::draw() {

	rect.h = alto;
	rect.w = ancho;
	rect.x = pos.x;
	rect.y = pos.y;

	rectA.h = alto;
	rectA.w = ancho;
	rectA.x = i;
	rectA.y = 0;


	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, &rectA, &rect);




}


