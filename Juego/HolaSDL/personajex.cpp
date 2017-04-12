#include "Personaje.h"
#include "Bala.h"



Personaje::Personaje(Game* juego, Game::Texturas_t text, float x, float y)
{
	juegootp = juego;
	Ttextura = text;

	alto = 46;
	ancho = 32;
	pos.set(x, y);

	dir.x = 0;
	dir.y = 0;
	mira = 1;
	vel = 0.5;
}
void Personaje::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pos.x;
	rect.y = pos.y;
	

	//Rectangulo que recorre el sprite
	srcR.w = ancho;
	srcR.h = alto;


	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, &srcR, &rect);

}
void Personaje::update(Uint32 delta) {
	pos.x += dir.x*vel*delta;
	pos.y += dir.y*vel*delta;
	if (pos.x < 600)
		pos.x = 600;
	else if (pos.x > 650)
		pos.x = 650;
	if (pos.y < 130)
		pos.y = 130;
	else if (pos.y > 650)
		pos.y = 650;
}

void Personaje::move(char c) {

	switch (c) {
	case 'W':
		dir.y = -1;
		//Coloca al jugador en la fila del spritesheet de la animación de avanzar hacia arriba
		srcR.y = 187;
		//Recorre esa animacion y la reinicia al acabar
		if (srcR.x < 65) {
			srcR.x += ancho;
		}
		else {
			srcR.x = 0;
		}
		break;
	case 'S':
		dir.y = 1;
		//Coloca al jugador en la fila del spritesheet de la animación de avanzar hacia arriba
		srcR.y = 0;
		//Recorre esa animacion y la reinicia al acabar
		if (srcR.x < 65) {
			srcR.x += ancho;
		}
		else {
			srcR.x = 0;
		}
		break;
	case 'A':
		mira = -1;
		dir.x = -1;
		//Coloca al jugador en la fila del spritesheet de la animación de avanzar hacia arriba
		srcR.y = 124;
		//Recorre esa animacion y la reinicia al acabar
		if (srcR.x < 65) {
			srcR.x += ancho;
		}
		else {
			srcR.x = 0;
		}
		break;
	case 'D':
		mira = 1;
		dir.x = 1;
		//Coloca al jugador en la fila del spritesheet de la animación de avanzar hacia arriba
		srcR.y = 62;
		//Recorre esa animacion y la reinicia al acabar
		if (srcR.x < 65) {
			srcR.x += ancho;
		}
		else {
			srcR.x = 0;
		}
		break;
	default:
		dir.x = 0;
		dir.y = 0;
		if (srcR.y == 124) {
			srcR.x = 32;
		}
		else srcR.x = 0;
		
		break;
	}
}