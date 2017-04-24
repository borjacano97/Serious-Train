#include "Menu.h"
#include "Button.h"
#include "Tienda.h"


Menu::Menu(Game * juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonJ, 100, 100, jugar));
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonS, 300, 200, salir));
}

void Menu::jugar(Game * jg) {
	jg->changeState(new Tienda(jg));
}

void Menu::salir(Game * jg){
	jg->setSalir();
}
bool Menu::initLibraries() {
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}
	return true;
}
