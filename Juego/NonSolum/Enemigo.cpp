#include "Enemigo.h"
#include "Estado.h"
#include "Game.h"

Enemigo::Enemigo(Game* juego, Play* pl, float x, float y, Game::Enemigo_t clase)
{
	juegootp = juego;
	p = pl;

	alto = 80;
	anchoc = 342;
	ancho = anchoc / 6;

	pos.set(x, y);

	_clase = clase;
	switch (_clase)
	{
	case Game::Enemigo_t::Normal:
		Ttextura = Game::Texturas_t::TEnemigo2;
		hp = 1000;
		points = 5;
		vel = 0.1;
		break;
	case Game::Enemigo_t::Rapido:
		Ttextura = Game::Texturas_t::TEnemigo;
		hp = 500;
		points = 10;
		vel = 0.3;
		break;
	case Game::Enemigo_t::Tank:
		Ttextura = Game::Texturas_t::TEnemigo2;
		hp = 5000;
		points = 50;
		vel = 0.05;
		break;
	case Game::Enemigo_t::ElQueDispara:
		Ttextura = Game::Texturas_t::TEnemigo2;
		hp = 1000;
		points = 15;
		vel = 0.1;
		break;
	default:
		break;
	}
	if (pos.x > 745) vel *=-1;//Programming God, please forgive us
}

void Enemigo::update(Uint32 delta) {


		if (hp <= 0) destruido = true;
		j += delta;
		if (!parado) {
			pos.y -= delta *0.04;

			pos.x += vel*delta;//*dir //someday 
		}

		if (_clase == Game::Enemigo_t::ElQueDispara && pos.x <= 1100 && pos.x >= 100){
			if (disparo == nullptr)  disparo = new Bala(juegootp, p, pos.x, pos.y, vel * 10, Game::Bala_t::BalaEnem);
			else if ( disparo->getDest()) {
				delete disparo;
				disparo = nullptr;
			}
			else disparo->update(delta);
			 
			parado = true;
		}
		else if (j >= 150){
			i += ancho;
			rectA.x = i;

			if (i >= Enemigo::anchoc) i = ancho;
			j = 0;
		}

}
void Enemigo::draw() {

	if (disparo != nullptr) disparo->draw();
	rect.h = alto;
	rect.w = ancho;
	rect.x = pos.x;
	rect.y = pos.y;

	rectA.h = alto;
	rectA.w = ancho;
	rectA.x = i;
	rectA.y = 0;


	SDL_Renderer* render = juegootp->getRender();
	if (rect.x < 640) {
		juegootp->getTextura(Ttextura)->draw(render, &rectA, &rect);
	}
	else if (rect.x > 640) {
		juegootp->getTextura(Ttextura)->drawInvertido(render, &rectA, &rect);
	}
}


