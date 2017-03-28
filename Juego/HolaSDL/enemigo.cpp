#include "Enemigo.h"
#include "Estado.h"
#include "Game.h"

Enemigo::Enemigo(Game* juego, Game::Texturas_t text, float x, float y, Game::Enemigo_t clase)
{
	juegootp = juego;
	Ttextura = text;

	alto = 50;
	ancho = 50;

	pos.set(x, y);

	_clase = clase;
	switch (_clase)
	{
	case Game::Enemigo_t::ENormal:
		points = 5;
		vel = 0.1;
		break;
	case Game::Enemigo_t::ERapido:
		points = 10;
		vel = 0.3;
		break;
	default:
		break;
	}
	if (pos.x > 745) vel *=-1;//Programming God, please forgive us
}

void Enemigo::update(Uint32 delta) {


	pos.x += vel*delta;//*dir //someday 
    //me pone que puede haber perdida de datos porque vel es float y lo demas int xd
}


