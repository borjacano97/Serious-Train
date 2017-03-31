#include "Bala.h"


Bala::Bala(Game* juego, Game::Texturas_t text, float x, float y, int mira, Game::Bala_t b)
{
	juegootp = juego;
	Ttextura = text;

	tipo = b;
	switch (tipo)
	{
	case Game::BNormal:
		alto = 20;  // "Esto para probar, luego..."
		ancho = 20;
		vel = 0.5;
		break;
	case Game::BLaser:
		std::cout << "laser";
		alto = 1400; 
		ancho = 700;
		vel = 0;
		break;
	default:
		break;
	}
	
	pos.set(x, y);	
	
	dir = mira;

}


void Bala::update(Uint32 delta) {
	switch (tipo)
	{
	case Game::BNormal:
		pos.x += dir * vel*delta;

		if (pos.x <= 0 || pos.x >= 1300)
			destruido = true;
		break;
	case Game::BLaser:
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