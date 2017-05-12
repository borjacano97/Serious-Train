#include "Survival.h"
#include "Enemigo.h"
#include "Escenario.h"


// FALTA POR CREAR EL CONTADOR DE TIEMPO, CAMBIAR PUNTOS POR N� DE RONDA , Y PENSAR SI SE VAN A METER VAGONES ENTRE LAS RONDAS
// Y CREAR UNA CLASE DE FIN NIVEL ESPECIAL QUE TE MUESTRE EL TIEMPO (YA QUE SIEMPRE SE PIERDE)
Survival::Survival(Game * j) : Play(j)
{
	for (unsigned int i = 0; i < 4; i++) {
		tren.emplace_back(new Vagon(ptsjuego, this, 580, 100 + 150 * i, Game::Vagon_t::Vacio));
	}
	armaActual = new ArmaTienda(ptsjuego, NULL, 300 , 40, 0, Game::Bala_t::Piedra, true);

	arma = Game::Bala_t::Piedra;
	cadencia = 800;

	shootTimer = 0;
	spawnTimer = 0;
	textInit = 0;

	spawn = 1800; // variable que va a hacer que a partir de la ronda 6 cada vez se generen m�s y m�s enemigos
	

	contRondas = 1;

	enem = 0; // variable que cuenta los enemigos creados por ronda

	TTF_Init();
	textTut = new Texturas();
	textTut->loadFuente("../fonts/fuenteNumbers.ttf", 200);

}
void Survival::update(Uint32 delta) {
	
	shootTimer += delta;
	spawnTimer += delta;

	if (disparando && shootTimer >= cadencia) {
		balas.emplace_back(new Bala(ptsjuego, this, player->getPos().x, player->getPos().y + 10, player->getMira(), arma));
		shootTimer = 0;
	}

	switch (contRondas)
	{
		/*font->loadFromText(ptsjuego->pRender, " " + std::to_string(contRondas), fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(220, 410, 480, 120));*/
	case 1:
		
		if (enem < (7 * contRondas) && spawnTimer >= spawn ) {
			if (rand() % 2 == 0) {
				if (rand() % 2 == 0) enems.emplace_back
				(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Normal));
				else enems.emplace_back
				(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Normal));
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

		if (enem < (7 * contRondas) && spawnTimer >= (spawn -50)) {
			if (newRonda) {
				spawn -= 5000;
				std::cout << "SUENO" << std::endl;
				newRonda = false;
			}
			else {
				if (rand() % 2 == 0) {
					if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Normal));
					else  enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Normal));
				}
				else {
					if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
					else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
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

		if (enem < (7 * contRondas) && spawnTimer >= (spawn -100)) {
			if (newRonda) {
				spawn -= 5000;
				newRonda = false;
			}
			else {
				if (rand() % 2 == 0) {
					if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Normal));
					else  enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Normal));
				}
				else {
					if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
					else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
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

		if (enem < (7 * contRondas) && spawnTimer >= (spawn - 110)) {
			if (newRonda) {
				spawn -= 5000;
				newRonda = false;
			}
			else {
				if (rand() % 2 == 0) {
					if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Normal));
					else  enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Normal));
				}
				else {
					if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
					else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
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

		if (enem < (7 * contRondas) && spawnTimer >= (spawn - 120)) {
			if (newRonda) {
				spawn -= 5000;
				newRonda = false;
			}
			else {
				if (rand() % 2 == 0) {
					if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Normal));
					else  enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Normal));
				}
				else {
					if (rand() % 2 == 0) {
						if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
						else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
					}
					else {
						if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 180, Game::Enemigo_t::Enano));
						else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 180, Game::Enemigo_t::Enano));
					}
				}
				enem++;
			}			
			spawnTimer = 0;
		}
		break;
	case 6:
		if (!created) {
			armaActual = new ArmaTienda(ptsjuego, NULL, 300, 40, 0, Game::Bala_t::Minigun, true);
			created = true;
		}
		arma = Game::Bala_t::Minigun;
		cadencia = 100;

		if (enem < (7 * contRondas) && spawnTimer >= spawn) {
			if (newRonda) {
				spawn -= 5000;
				newRonda = false;
			}
			else {
				if (rand() % 2 == 0) {
					if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Normal));
					else  enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Normal));
				}
				else {
					if (rand() % 2 == 0) {
						if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
						else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
					}
					else {
						if (rand() % 2 == 0) {
							if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 180, Game::Enemigo_t::Enano));
							else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 180, Game::Enemigo_t::Enano));
						}
						else {
							if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 380, Game::Enemigo_t::Tank));
							else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Tank));
						}
					}
				}
				enem++;
			}
			spawnTimer = 0;
		}
		break;
	default:
		if (!created) {
			armaActual = new ArmaTienda(ptsjuego, NULL, 300, 40, 0, Game::Bala_t::Canon, true);
			created = true;
		}
		arma = Game::Bala_t::Canon;
		cadencia = 1700;

		if (enem < (7 * contRondas) && spawnTimer >= spawn) {
			if (newRonda) {
				spawn -= 5000;
				newRonda = false;
			}
			else {
				if (rand() % 2 == 0) {
					if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Normal));
					else  enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Normal));
				}
				else {
					if (rand() % 2 == 0) {
						if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
						else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
					}
					else {
						if (rand() % 2 == 0) {
							if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 180, Game::Enemigo_t::Enano));
							else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 180, Game::Enemigo_t::Enano));
						}
						else {
							if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 380, Game::Enemigo_t::Tank));
							else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Tank));
						}
					}					
			     }
				enem++;
			}
			spawnTimer = 0;
		}
		break;
	}
		

		if (killed >= (7 * contRondas)) {
			if (contRondas >= 7) spawn -= 10;

			enem = 0;
			spawnTimer = 0;
			killed = 0;

			newRonda = true;
			created = false; // para que no haga un new arma cada frame

			contRondas++;
			spawn += 5000; //estaria bien aqu� parar el tiempo de spawn por as� decirlo durante un ratejo para que se note el tiempo entre rondas
		}
		textInit += delta;
	Play::update(delta);
}
void Survival::draw() {
	Play::draw();


	if (ptsjuego->spanish) { 
		font->loadFromText(ptsjuego->pRender, " Ronda: " + std::to_string(contRondas), fontColor);
	}
	else { 
		font->loadFromText(ptsjuego->pRender, " Round: " + std::to_string(contRondas), fontColor); 
	}

	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, 90, 150, 53));


	if (newRonda && ptsjuego->spanish) {
		font->loadFromText(ptsjuego->pRender, " Nueva    Ronda:  " + std::to_string(contRondas), fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(220, 500, 400, 120));
	}
	if (newRonda && !ptsjuego->spanish) {
		font->loadFromText(ptsjuego->pRender, " New    Round:    " + std::to_string(contRondas), fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(220, 500, 400, 120));
	}


	if (ptsjuego->spanish && enem < 2 && textInit < 2000) {
		font->loadFromText(ptsjuego->pRender, "L o s   C o w b o y s   n a c e n ,   n o   s e   h a c e n", fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(130, 950, 140, 270));
	}
	if (!ptsjuego->spanish && enem < 2 && textInit <  2000) {
		font->loadFromText(ptsjuego->pRender, "C o w b o y s   a r e   b o r n ,   t h e y   a i n t   m a d e", fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(130, 950, 140, 270));
	}

	if (ptsjuego->spanish && enem <= 1 && contRondas == 1) {
		textTut->loadFromText(ptsjuego->pRender, "Muevete con WASD!!", fontColor);
		textTut->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(35, 350, 50, 170));
	}
	if (ptsjuego->spanish && enem >= 1 && enem < 3 && contRondas == 1) {
		textTut->loadFromText(ptsjuego->pRender, "Dispara con el raton!!", fontColor);
		textTut->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(35, 350, 50, 210));
	}

	if (!ptsjuego->spanish && enem <= 1 && contRondas == 1) {
		textTut->loadFromText(ptsjuego->pRender, "Move with WASD!!", fontColor);
		textTut->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(35, 350, 50, 170));
	}
	if (!ptsjuego->spanish && enem >= 1 && enem < 3 && contRondas == 1) {
		textTut->loadFromText(ptsjuego->pRender, "Shoot with the mouse!", fontColor);
		textTut->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(35, 350, 50, 210));
	}
}