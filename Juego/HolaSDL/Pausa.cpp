#include "Pausa.h"
#include "Button.h"
#include "Play.h"


Pausa::Pausa(Game* juego) : Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonJ, 300, 500, reanudar)); // hay que poner sdl_center o algo asi xd
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonS, 800, 500, salir));
}

void Pausa::reanudar(Game * jg) {
	jg->popState();
}
void Pausa::salir(Game * jg){
	jg->setSalir();
}
