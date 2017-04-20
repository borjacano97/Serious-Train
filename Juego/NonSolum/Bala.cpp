#include "Bala.h"
#include "Play.h"

Bala::Bala(Game* juego, Play*pl, Game::Texturas_t text, float x, float y, int mira, Game::Bala_t b)
{
	juegootp = juego;
	Ttextura = text;

	tipo = b;
	pos.set(x, y);

	dir = mira;
	p = pl;
	switch (tipo)
	{
	case Game::BalaEnem:
		alto = 20;
		ancho = 20;
		vel = 0.5;
		break;
	case Game::Piedra:
		alto = 20; 
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		break;
	case Game::Rayo:
		alto = 1400;
		ancho = 700;
		vel = 0;
		break;
	case Game::Fuego:
		alto = 100;
		ancho = 100;
		vel = 0;
		dmg = 1;
		break;
	case Game::Escopeta:
		alto = 20;
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		p->balas.emplace_back(new Bala(juegootp, p, Game::TRoca, p->player->getPos().x, p->player->getPos().y, p->player->getMira(), Game::Bala_t::E1));
		p->balas.emplace_back(new Bala(juegootp, p, Game::TRoca, p->player->getPos().x, p->player->getPos().y, p->player->getMira(), Game::Bala_t::E2));
		break;
	case Game::E1: // digamos que son balas auxiliares de la escopeta xd
		alto = 20;
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		break;
	case Game::E2:
		alto = 20;
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		break;	
	case Game::Pistola:
		alto = 20;
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		break;
	case Game::Sniper:
		alto = 14;
		ancho = 14;
		vel = 0.7;
		dmg = 1000;
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
			alto -= 2;
			pos.y++;
		}
		else destruido = true;
		break;
	case Game::Fuego:
		cont++;
		if (cont %2 ==0) ancho -= 5;
		else ancho += 5;
		for each (auto var in p->enems)
		{
			if (var != nullptr &&  var->collision(this)) var->damage(dmg);
			
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
	default:
		break;
	}
}