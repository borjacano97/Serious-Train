#include "Personaje.h"
#include "Bala.h"



Personaje::Personaje(Game* juego, Game::Texturas_t text, int x, int y)
{
	juegootp = juego;
	Ttextura = text;

	alto = 46;
	ancho = 32;

	pimgx = x;
	pimgy = y;

	dir.x = 0;
	dir.y = 0;
	mira = 1;
	vel = 1;
}


Personaje::~Personaje()
{
}

void Personaje::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;

	//Rectangulo que recorre el sprite
	SrcR.w = ancho;
	SrcR.h = alto;


	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, &SrcR, &rect);

}


void Personaje::update(Uint32 delta) {
	pos.x += dir.x*vel*delta;
	pos.y += dir.y*vel*delta;
	if (pos.x < 550)
		pos.x = 550;
	else if (pos.x > 640)
		pos.x = 640;
	if (pos.y < 60)
		pos.y = 60;
	else if (pos.y > 1000)
		pos.y = 1000;
}

bool Personaje::onClick() {
	return true;
}
void Personaje::move(char c) {
	if (c == 'W') {
		dir.y = -1;
		//Coloca al jugador en la fila del spritesheet de la animación de avanzar hacia arriba
		SrcR.y = 187;
		//Recorre esa animacion y la reinicia al acabar
		if (SrcR.x < 65) {
			SrcR.x += ancho;
		}
		else {
			SrcR.x = 0;
		}
	}
	else if (c == 'S') {
		dir.y = 1;
		//Coloca al jugador en la fila del spritesheet de la animación de avanzar hacia abajo
		SrcR.y = 0;
		//Recorre esa animacion y la reinicia al acabar
		if (SrcR.x < 65) {
			SrcR.x += ancho;
		}
		else {
			SrcR.x = 0;
		}
	}
	if (c == 'A') {
		mira = -1;
		dir.x = -1;
		//Coloca al jugador en la fila del spritesheet de la animación de avanzar hacia la izquierda
		SrcR.y = 124;
		//Recorre esa animacion y la reinicia al acabar
		if (SrcR.x < 65) {
			SrcR.x += ancho;
		}
		else {
			SrcR.x = 0;

		}
	}
	else if (c == 'D') {
		mira = 1;
		dir.x = 1;
		//Coloca al jugador en la fila del spritesheet de la animación de avanzar hacia la derecha
		SrcR.y = 62;
		//Recorre esa animacion y la reinicia al acabar
		if (SrcR.x < 65) {
			SrcR.x += ancho;
		}
		else {
			SrcR.x = 0;
		}
	}
	//else SrcR.x = 32;

	if (c == 'N') {
		dir.x = 0;
		dir.y = 0;
	}

}