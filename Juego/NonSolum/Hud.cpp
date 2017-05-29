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
		case Game::Pause:Ttextura = Game::Texturas_t::TPausa;
			break;
		case Game::Historia1:

			switch (juegootp->getNivel())
			{
			case 1:Ttextura = Game::Texturas_t::THistoria1;
				break;
			case 4:Ttextura = Game::Texturas_t::THistoria2;
				break;
			case 7:Ttextura = Game::Texturas_t::THistoria3;
				break;
			case 10:Ttextura = Game::Texturas_t::THistoria4;
				break;
			case 13:Ttextura = Game::Texturas_t::THistoria5;
				break;
			default:
				break;
			}
			
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
	case Game::Logo:
		Ttextura = Game::Texturas_t::TLogo;
		alto = 1;
		ancho = 1;
		break;
	case Game::Sangre:
		Ttextura = Game::Texturas_t::TSangre;
		alto = 400;
		ancho = 600;
		break;
	case Game::LetrasHist:
		alto = 500;
		ancho = 1000;
		switch (juegootp->getNivel())
		{
		case 1:
			if (juegootp->spanish) Ttextura = Game::Texturas_t::THistEsp1;
			else Ttextura = Game::Texturas_t::THistEng1;
			break;
		case 4:
			if (juegootp->spanish) Ttextura = Game::Texturas_t::THistEsp2;
			else Ttextura = Game::Texturas_t::THistEng2;
			break;
		case 7:
			if (juegootp->spanish) Ttextura = Game::Texturas_t::THistEsp3;
			else Ttextura = Game::Texturas_t::THistEng3;
			break;
		case 10:
			if (juegootp->spanish) Ttextura = Game::Texturas_t::THistEsp4;
			else Ttextura = Game::Texturas_t::THistEng4;
			break;
		case 13:
			if (juegootp->spanish) Ttextura = Game::Texturas_t::THistEsp5;
			else Ttextura = Game::Texturas_t::THistEng5;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}	
}

void Hud::update(Uint32 delta) {
	switch (tipo)
	{
	case Game::Tren: pos.y = 280 - ((230 / p->emax) *p->getKilled());
		break;
	case Game::Logo: 
		if (alto <= 150) {
			if (cont >= 25) {
				alto++;
				ancho += 2;

				pos.y--;
				pos.x--;
				cont = 0;
			}
			else cont += delta;
		}		
		break;
	case Game::LetrasHist: 

		if (pos.y >= 200 && cont>=15) {
			pos.y--;
			cont = 0;
		}
		else cont += delta;
		break;
	default:
		break;
	}
}
	
	