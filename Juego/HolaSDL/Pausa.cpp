#include "Pausa.h"
#include "Button.h"
#include "Play.h"


Pausa::Pausa(Game* juego) : Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonC, 300, 500, reanudar));
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonS, 800, 500, salir));
}

void Pausa::reanudar(Game * jg) {
	jg->popState();
}
void Pausa::salir(Game * jg){
	jg->setSalir();
}
