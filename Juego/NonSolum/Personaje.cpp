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
	if (pos.x < 590)
		pos.x = 590;
	else if (pos.x > 660)
		pos.x = 660;
	if (pos.y < 110)
		pos.y = 110;
	else if (pos.y > 650)
		pos.y = 650;
}

void Personaje::move(HorizontalMov_t dirH, VerticalMov_t dirV) {
	/*dir.x = dirH;
	dir.y = dirV;
	*/
	switch (dirH)
	{
	case Personaje::LEFT:
		dir.x = -1;
		break;
	case Personaje::STOP_h:
		dir.x = 0;
		break;
	case Personaje::RIGHT:
		dir.x = 1;
		break;
	default:
		break;
	}
	switch (dirV)
	{
	case Personaje::UP:
		dir.y = 1;
		break;
	case Personaje::STOP_v:
		dir.y = 0;
		break;
	case Personaje::DOWN:
		dir.y = -1;
		break;
	default:
		break;
	}
}