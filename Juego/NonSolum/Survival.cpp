#include "Survival.h"
#include "Enemigo.h"
#include "Escenario.h"


// FALTA POR CREAR EL CONTADOR DE TIEMPO, QUITAR LOS PUNTOS Y CREAR UNA CLASE DE FIN NIVEL ESPECIAL QUE TE MUESTRE EL TIEMPO (YA QUE SIEMPRE SE PIERDE)
// Y CORREGIR ERROR EN LOS SPAWNS 
Survival::Survival(Game * j) : Play(j)
{
	for (unsigned int i = 0; i < 4; i++) {
		tren.emplace_back(new Vagon(ptsjuego, this, 580, 100 + 150 * i, Game::Vagon_t::Vacio));
	}
	arma = Game::Bala_t::Piedra;
	cadencia = 800;

	shootTimer = 0;
	spawnTimer = 0;

	spawn = 1500; // variable que va a hacer que a partir de la ronda 6 cada vez se generen más y más enemigos
	
	esc = new Escenario(ptsjuego, Game::Texturas_t::TFondo, 0, -4280);

	contRondas = 1;
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
	case 1:
		//generar zombies aleatorios
		if (spawnTimer >= spawn) {
			if (rand() % 2 == 0) {
				if (rand() % 2 == 0) enems.emplace_back
				(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Normal));
				else enems.emplace_back
				(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Normal));
			}
			spawnTimer = 0;
		}
		break;
	case 2:
		
		arma = Game::Bala_t::Escopeta;
		cadencia = 700;
		if (spawnTimer >= (spawn -50)) {
			if (newRonda) {
				spawn -= 7000;
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
				spawnTimer = 0;
			}
			
		}
		break;
	case 3:
		arma = Game::Bala_t::Pistola;
		cadencia = 600;
		if (spawnTimer >= (spawn -100)) {
			if (newRonda) {
				spawn -= 7000;
				newRonda = false;
			}
			if (rand() % 2 == 0) {
				if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Normal));
				else  enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Normal));
			}
			else {
				if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
				else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
			}
			spawnTimer = 0;
		}
		break;
	case 4:
		arma = Game::Bala_t::Metralleta;
		cadencia = 200;
		if (spawnTimer >= (spawn - 110)) {
			if (newRonda) {
				spawn -= 7000;
				newRonda = false;
			}
			if (rand() % 2 == 0) {
				if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 280, Game::Enemigo_t::Normal));
				else  enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 280, Game::Enemigo_t::Normal));
			}
			else {
				if (rand() % 2 == 0) enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
				else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 120, Game::Enemigo_t::Rapido));
			}
			spawnTimer = 0;
		}
		break;
	case 5:
		arma = Game::Bala_t::Sniper;
		cadencia = 1000;
		if (spawnTimer >= (spawn - 120)) {
			if (newRonda) {
				spawn -= 7000;
				newRonda = false;
			}
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
			spawnTimer = 0;
		}
		break;
	default:
		arma = Game::Bala_t::Minigun;
		cadencia = 30;
		if (spawnTimer >= spawn) {
			if (newRonda) {
				spawn -= 7000;
				newRonda = false;
			}
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
						if (rand() % 2 == 0)enems.emplace_back(new Enemigo(ptsjuego, this, 0, (rand() % 550) + 130, Game::Enemigo_t::Tank));
						else enems.emplace_back(new Enemigo(ptsjuego, this, 1300, (rand() % 550) + 130, Game::Enemigo_t::Tank));
					}
				}
			}
			spawnTimer = 0;
		}
		break;
	}
		

		if (killed >= (2 * contRondas)) {
			if (contRondas >= 6) spawn -= 10;

			spawnTimer = 0;
			killed = 0;
			newRonda = true;
			contRondas++;
			spawn += 7000; //estaria bien aquí parar el tiempo de spawn por así decirlo durante un ratejo para que se note el tiempo entre rondas
		}
	Play::update(delta);
}
