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
		vel = 0.08;
		velVertical = 0.035;
		break;
	case Game::Enemigo_t::Rapido:
		alto = 81;
		ancho = 74;
		anchoc = 444;
		Ttextura = Game::Texturas_t::TEnemigo;
		hp = 600;
		points = 10;
		vel = 0.2;
		velVertical = 0.015;
		break;
	case Game::Enemigo_t::Tank:
		Ttextura = Game::Texturas_t::TEnemigoG;
		hp = 5000;
		points = 25;
		vel = 0.05;
		//alto *= 1.5;
		velVertical = 0.02;
		break;
	case Game::Enemigo_t::Enano:
		Ttextura = Game::Texturas_t::TEnemigoD;
		hp = 1000;
		points = 10;
		vel = 0.1;
		velVertical = 0.004;
		break;
	case Game::Enemigo_t::Invisible:
		Ttextura = Game::Texturas_t::TInvisible;
		hp = 1500;
		points = 15;
		vel = 0.05;
		velVertical = 0.02;
		anchoc *= 3; // esto es lo que le hace invisible xd
		break;
	case Game::Enemigo_t::Slender:
		Ttextura = Game::Texturas_t::TSlender;
		hp = 5000;
		points = 200;
		vel = 0.01;
		velVertical = 0.004;
		break;
	case Game::Enemigo_t::Tocho:
		Ttextura = Game::Texturas_t::TTocho;
		hp = 6500;
		points = 30;
		vel = 0.07;
		velVertical = 0.02;
		break;
	default:
		break;
	}
	if (pos.x > 745) vel *=-1;//Programming God, please forgive us


	k = 0;
}

void Enemigo::update(Uint32 delta) {


		if (hp <= 0) destruido = true;
		j += delta;
		if (!parado) {
			pos.y -= (delta * velVertical); // hay que meter aqui la velocidad

			pos.x += vel*delta;//*dir //someday 
		}

		if (_clase == Game::Enemigo_t::Enano && pos.x <= 1000 && pos.x >= 200){
			shootTime += delta;
			if (shootTime >= 3000) {
				if (vel <=0) p->balas.emplace_back(new Bala(juegootp, p, pos.x, pos.y + 30, vel * 10, Game::Bala_t::BalaEnem));
				else p->balas.emplace_back(new Bala(juegootp, p, pos.x +25, pos.y + 30, vel * 10, Game::Bala_t::BalaEnem));
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
			if (!explotao){
				j = 0;
				Ttextura = Game::Texturas_t::TExplosion;
				explotao = true;
			}
			else {
				if (contExplo >= 100){
					p->TrainHp->damage(Game::EnemyDmg_t::Explosion);
					destruido = true;
					contExplo = 0;
				}
				else contExplo++;
			}
			
		}
		 if (j >= 100){
			i += ancho ;
			rectA.x = i;

			if (i >= Enemigo::anchoc) i = ancho;
			j = 0;
		}
		 // TEMPORIZADOR DEL CAMBIO DE COLOR DE LOS ENEMIGOS (FEEDBACK)
		 //·······
		 if (dañado){
			 if (k < 50) k ++;
			 else{
				 dañado = false;
				 k = 0;
			 }
		 }
		
		 //·······
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

	/*if (dañado)	{
			 
			 juegootp->getTextura(Ttextura)->setColor(240, 0, 0);

				 if (k < 100){
					 if (k == 99) Ttextura->set
						 juegootp->getTextura(Ttextura)->setColor(255, 255, 255);

					 k += delta;
					 dañado = false;
				 }
			 
		 }*/
	//SOLO CAMBIA EL COLOR DE LOS ENEMIGOS QUE SON GOLPEADOS
	//···············
	if (dañado){

		juegootp->getTextura(Ttextura)->setColor(240, 0, 0);
	}
	else
	{
		juegootp->getTextura(Ttextura)->setColor(255, 255, 255);
	}
	//···············

	SDL_Renderer* render = juegootp->getRender();
	if (rect.x < 640) {
		juegootp->getTextura(Ttextura)->draw(render, &rectA, &rect);
	}
	else if (rect.x > 640) {
		juegootp->getTextura(Ttextura)->drawInvertido(render, &rectA, &rect);
	}

}