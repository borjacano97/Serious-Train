#include "Controles.h"
#include "Button.h"


Controles::Controles(Game* juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, 550, 600, Game::Boton_t::Volver, salir));
}
