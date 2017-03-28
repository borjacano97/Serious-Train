#include "Menu.h"
#include "Button.h"
#include "Play.h"
#include "Nivel1.h"


Menu::Menu(Game * juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonJ, 300, 400, jugar));
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonS, 800, 400, salir));
}


void Menu::salir(Game * jg){
	jg->setSalir();
}

void Menu::jugar(Game * jg){
	jg->changeState(new Nivel1(jg));  
}
void Menu::update(Uint32 delta) {
	for (auto i : objetos) {
		if (i != nullptr) {
			i->update(delta);
		}
	}
}