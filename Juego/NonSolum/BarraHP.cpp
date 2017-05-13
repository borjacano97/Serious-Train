#include "BarraHP.h"



barraHP::barraHP(Game* juego, Game::Texturas_t text, float x, float y)
{
	juegootp = juego;
	Ttextura = text;

	alto = 12;
	ancho = 270 ;

	pos.set(x, y);

	contDmg = 0;
	contGive = 0;

	maxHP = 360;
}


void barraHP::update(Uint32 delta) {
	d = delta;
	if (ancho <= 0) destruido = true;
}
void barraHP::damage(Game::EnemyDmg_t dm) {

	
	if (dm == Game::Simple) {
		contDmg += d;
		if (contDmg >= 100) {
			contDmg = 0;
			ancho--;
		}
	}
	 if ( dm == Game::Explosion)ancho -= 50;
	else if (dm == Game::Bala) ancho -= 10;	
}
void barraHP::giveHP(int i){

	if (i == 1){
		contGive += d;
		if (contGive >= 200) {
			contGive = 0;
			if (ancho<=maxHP) ancho ++;
		}
	}
	else ancho += i;
}