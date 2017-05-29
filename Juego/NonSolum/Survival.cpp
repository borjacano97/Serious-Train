#include "Survival.h"
#include "Enemigo.h"


// FALTA POR CREAR EL CONTADOR DE TIEMPO
// Y CREAR UNA CLASE DE FIN NIVEL ESPECIAL QUE TE MUESTRE EL TIEMPO (YA QUE SIEMPRE SE PIERDE)
Survival::Survival(Game * j) : Play(j)
{

	for (unsigned int i = 0; i < 4; i++) {
		if (i==0 && !ptsjuego->extrem)	tren.emplace_back(new Vagon(ptsjuego, this, 580, 100 + 150 * i, Game::Vagon_t::Recuperador));
		else tren.emplace_back(new Vagon(ptsjuego, this, 580, 100 + 150 * i, Game::Vagon_t::Vacio));
	}


	if (ptsjuego->extrem){
		arma = Game::Bala_t::Minigun;
		cadencia = 100;

	}
	else {
		armaActual = new ArmaTienda(ptsjuego, NULL, 300, 40, 0, Game::Bala_t::Piedra, true);

		arma = Game::Bala_t::Piedra;
		cadencia = 800;
		
		spawn = 3000; // variable que va a hacer que a partir de la ronda 6 cada vez se generen más y más enemigos

	}

	shootTimer = 0;
	spawnTimer = 0;
	textInit = 0;


	ptsjuego->contRondas = 1;

	enem = 0; // variable que cuenta los enemigos creados por ronda

	TTF_Init();
	textTut = new Texturas();
	textTut->loadFuente("../fonts/fuenteNumbers.ttf", 200);
}
void Survival::update(Uint32 delta) {
	if (!ptsjuego->paused) {

		if (ptsjuego->extrem){
			shootTimer += delta;
			spawnTimer += delta;

			if (disparando && shootTimer >= cadencia) {
				balas.emplace_back(new Bala(ptsjuego, this, player->getPos().x, player->getPos().y + 10, player->getMira(), arma));
				shootTimer = 0;
			}


			switch (ptsjuego->contRondas) // 6 tipos de enemigos
			{
			case (1) :


					 spawn = 750 - (3 * ptsjuego->contRondas); // ha de variar entre rondas
					 lastEnemy = 30 + (2 * ptsjuego->contRondas);
					 if (enem < lastEnemy && spawnTimer >= spawn) {

						 if (rand() % 2 == 0) enems.emplace_back
							 (new Enemigo(ptsjuego, this, 0, (rand() % 500) + 320, Game::Enemigo_t::Normal));
						 else enems.emplace_back
							 (new Enemigo(ptsjuego, this, 1300, (rand() % 500) + 320, Game::Enemigo_t::Normal));
						 enem++;
						 spawnTimer = 0;
					 }


					 break;
			case (2) :

				spawn = 650 - (3 * ptsjuego->contRondas);
				lastEnemy = 25 + (2 * ptsjuego->contRondas);
				if (enem < lastEnemy && spawnTimer >= spawn) {
					if (newRonda) {
						spawn -= 9000;
						newRonda = false;
					}
					else {
						if (rand() % 2 == 0) enems.emplace_back
							(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 100, Game::Enemigo_t::Rapido));
						else enems.emplace_back
							(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 100, Game::Enemigo_t::Rapido));
						enem++;
						spawnTimer = 0;
					}
				}
				break;
			case (3) :
				spawn = 950 - (3 * ptsjuego->contRondas);
				lastEnemy = 20 + (2 * ptsjuego->contRondas);
				if (enem < lastEnemy && spawnTimer >= spawn) {
					if (newRonda) {
						spawn -= 9000;
						newRonda = false;
					}
					else {
						if (rand() % 2 == 0) enems.emplace_back
							(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Invisible));
						else enems.emplace_back
							(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Invisible));
						enem++;
						spawnTimer = 0;
					}
				}
				break;
			case (4) :
				spawn = 2950 - (3 * ptsjuego->contRondas);
				lastEnemy = 7 + (2 * ptsjuego->contRondas);
				if (enem < lastEnemy && spawnTimer >= spawn) {
					if (newRonda) {
						spawn -= 9000;
						newRonda = false;
					}
					else {
						if (rand() % 2 == 0) enems.emplace_back
							(new Enemigo(ptsjuego, this, 0, (rand() % 500) + 300, Game::Enemigo_t::Tank));
						else enems.emplace_back
							(new Enemigo(ptsjuego, this, 1300, (rand() % 500) + 300, Game::Enemigo_t::Tank));
						enem++;
						spawnTimer = 0;
					}
				}
				break;
			case (5) :
				spawn = 1600 - (3 * ptsjuego->contRondas);
				lastEnemy = 20 + (2 * ptsjuego->contRondas);
				if (enem < lastEnemy && spawnTimer >= spawn) {
					if (newRonda) {
						spawn -= 9000;
						newRonda = false;
					}
					else {
						if (rand() % 2 == 0) enems.emplace_back
							(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 80, Game::Enemigo_t::Enano));
						else enems.emplace_back
							(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 80, Game::Enemigo_t::Enano));
						enem++;
						spawnTimer = 0;
					}
				}
				break;
			case (6) :
				spawn = 3800 - (3 * ptsjuego->contRondas);
				lastEnemy = 5 + (2 * ptsjuego->contRondas);
				if (enem < lastEnemy && spawnTimer >= spawn) {
					if (newRonda) {
						spawn -= 9000;
						newRonda = false;
					}
					else {
						if (rand() % 2 == 0) enems.emplace_back
							(new Enemigo(ptsjuego, this, 0, (rand() % 500) + 230, Game::Enemigo_t::Tocho));
						else enems.emplace_back
							(new Enemigo(ptsjuego, this, 1300, (rand() % 500) + 230, Game::Enemigo_t::Tocho));
						enem++;
						spawnTimer = 0;
					}
				}
				break;
			case (7):
				lastEnemy = 2;
				if (enem < 2 && spawnTimer >= spawn) {
					if (newRonda) {
						spawn -= 9000;
						newRonda = false;
					}
					else {
						 enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 500) + 230, Game::Enemigo_t::Boss));
						 enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 500) + 230, Game::Enemigo_t::Boss));

						enem+=2;
						spawnTimer = 0;
					}
				}
				break;
			default:
				break;
			}


			if (killed >= lastEnemy) {

				enem = 0;
				spawnTimer = 0;
				killed = 0;

				newRonda = true;
				vagonCambiado = false;

				ptsjuego->contRondas++;
				spawn += 9000;
			}
			if (ptsjuego->contRondas == 8) fin = true;
			
		}
		else {
			shootTimer += delta;
			spawnTimer += delta;

			if (disparando && shootTimer >= cadencia) {
				balas.emplace_back(new Bala(ptsjuego, this, player->getPos().x, player->getPos().y + 10, player->getMira(), arma));
				shootTimer = 0;
			}

			switch (ptsjuego->contRondas)
			{
				/*font->loadFromText(ptsjuego->pRender, " " + std::to_string(contRondas), fontColor);
				font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(220, 410, 480, 120));*/
			case 1:
				if (enem < (7 * ptsjuego->contRondas) && spawnTimer >= spawn) {
					if (rand() % 2 == 0) {
						if (rand() % 2 == 0) enems.emplace_back
							(new Enemigo(ptsjuego, this, 0, (rand() % 500) + 320, Game::Enemigo_t::Normal));
						else enems.emplace_back
							(new Enemigo(ptsjuego, this, 1300, (rand() % 500) + 320, Game::Enemigo_t::Normal));
						enem++;
					}
					spawnTimer = 0;
				}
				break;
			case 2:
				if (!created) {
					armaActual = new ArmaTienda(ptsjuego, NULL, 310, 30, 0, Game::Bala_t::Pistola, true);
					created = true;
				}

				arma = Game::Bala_t::Pistola;
				cadencia = 600;

				if (enem < (7 * ptsjuego->contRondas) && spawnTimer >= (spawn - 50)) {
					if (newRonda) {
						spawn -= 5000;
						newRonda = false;
					}
					else {
						if (rand() % 2 == 0) {
							if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 500) + 320, Game::Enemigo_t::Normal));
							else  enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 500) + 320, Game::Enemigo_t::Normal));
						}
						else {
							if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 100, Game::Enemigo_t::Rapido));
							else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 100, Game::Enemigo_t::Rapido));
						}
						enem++;

					}
					spawnTimer = 0;
				}
				break;
			case 3:
				if (!created) {
					armaActual = new ArmaTienda(ptsjuego, NULL, 300, 40, 0, Game::Bala_t::Escopeta, true);
					created = true;
				}
				arma = Game::Bala_t::Escopeta;
				cadencia = 700;

				if (enem < (7 * ptsjuego->contRondas) && spawnTimer >= (spawn - 100)) {
					if (newRonda) {
						spawn -= 5000;
						newRonda = false;
					}
					else {
						if (rand() % 2 == 0) {
							if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 500) + 320, Game::Enemigo_t::Normal));
							else  enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 500) + 320, Game::Enemigo_t::Normal));
						}
						else {
							if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 100, Game::Enemigo_t::Rapido));
							else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 100, Game::Enemigo_t::Rapido));
						}
						enem++;
					}
					spawnTimer = 0;
				}
				break;
			case 4:
				if (!created) {
					armaActual = new ArmaTienda(ptsjuego, NULL, 300, 40, 0, Game::Bala_t::Sniper, true);
					created = true;
				}
				arma = Game::Bala_t::Sniper;
				cadencia = 1000;

				if (enem < (7 * ptsjuego->contRondas) && spawnTimer >= (spawn - 110)) {
					if (newRonda) {
						spawn -= 5000;
						newRonda = false;
					}
					else {
						if (rand() % 2 == 0) {
							if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 500) + 320, Game::Enemigo_t::Normal));
							else  enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 500) + 320, Game::Enemigo_t::Normal));
						}
						else {
							if (rand() % 2 == 0) {
								if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 100, Game::Enemigo_t::Rapido));
								else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 100, Game::Enemigo_t::Rapido));
							}
							else {
								if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Invisible));
								else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Invisible));
							}
						}
						enem++;
					}
					spawnTimer = 0;
				}
				break;
			case 5:
				if (!created) {
					armaActual = new ArmaTienda(ptsjuego, NULL, 300, 40, 0, Game::Bala_t::Metralleta, true);
					created = true;
				}
				arma = Game::Bala_t::Metralleta;
				cadencia = 300;

				if (enem < (7 * ptsjuego->contRondas) && spawnTimer >= (spawn - 200)) {
					if (newRonda) {
						spawn -= 5000;
						newRonda = false;
					}
					else {
						if (rand() % 2 == 0) {
							if (rand() % 2 == 0) {
								if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 500) + 320, Game::Enemigo_t::Normal));
								else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 500) + 320, Game::Enemigo_t::Normal));
							}
							else {
								if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Invisible));
								else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Invisible));
							}
						}
						else {
							if (rand() % 2 == 0) {
								if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 100, Game::Enemigo_t::Rapido));
								else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 100, Game::Enemigo_t::Rapido));
							}
							else {
								if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 80, Game::Enemigo_t::Enano));
								else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 80, Game::Enemigo_t::Enano));
							}
						}
						enem++;
					}
					spawnTimer = 0;
				}
				break;
			case 6:
				if (!created) {
					armaActual = new ArmaTienda(ptsjuego, NULL, 300, 40, 0, Game::Bala_t::Canon, true);
					created = true;
				}
				arma = Game::Bala_t::Canon;
				cadencia = 1700;

				if (enem < (7 * ptsjuego->contRondas) && spawnTimer >= (spawn - 250)) {
					if (newRonda) {
						spawn -= 5000;
						newRonda = false;
					}
					else {
						if (rand() % 2 == 0) {
							if (rand() % 2 == 0) {
								if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 500) + 320, Game::Enemigo_t::Normal));
								else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 500) + 320, Game::Enemigo_t::Normal));
							}
							else {
								if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Invisible));
								else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Invisible));
							}
						}
						else {
							if (rand() % 2 == 0) {
								if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 100, Game::Enemigo_t::Rapido));
								else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 100, Game::Enemigo_t::Rapido));
							}
							else {
								if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 80, Game::Enemigo_t::Enano));
								else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 80, Game::Enemigo_t::Enano));
							}
						}
						enem++;
					}
					spawnTimer = 0;
				}
				break;
			default:

				if (!vagonCambiado && (ptsjuego->contRondas == 8 || ptsjuego->contRondas == 9 || ptsjuego->contRondas == 10)) {

					tren[ptsjuego->contRondas - 6]->cambiar();
					vagonCambiado = true;
				}
				if (!created) {
					armaActual = new ArmaTienda(ptsjuego, NULL, 300, 40, 0, Game::Bala_t::Minigun, true);
					created = true;
				}
				arma = Game::Bala_t::Minigun;
				cadencia = 100;

				if (enem < (7 * ptsjuego->contRondas) && spawnTimer >= (spawn - 260)) {
					if (newRonda) {
						spawn -= 5000;
						newRonda = false;
					}
					else {
						if (rand() % 2 == 0) {
							if (rand() % 2 == 0) {
								if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 500) + 320, Game::Enemigo_t::Normal));
								else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 500) + 320, Game::Enemigo_t::Normal));
							}
							else {
								if (rand() % 2 == 0) {
									if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Invisible));
									else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Invisible));
								}
								else {
									if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 500) + 300, Game::Enemigo_t::Tank));
									else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 500) + 300, Game::Enemigo_t::Tank));
								}
							}
						}
						else {
							if (rand() % 2 == 0) {
								if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 100, Game::Enemigo_t::Rapido));
								else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 100, Game::Enemigo_t::Rapido));
							}
							else {
								if (rand() % 2 == 0) {
									if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 80, Game::Enemigo_t::Enano));
									else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 80, Game::Enemigo_t::Enano));
								}
								else {
									if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 500) + 230, Game::Enemigo_t::Tocho));
									else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 500) + 230, Game::Enemigo_t::Tocho));
								}
							}
						}
						enem++;
					}
					spawnTimer = 0;
				}
				break;
			}


			if (killed >= (7 * ptsjuego->contRondas)) {
				if (ptsjuego->contRondas >= 7) spawn -= 10;

				enem = 0;
				spawnTimer = 0;
				killed = 0;

				newRonda = true;
				created = false; // para que no haga un new arma cada frame
				vagonCambiado = false;

				ptsjuego->contRondas++;
				spawn += 5000; //estaria bien aquí parar el tiempo de spawn por así decirlo durante un ratejo para que se note el tiempo entre rondas
			}
		}		
		Play::update(delta);
	}	
}