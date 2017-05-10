#include "Hud.h"
#include "Play.h"

Hud::Hud(Game* juego, Play* pl, float x, float y, Game::Hud_t t)
{
	juegootp = juego;
	pos.set(x, y);

	tipo = t;
	p = pl;
	switch (tipo)
	{
	case Game::Tick:
		alto = 130;
		ancho = 95; 
		Ttextura = Game::Texturas_t::TTick;
		break;
	case Game::Hud1:

		if (!juegootp->bigHP){
			alto = 230;
			ancho = 550;
			Ttextura = Game::Texturas_t::THud;
		}
		else {
			alto = 200;
			ancho = 500;
			pos.y += 13;
			pos.x += 30;
			Ttextura = Game::Texturas_t::THud2;
		}		
		break;
	case Game::Trayecto:
		alto = 400;
		ancho = 70;
		Ttextura = Game::Texturas_t::TTrayecto;
		break;
	case Game::Tren:
		alto = 50;
		ancho = 30;
		Ttextura = Game::Texturas_t::TLocomotora;
		break;
	default:
		break;
	}	
}

void Hud::update(Uint32 delta){
	pos.y = 280 - ((230 / p->emax) *p->getKilled());
}