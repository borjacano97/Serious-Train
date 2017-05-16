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
	case Game::Laser: Ttextura = Game::Texturas_t::TVagonLaser;
		break;
	case Game::Lanzallamas: Ttextura = Game::Texturas_t::TVagonFuego;
		break;
	case Game::Escudo: {
		Ttextura = Game::Texturas_t::TVagonEscudo; 
		p->TrainHp->giveHP(90);		
	}
		break;
	case Game::Recuperador: Ttextura = Game::Texturas_t::TVagonReg; 
	    break;
	case Game::Succionador: Ttextura = Game::Texturas_t::TVagonAuto;
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
				if (var != nullptr && pos.y - var->getPos().y <= 20 && pos.y - var->getPos().y >= -100) 	var->damage(1500);
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
	case Game::Recuperador:
		if (this->collision(p->player)) {
			p->TrainHp->giveHP(1);
		}
		break;
	case Game::Succionador:
		for each (auto var in p->enems)
		{
			if (var != nullptr && p->tg->collision(var)){
				if (var->getPos().y > pos.y) {
					if (contSucc >= 10){
						contSucc = 0;
						var->pos.y--;
					}					
					else contSucc+=delta;
				}
				else if (var->getPos().y < pos.y){
					if (contSucc >= 10){
						contSucc = 0;
						var->pos.y++;
					}
					else contSucc+=delta;
				}
			}
		}
		break;
	default:
		break;
	}
	vib++;
	if (vib >= 1500 ){
		
		if ( vib % 8 == 0) pos.x -= 4;
		else if (vib % 8 == 1) pos.x += 4;
		
	}
	 if (vib >= 2001) vib = 0;
	
}