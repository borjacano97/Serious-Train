#include "Bala.h"
#include "Play.h"

Bala::Bala(Game* juego, Game::Texturas_t text, float x, float y, int mira, Game::Bala_t b)
{
	juegootp = juego;
	Ttextura = text;

	tipo = b;
	switch (tipo)
	{
	case Game::Piedra:
		alto = 20;  // "Esto para probar, luego..."
		ancho = 20;
		vel = 0.5;
		break;
	case Game::Rayo:
		alto = 1400; 
		ancho = 700;
		vel = 0;		
	default:
		break;
	}
	
	pos.set(x, y);	
	
	dir = mira;
}


void Bala::update(Uint32 delta) {
	switch (tipo)
	{
	case Game::Piedra:
		pos.x += dir * vel*delta;

		if (pos.x <= 0 || pos.x >= 1300)
			destruido = true;
		break;
	case Game::Rayo:
		if (alto > 0){
			alto-=2;
			pos.y++;
		}
		else destruido = true;
		break;
	default:
		break;
	}	
}
