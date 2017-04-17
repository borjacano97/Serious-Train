#include "Bala.h"
#include "Play.h"

Bala::Bala(Game* juego, Play*pl, Game::Texturas_t text, float x, float y, int mira, Game::Bala_t b)
{
	juegootp = juego;
	Ttextura = text;

	tipo = b;
	pos.set(x, y);

	dir = mira;
	p = pl;
	switch (tipo)
	{
	case Game::Piedra:
		alto = 20; 
		ancho = 20;
		vel = 0.5;
		dmg = 50;
		break;
	case Game::Rayo:
		alto = 1400;
		ancho = 700;
		vel = 0;
		break;
	case Game::Fuego:
		alto = 100;
		ancho = 100;
		vel = 0;
		dmg = 1;
		break;
	default:
		break;
	}

	
}


void Bala::update(Uint32 delta) {
	switch (tipo)
	{
	case Game::Piedra:
		pos.x += dir * vel*delta;

		if (pos.x <= 0 || pos.x >= 1300)
			destruido = true;
		for each (auto var in p->enems)
		{
			if (var != nullptr && var->collision(this)) {
				var->damage(dmg);
				destruido = true;
			}
		}
		break;
	case Game::Rayo:
		if (alto > 0) {
			alto -= 2;
			pos.y++;
		}
		else destruido = true;
		break;
	case Game::Fuego:
		cont++;
		if (cont %2 ==0) ancho -= 5;
		else ancho += 5;
		for each (auto var in p->enems)
		{
			if (var != nullptr &&  var->collision(this)) var->damage(dmg);
			
		}

		if (cont >= 1000) destruido = true;
		break;
	default:
		break;
	}
}