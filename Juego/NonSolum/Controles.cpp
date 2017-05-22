#include "Controles.h"
#include "Button.h"


Controles::Controles(Game* juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, 550, 600, Game::Boton_t::Volver, salir));
	fondo = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::Fondo, Game::Fondo_t::Control);
}

void Controles::draw(){
fondo->draw();
Estado::draw();
}

