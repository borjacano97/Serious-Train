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
	case Game::BalaEnemGorda:
		alto = 55;
		ancho = 55;
		vel = 0.4;
		Ttextura = Game::Texturas_t::TRoca;
		contBalaBoss = 0;
		break;
	case Game::Piedra:
		alto = 20; 
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		Ttextura = Game::Texturas_t::TRoca;
		juego->sound->playEffect("../sounds/stoneEffect.mp3", 0, 5, 3);
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
		//juego->sound->playEffect("../sounds/flameEffect.mp3", 0, 250, 3); queda fatal xd
		break;
	case Game::Escopeta:
		alto = 20;
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		if (!juegootp->survival && ((juegootp->getNivel() - 1) / 3) == 2 ) Ttextura = Game::Texturas_t::TBala2;
		else Ttextura = Game::Texturas_t::TBala;
		p->balas.emplace_back(new Bala(juegootp, p, p->player->getPos().x, p->player->getPos().y, p->player->getMira(), Game::Bala_t::E1));
		p->balas.emplace_back(new Bala(juegootp, p, p->player->getPos().x, p->player->getPos().y, p->player->getMira(), Game::Bala_t::E2));
		juego->sound->playEffect("../sounds/shotgunEffect.mp3", 0, 6, 3);
		break;
	case Game::E1: // digamos que son balas auxiliares de la escopeta xd
		alto = 20;
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		if (!juegootp->survival && (juegootp->getNivel() <= 10) && (juegootp->getNivel() >= 7)) Ttextura = Game::Texturas_t::TBala2;
		else Ttextura = Game::Texturas_t::TBala;
		break;
	case Game::E2:
		alto = 20;
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		if (!juegootp->survival && (juegootp->getNivel() <= 10) && (juegootp->getNivel() >= 7)) Ttextura = Game::Texturas_t::TBala2;
		else Ttextura = Game::Texturas_t::TBala;
		break;	
	case Game::Pistola:
		alto = 20;
		ancho = 20;
		vel = 0.5;
		dmg = 500;
		if (!juegootp->survival && (juegootp->getNivel() <= 10) && (juegootp->getNivel() >= 7)) Ttextura = Game::Texturas_t::TBala2;
		else Ttextura = Game::Texturas_t::TBala;
		juego->sound->playEffect("../sounds/revolverEffect.mp3", 0, 10, 3);
		break;
	case Game::Sniper:
		alto = 20;
		ancho = 40;
		vel = 0.8;
		dmg = 1500; 
		if (!juegootp->survival && (juegootp->getNivel() <= 10) && (juegootp->getNivel() >= 7)) Ttextura = Game::Texturas_t::TBala2;
		else Ttextura = Game::Texturas_t::TBala;
		juego->sound->playEffect("../sounds/rifleEffect.mp3", 0, 20, 3);
		break;
	case Game::Metralleta:
		alto = 20;
		ancho = 20;
		vel = 0.5;
		dmg = 300;
		if (!juegootp->survival && (juegootp->getNivel() <= 10) && (juegootp->getNivel() >= 7)) Ttextura = Game::Texturas_t::TBala2;
		else Ttextura = Game::Texturas_t::TBala;
		juego->sound->playEffect("../sounds/rifleEffect.mp3", 0, 20, 3);
		break;
	case Game::Minigun:
		alto = 20;
		ancho = 20;
		vel = 0.6;
		dmg = 200;
		if (!juegootp->survival && (juegootp->getNivel() <= 10) && (juegootp->getNivel() >= 7)) Ttextura = Game::Texturas_t::TBala2;
		else Ttextura = Game::Texturas_t::TBala;
		juego->sound->playEffect("../sounds/miniGunEffect.mp3", 0, 10, 3);
		break;
	case Game::Canon:
		alto = 70;
		ancho = 70;
		vel = 1;
		dmg = 3000;
		Ttextura = Game::Texturas_t::TRoca;
		juego->sound->playEffect("../sounds/rifleEffect.mp3", 0, 20, 3);
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
			p->TrainHp->damage(Game::EnemyDmg_t::Bala);
			destruido = true;
		}
		for each (auto b in p->balas)
		{
			if (b != nullptr && this->collision(b)) {
				destruido = true;
				if ((b->tipo != Game::Bala_t::Sniper) && (b->tipo != Game::Bala_t::Canon)) b->destroy();
			}
		}
		break;
	case Game::BalaEnemGorda:
		pos.x += dir * vel*delta;
		if (p->tg->collision(this)) {
			p->TrainHp->damage(Game::EnemyDmg_t::Explosion);
			destruido = true;
		}
		for each (auto b in p->balas)
		{
			if (b != nullptr && this->collision(b)){
				if (contBalaBoss >= 5) destruido = true;
				else contBalaBoss++;

				b->destroy();
			}
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
			pos.y -= 30;
			ancho += 10;
			if (var != nullptr &&  this->collision(var) || var != nullptr && var->collision(this)) var->damage(dmg);
			pos.y += 30;
			ancho -= 10;
		}

		if (cont >= 1000 || p->tren[1]->roto) destruido = true;
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
			if (var != nullptr  &&  var->collision(this)) {
				if ((lastEnemy != nullptr && lastEnemy != var) || lastEnemy == nullptr) {
					var->damage(dmg);
					lastEnemy = var;
				}
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
	case Game::Canon:
		pos.x += dir * vel*delta;

		if (pos.x <= -30 || pos.x >= 1500)
			destruido = true;
		for each (auto var in p->enems)
		{
			if (var != nullptr  && var->collision(this)) {
				if ((lastEnemy != nullptr && lastEnemy != var) || lastEnemy == nullptr) {
					var->damage(dmg);
					lastEnemy = var;
				}
			}
		}
		
		break;
	default:
		break;
	}
}