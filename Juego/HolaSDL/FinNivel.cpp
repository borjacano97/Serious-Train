#include "FinNivel.h"
#include "Button.h"
#include "Play.h"
#include "Nivel1.h"
#include "Nivel2.h"

FinNivel::FinNivel(Game* juego, bool v) :Estado(juego)
{		
	victory = v;
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonJ, 300, 500, jugar)); // hay que poner sdl_center o algo asi xd
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonS, 800, 500, salir));
}


void FinNivel::salir(Game * jg){
	jg->setSalir();
}

void FinNivel::jugar(Game * jg){
	jg->changeState(new Play(jg));
	switch (jg->getNivel())
		 {
		case(1): {
			jg->changeState(new Nivel1(jg));
			break;}
		case(2): {
			jg->changeState(new Nivel2(jg));
			break;}
		default:
			break;}
}
void FinNivel::update(Uint32 delta) {
	for (auto i : objetos) {
		if (i != nullptr) {
			i->update(delta);
		}
	}
}