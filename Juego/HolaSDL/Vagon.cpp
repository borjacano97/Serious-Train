#include "Vagon.h"
#include "Play.h"


Vagon::Vagon(Game* juego, Play*pl, Game::Texturas_t text, float x, float y, Game::Vagon_t t)
{
	juegootp = juego;
	Ttextura = text;
	p= pl;

	alto = 151;
	ancho = 120;

	pos.set(x, y);

	tipo = t;
	
	disparo = false;
}

void Vagon::update(Uint32 delta) {
	switch (tipo)
	{
	case Game::Automatico:
		cont += delta;
		if (cont >= 1500) {
			p->balas.emplace_back(new Bala(juegootp, Game::TRoca, pos.x + 120, pos.y + 75, 1, Game::Bala_t::Piedra));
			p->balas.emplace_back(new Bala(juegootp, Game::TRoca, pos.x, pos.y + 75, -1, Game::Bala_t::Piedra));
			cont = 0;
		}
		break;
	case Game::Laser:
		cont += delta;
		if (cont >= 3000) {
			p->balas.emplace_back(new Bala(juegootp, Game::TLaser, pos.x - 700, pos.y - 630, 1, Game::Bala_t::Rayo));
			p->balas.emplace_back(new Bala(juegootp, Game::TLaser, pos.x + 120, pos.y - 630, -1, Game::Bala_t::Rayo));
			cont = 0;
			for each (auto var in p->objetos)
			{
				if (var != nullptr && pos.y - var->getPos().y <= 20 && pos.y - var->getPos().y >= -100) {
					juegootp->addCoins(var->getPoints());
					var->destroy();
					p->killed++;
				}

			}
		}
		break;
	default:
		break;
	}
}