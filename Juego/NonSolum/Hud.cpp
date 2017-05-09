#include "Hud.h"


Hud::Hud(Game* juego, float x, float y, Game::Hud_t t)
{
	juegootp = juego;
	pos.set(x, y);

	tipo = t;

	switch (tipo)
	{
	case Game::Tick:
		alto = 130;
		ancho = 95; 
		Ttextura = Game::Texturas_t::TTick;
		break;
	case Game::Hud1:
		alto = 230;
		ancho = 550;
		Ttextura = Game::Texturas_t::THud;
		break;
	case Game::Trayecto:
		break;
	case Game::Cuadrado:
		break;
	default:
		break;
	}

	
}

