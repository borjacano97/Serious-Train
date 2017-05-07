#include "Pausa.h"
#include "Button.h"
#include "Play.h"


Pausa::Pausa(Game* juego) : Estado(juego)
{
	game_ptr = juego;
	objetos.emplace_back(new Button(ptsjuego, 300, 500, Game::Boton_t::Jugar, reanudar));
	objetos.emplace_back(new Button(ptsjuego, 550, 500, Game::Boton_t::Controles, control));
	objetos.emplace_back(new Button(ptsjuego, 800, 500, Game::Boton_t::Volver, salir));
}

void Pausa::reanudar(Game * jg) {
	jg->popState();
}
bool Pausa::handle_events(SDL_Event * evento)
{
	if (evento->type == SDL_MOUSEBUTTONDOWN && evento->button.state == SDL_BUTTON_LEFT) {
		mx = evento->button.x;
		my = evento->button.y;
		onClick();
	}

	return Estado::handle_events(evento);
}
void Pausa::getMousePos(int & x, int & y)
{
	x = mx;
	y = my;
}
void Pausa::salir(Game * jg){
	jg->popState();
	jg->popState();
}

bool Pausa::initLibraries() {
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}
	return true;
}

