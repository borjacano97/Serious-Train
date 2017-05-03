#include "Bala.h"
#include "Play.h"

Bala::Bala(Game* juego, Play*pl, float x, float y, int mira, Game::Bala_t b)
{
	juegootp = juego;

	tipo = b;
	pos.set(x, y);

	dir = mira;
	p = pl;
	switch (tipo)//Cambiar las texturas cuando estes implementadas
	{
	case Game::BalaEnem:
		alto = 20;
		ancho = 20;
		vel = 0.3;
		Ttextura = Game::Texturas_t::TRoca;
		break;
	case Game::Piedra:
		alto = 20; 
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		Ttextura = Game::Texturas_t::TRoca;
		break;
	case Game::Rayo:
		alto = 1400;
		ancho = 700;
		vel = 0;
		Ttextura = Game::Texturas_t::TLaser;
		break;
	case Game::Fuego:
		alto = 120;
		ancho = 120;
		vel = 0;
		dmg = 5;
		if (x <= 600) Ttextura = Game::Texturas_t::TFuegoi;
		else Ttextura = Game::Texturas_t::TFuegod;
		break;
	case Game::Escopeta:
		alto = 20;
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		Ttextura = Game::Texturas_t::TBala;
		p->balas.emplace_back(new Bala(juegootp, p, p->player->getPos().x, p->player->getPos().y, p->player->getMira(), Game::Bala_t::E1));
		p->balas.emplace_back(new Bala(juegootp, p, p->player->getPos().x, p->player->getPos().y, p->player->getMira(), Game::Bala_t::E2));
		break;
	case Game::E1: // digamos que son balas auxiliares de la escopeta xd
		alto = 20;
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		Ttextura = Game::Texturas_t::TBala;
		break;
	case Game::E2:
		alto = 20;
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		Ttextura = Game::Texturas_t::TBala;
		break;	
	case Game::Pistola:
		alto = 20;
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		Ttextura = Game::Texturas_t::TBala;
		break;
	case Game::Sniper:
		alto = 20;
		ancho = 40;
		vel = 0.8;
		dmg = 150; // no nos habiamos dado cuenta que como la bala no se destruye en el franco colisiona varias veces con el enemigo
		          // por eso hay que poner menor damage que si no es insta kill hasta pa los bosses xd
		Ttextura = Game::Texturas_t::TBala;
		break;
	case Game::Metralleta:
		alto = 20;
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		Ttextura = Game::Texturas_t::TBala;
		break;
	case Game::Minigun:
		alto = 20;
		ancho = 20;
		vel = 0.6;
		dmg = 200;
		Ttextura = Game::Texturas_t::TBala;
		break;
	default:
		break;
	}	
}


void Bala::update(Uint32 delta) {
	switch (tipo)
	{
	case Game::BalaEnem:
		pos.x += dir * vel*delta;
		if (p->tg->collision(this)) {
			p->TrainHp->move('b');
			destruido = true;
		}
		break;
	case Game::Piedra:
		pos.x += dir * vel*delta;

		if (pos.x <= 450 || pos.x >= 850)
			destruido = true;
		for each (auto var in p->enems)
		{
			if (var != nullptr && var->collision(this)) {
				var->damage(dmg);
				destruido = true;
			}
		}
		break;
	case Game::Rayo:
		if (alto > 0) {
			alto -= delta;
			pos.y+= delta*0.5;
		}
		else destruido = true;
		break;
	case Game::Fuego:
		cont ++;
		if (cont %2 ==0) ancho -= 5;
		else ancho += 5;
		for each (auto var in p->enems)
		{
			if (var != nullptr &&  this->collision(var) || var != nullptr && var->collision(this)) var->damage(dmg);
						
		}

		if (cont >= 1000) destruido = true;
		break;
	case Game::Escopeta:
		pos.x += dir * vel*delta;
		pos.y += dir*vel*delta / 2;
		if (pos.x <= 450 || pos.x >= 850)
			destruido = true;
		for each (auto var in p->enems)
		{
			if (var != nullptr && var->collision(this)) {
				var->damage(dmg);
				destruido = true;
			}
		}
		break;
	case Game::E1:
		pos.x += dir * vel*delta;

		if (pos.x <= 450 || pos.x >= 850)
			destruido = true;
		for each (auto var in p->enems)
		{
			if (var != nullptr && var->collision(this)) {
				var->damage(dmg);
				destruido = true;
			}
		}
		break;
	case Game::E2:
		pos.x += dir * vel*delta;
		pos.y -= dir*vel*delta / 2;
		if (pos.x <= 450 || pos.x >= 850)
			destruido = true;
		for each (auto var in p->enems)
		{
			if (var != nullptr && var->collision(this)) {
				var->damage(dmg);
				destruido = true;
			}
		}
		break;
	case Game::Pistola:
		pos.x += dir * vel*delta;
		if (pos.x <= 0 || pos.x >= 1500)
			destruido = true;
		for each (auto var in p->enems)
		{
			if (var != nullptr && var->collision(this)) {
				var->damage(dmg);
				destruido = true;
			}
		}
		break;
	case Game::Sniper:
		pos.x += dir * vel*delta;
		if (pos.x <= 0 || pos.x >= 1500)
			destruido = true;
		for each (auto var in p->enems)
		{
			if (var != nullptr && var->collision(this)) {
				var->damage(dmg);
			}
		}
		break;
	case Game::Metralleta:
		pos.x += dir * vel*delta;
		if (pos.x <= 0 || pos.x >= 1500)
			destruido = true;
		for each (auto var in p->enems)
		{
			if (var != nullptr && var->collision(this)) {
				var->damage(dmg);
				destruido = true;
			}
		}
		break;
	case Game::Minigun:
		pos.x += dir * vel*delta;
		if (pos.x <= 0 || pos.x >= 1500)
			destruido = true;
		for each (auto var in p->enems)
		{
			if (var != nullptr && var->collision(this)) {
				var->damage(dmg);
				destruido = true;
			}
		}
		break;
	default:
		break;
	}
}