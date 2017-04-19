#include "Menu.h"
#include "Button.h"
#include "Tienda.h"


Menu::Menu(Game * juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonJ, 300, 400, jugar));
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonS, 800, 400, salir));
}

void Menu::jugar(Game * jg) {
	jg->changeState(new Tienda(jg));
}

void Menu::salir(Game * jg){
	jg->setSalir();
}
