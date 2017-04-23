#include "Nivel2.h"
#include "Enemigo.h"


Nivel2::Nivel2(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a) : Play(j)
{
	enem = 0;
	emax = 15;
	for (unsigned int i = 0; i < 4; i++) {
		tren.emplace_back(new Vagon(ptsjuego, this, 580, 100 +150*i, v[i]));
	}	
	arma = a;
	timer = 0;
	//Falta por completar conforme se implementen las nuevas clases y me da palo hacerlo para nada ^^'
	switch (arma)
	{
	case Game::Bala_t::Piedra:
		cadencia = 800;//0'8s || 800 ms 
					   /*case Game::Bala_t::Pistola:
					   cadencia = 400;//0'4s || 400 ms */
	}
}
void Nivel2::onClick() {
	if (timer >= cadencia) {
		timer = 0;
		balas.emplace_back(new Bala(ptsjuego, this, player->getPos().x, player->getPos().y, player->getMira(), arma));
	}
}
void Nivel2::update(Uint32 delta) {
	timer += delta;
	if (enem < emax){
		 //generar zombies aleatorios
		aleatorio = rand() % 10000;
		if (aleatorio >= 9985) {
			izq = rand() % 2;
			if (izq == 0) enems.emplace_back
				(new Enemigo(ptsjuego, this, 0, (rand() % 550) - 50, Game::Enemigo_t::Normal));
			else enems.emplace_back
				(new Enemigo(ptsjuego, this, 1300, (rand() % 550) - 50, Game::Enemigo_t::Normal));
			enem++;
		}	
	}
	else if (emax == Play::getKilled()){
		Play::finish();
	}
	
	
	Play::update(delta);
	
}