#include "FinNivel.h"
#include "Button.h"
#include "Tienda.h"

FinNivel::FinNivel(Game* juego, bool v) :Estado(juego)
{		
	victory = v;
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonJ, 300, 500, jugar)); // hay que poner sdl_center o algo asi xd
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonS, 800, 500, salir));
}

void FinNivel::jugar(Game * jg) {
	jg->popState(); // vuelve a la tienda
}

void FinNivel::salir(Game * jg){
	jg->setSalir();
}