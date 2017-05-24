#include "Hud.h"
#include "Play.h"

Hud::Hud(Game* juego, Play* pl, float x, float y, Game::Hud_t t, Game::Fondo_t f)
{
	juegootp = juego;
	pos.set(x, y);

	tipo = t;
	fondo = f;
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
	case Game::Fondo:
		alto = 720;
		ancho = 1280;
		switch (fondo)
		{
		case Game::Control:Ttextura = Game::Texturas_t::TControlEsp;
			break;
		case Game::MenuP:Ttextura = Game::Texturas_t::TMenuP;
			break;
		case Game::Win:Ttextura = Game::Texturas_t::TWin;
			break;
		case Game::Lose:Ttextura = Game::Texturas_t::TLose;
			break;
		case Game::Tienda:Ttextura = Game::Texturas_t::TFondoT;
			break;
		case Game::FondoInicio:Ttextura = Game::Texturas_t::TFondoIni;
			break;
		default:
			break;
		}
		break;
	case Game::BotonOsc:
		Ttextura = Game::Texturas_t::TBotonOsc;
		alto = 90;
		ancho = 200;
		break;
	default:
		break;
	}	
}

void Hud::update(Uint32 delta){
	pos.y = 280 - ((230 / p->emax) *p->getKilled());
}