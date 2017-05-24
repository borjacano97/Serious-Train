#include "PantallaInicio.h"


PantallaInicio::PantallaInicio(Game* juego) : Estado(juego)
{
	fondo = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::FondoIni, Game::Fondo_t::FondoInicio);
}


void PantallaInicio::draw(){
	fondo->draw();
	Estado::draw();
}
