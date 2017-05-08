#include "Vagon.h"
#include "Play.h"


Vagon::Vagon(Game* juego, Play*pl, float x, float y, Game::Vagon_t t)
{
	juegootp = juego;
	p= pl;

	alto = 151;
	ancho = 98;
	
	
	pos.set(x, y);

	tipo = t;
	
	disparo = false;
	// IMAGEN DEL VAGON
	switch (tipo)
	{
	case Game::Locom: 
		Ttextura = Game::Texturas_t::TLocomotora;
		break;
	case Game::Vacio: 
		Ttextura = Game::Texturas_t::TVagon1;
		break;
	case Game::Automatico:
		alto = 151;
		anchoc = 392;
		ancho = 98;
		Ttextura = Game::Texturas_t::TVagonAutoA;
		break;
	case Game::Laser:
		alto = 151;
		anchoc = 392;
		ancho = 98;
		Ttextura = Game::Texturas_t::TVagonLaserA;
		break;
	case Game::Lanzallamas:
		alto = 151;
		anchoc = 490;
		ancho = 98;
		Ttextura = Game::Texturas_t::TVagonFuegoA;
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
// EFECTO DEL VAGON
void Vagon::update(Uint32 delta) {
	
	switch (tipo)
	{
	case Game::Automatico:
		cont += delta;
		j += delta; // vel animacion
		if (cont >= 1500) {
			p->balas.emplace_back(new Bala(juegootp, p, pos.x + 120, pos.y + 75, 1, Game::Bala_t::Pistola));
			p->balas.emplace_back(new Bala(juegootp, p, pos.x, pos.y + 75, -1, Game::Bala_t::Pistola));
			cont = 0;
		}
		break;
	case Game::Laser:
		cont += delta;
		j += delta; // vel animacion
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
		j += delta; // vel animacion
		if (cont >= 3000) {
			p->balas.emplace_back(new Bala(juegootp, p, pos.x + 130, pos.y, 1, Game::Bala_t::Fuego));
			p->balas.emplace_back(new Bala(juegootp, p, pos.x - 120, pos.y, -1, Game::Bala_t::Fuego));
			cont = 0;
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

			// VELOCIDAD ANIMACION
			if (j >= 200){
				i += ancho;
				rectA.x = i;

				if (i >= anchoc) i = ancho;
				j = 0;
			}//VELOCIDAD ANIMACION
	 


	}
void Vagon::draw(){
	
	rect.h = alto;
	rect.w = ancho;
	rect.x = pos.x;
	rect.y = pos.y;

	rectA.h = alto;
	rectA.w = ancho;
	rectA.x = i;
	rectA.y = 0;

	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, &rectA, &rect);
	
}