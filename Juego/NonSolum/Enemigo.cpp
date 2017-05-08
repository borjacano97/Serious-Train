#include "Enemigo.h"
#include "Estado.h"
#include "Game.h"
#include "Play.h"

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
		alto = 81;
		ancho = 74;
		anchoc = 444;
		Ttextura = Game::Texturas_t::TEnemigo;
		hp = 600;
		points = 10;
		vel = 0.3;
		break;
	case Game::Enemigo_t::Tank:
		Ttextura = Game::Texturas_t::TEnemigoG;
		hp = 5000;
		points = 50;
		vel = 0.05;
		alto *= 1.5;
		break;
	case Game::Enemigo_t::Enano:
		Ttextura = Game::Texturas_t::TEnemigoD;
		hp = 1000;
		points = 15;
		vel = 0.1;
		break;
	case Game::Enemigo_t::Invisible:
		Ttextura = Game::Texturas_t::TEnemigo2;
		hp = 1500;
		points = 25;
		vel = 0.1;
		anchoc *= 3;
		break;
	case Game::Enemigo_t::Slender:
		Ttextura = Game::Texturas_t::TEnemigo2;
		hp = 5000;
		points = 200;
		vel = 0.01;
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
			pos.y -= (delta *0.04); // hay que meter aqui la velocidad

			pos.x += vel*delta;//*dir //someday 
		}

		if (_clase == Game::Enemigo_t::Enano && pos.x <= 1100 && pos.x >= 100){
			shootTime += delta;
			if (shootTime >= 3000) {
				p->balas.emplace_back(new Bala(juegootp, p, pos.x, pos.y + 30, vel * 10, Game::Bala_t::BalaEnem));
				shootTime = 0;
			}
			
			parado = true;
		}
		else if (_clase == Game::Enemigo_t::Slender && pos.x <= 1150 && pos.x >= 50) {
			
			parado = true;
			disappearTime += delta;
			if (disappearTime >= 10000) {
				points = 0;
				destruido = true;
			}
		}
		else if (_clase == Game::Enemigo_t::Tank && p->tg->collision(this)) {
			points = 0;
			p->TrainHp->damage(Game::EnemyDmg_t::Explosion);
			destruido = true;
		
		}
		 if (j >= 150){
			i += ancho;
			rectA.x = i;

			if (i >= anchoc) i = ancho;
			j = 0;
		}

}
void Enemigo::draw() {

	
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


