#include "Creditos.h"


Creditos::Creditos(Game* juego) :Estado(juego)
{
	letras = new Hud(ptsjuego, NULL, 0, 720, Game::Hud_t::Creditos, Game::Fondo_t::History);
}
void Creditos::draw(){
	letras->draw();
}
void Creditos::update(Uint32 d){
	letras->update(d);
}
