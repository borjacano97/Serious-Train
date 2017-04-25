#include "Vagon.h"
#include "Play.h"


Vagon::Vagon(Game* juego, Play*pl, float x, float y, Game::Vagon_t t)
{
	juegootp = juego;
	p= pl;

	alto = 151;
	ancho = 120;

	pos.set(x, y);

	tipo = t;
	
	disparo = false;

	switch (tipo)
	{
	case Game::Locom: Ttextura = Game::Texturas_t::TLocomotora;
		break;
	case Game::Vacio: Ttextura = Game::Texturas_t::TVagon1;
		break;
	case Game::Automatico: Ttextura = Game::Texturas_t::TVagonAuto;
		break;
	case Game::Laser: Ttextura = Game::Texturas_t::TVagon1;
		break;
	case Game::Lanzallamas: Ttextura = Game::Texturas_t::TVagon1;
		break;
	case Game::Escudo: {
		Ttextura = Game::Texturas_t::TVagon1; 
		p->TrainHp->giveHP(150);
	}
		break;
	default:
		break;
	}
}

void Vagon::update(Uint32 delta) {
	switch (tipo)
	{
	case Game::Automatico:
		cont += delta;
		if (cont >= 1500) {
			p->balas.emplace_back(new Bala(juegootp, p, pos.x + 120, pos.y + 75, 1, Game::Bala_t::Pistola));
			p->balas.emplace_back(new Bala(juegootp, p, pos.x, pos.y + 75, -1, Game::Bala_t::Pistola));
			cont = 0;
		}
		break;
	case Game::Laser:
		cont += delta;
		if (cont >= 4000) {
			p->balas.emplace_back(new Bala(juegootp, p, pos.x - 700, pos.y - 630, 1, Game::Bala_t::Rayo));
			p->balas.emplace_back(new Bala(juegootp, p, pos.x + 120, pos.y - 630, -1, Game::Bala_t::Rayo));
			cont = 0;
			for each (auto var in p->enems)
			{
				if (var != nullptr && pos.y - var->getPos().y <= 20 && pos.y - var->getPos().y >= -100) 	var->destroy();
			}
		}
		break;
	case Game::Lanzallamas:
		cont += delta;
		if (cont >= 3000) {
			p->balas.emplace_back(new Bala(juegootp, p, pos.x + 130, pos.y, 1, Game::Bala_t::Fuego));
			p->balas.emplace_back(new Bala(juegootp, p, pos.x - 120, pos.y, -1, Game::Bala_t::Fuego));
			cont = 0;
		}
		break;
	default:
		break;
	}
	cont++;
	if (cont >= 1500){
		
		if ( cont% 2 == 0) pos.x -= 3;
		else pos.x += 3;	
		
	}
	 if (cont >= 2001) cont = 0;
	
}