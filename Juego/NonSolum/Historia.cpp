#include "Historia.h"
#include "Button.h"

Historia::Historia(Game* juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, 1050, 480, Game::Boton_t::Jugar, jugar));

	switch (juego->getNivel())
	{
	case 1: fondo = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::Fondo, Game::Fondo_t::Historia1);
		break;
	default:
		break;
	}
	
}

void Historia::draw() {
	fondo->draw();
	Estado::draw();
}
void Historia::jugar(Game* juego) {
	juego->popState();
}