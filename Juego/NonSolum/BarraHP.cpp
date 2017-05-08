#include "BarraHP.h"



barraHP::barraHP(Game* juego, Game::Texturas_t text, float x, float y)
{
	juegootp = juego;
	Ttextura = text;

	alto = 50;
	ancho = 200 ;

	pos.set(x, y);

	cont = 0;
}


void barraHP::update(Uint32 delta) {
	d = delta;
	if (ancho <= 0) destruido = true;
}
void barraHP::damage(Game::EnemyDmg_t dm) {

	
	if (dm == Game::Simple) {
		cont += d;
		if (cont >= 100) {
			cont = 0;
			ancho--;
		}
	}
	 if ( dm == Game::Explosion)ancho -= 50;
	else if (dm == Game::Bala) ancho -= 10;	
}
