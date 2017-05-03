#include "Survival.h"
#include "Enemigo.h"
#include "Escenario.h"


// FALTA POR CREAR EL CONTADOR DE TIEMPO, CAMBIAR PUNTOS POR Nº DE RONDA , Y PENSAR SI SE VAN A METER VAGONES ENTRE LAS RONDAS
// Y CREAR UNA CLASE DE FIN NIVEL ESPECIAL QUE TE MUESTRE EL TIEMPO (YA QUE SIEMPRE SE PIERDE)
Survival::Survival(Game * j) : Play(j)
{
	for (unsigned int i = 0; i < 4; i++) {
		tren.emplace_back(new Vagon(ptsjuego, this, 580, 100 + 150 * i, Game::Vagon_t::Vacio));
	}
	armaActual = new ArmaTienda(ptsjuego, NULL, 170 , 70, 0, Game::Bala_t::Piedra, true);
	arma = Game::Bala_t::Piedra;
	cadencia = 800;

	shootTimer = 0;
	spawnTimer = 0;
	textInit = 0;

	spawn = 1500; // variable que va a hacer que a partir de la ronda 6 cada vez se generen más y más enemigos
	
	esc = new Escenario(ptsjuego, Game::Texturas_t::TFondo, 0, -4280);

	contRondas = 1;

	enem = 0; // variable que cuenta los enemigos creados por ronda
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
			armaActual = new ArmaTienda(ptsjuego, NULL, 170, 50, 0, Game::Bala_t::Pistola, true);
			created = true;
		}
			
		arma = Game::Bala_t::Pistola;
		cadencia = 600;

		if (enem < (7 * contRondas) && spawnTimer >= (spawn -50)) {
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
	case 3:
		if (!created) {
			armaActual = new ArmaTienda(ptsjuego, NULL, 170, 70, 0, Game::Bala_t::Escopeta, true);
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
			armaActual = new ArmaTienda(ptsjuego, NULL, 170, 70, 0, Game::Bala_t::Sniper, true);
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
			armaActual = new ArmaTienda(ptsjuego, NULL, 170, 70, 0, Game::Bala_t::Metralleta, true);
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
						if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 130, Game::Enemigo_t::ElQueDispara));
						else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 130, Game::Enemigo_t::ElQueDispara));
					}
				}
				enem++;
			}			
			spawnTimer = 0;
		}
		break;
	default:
		if (!created) {
			armaActual = new ArmaTienda(ptsjuego, NULL, 170, 70, 0, Game::Bala_t::Minigun, true);
			created = true;
		}
		arma = Game::Bala_t::Minigun;
		cadencia = 150;

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
							if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 130, Game::Enemigo_t::ElQueDispara));
							else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 130, Game::Enemigo_t::ElQueDispara));
						}
						else {
							if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Tank));
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
			if (contRondas >= 6) spawn -= 10;

			enem = 0;
			spawnTimer = 0;
			killed = 0;

			newRonda = true;
			created = false; // para que no haga un new arma cada frame

			contRondas++;
			spawn += 5000; //estaria bien aquí parar el tiempo de spawn por así decirlo durante un ratejo para que se note el tiempo entre rondas
		}
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

	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(70, 120, 10, 70));	


	if (newRonda && ptsjuego->spanish) {
		font->loadFromText(ptsjuego->pRender, " Nueva    Ronda:  " + std::to_string(contRondas), fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(220, 500, 400, 120));
	}
	if (newRonda && !ptsjuego->spanish) {
		font->loadFromText(ptsjuego->pRender, " New    Round:    " + std::to_string(contRondas), fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(220, 500, 400, 120));
	}


	if (ptsjuego->spanish && enem < 2 && textInit < 1) {
		font->loadFromText(ptsjuego->pRender, "L o s   C o w b o y s   n a c e n ,   n o   s e   h a c e n", fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(210, 1050, 120, 180));
		textInit++;
	}
	if (!ptsjuego->spanish && enem < 2 && textInit < 1) {
		font->loadFromText(ptsjuego->pRender, "C o w b o y s   a r e   b o r n ,   t h e y   a i n t   m a d e", fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(210, 1050, 90, 180));
		textInit++;
	}
	/*else {
		font->loadFromText(ptsjuego->pRender, "Cowboys are born, they ain’t made!" + std::to_string(contRondas), fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(220, 410, 480, 120));
	}*/
	/*else  {
		font->loadFromText(ptsjuego->pRender, " New Round: " + std::to_string(contRondas), fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(220, 380, 520, 120));
	}*/

}