#include "Menu.h"
#include "Button.h"
#include "Play.h"


Menu::Menu(Game * juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, Game::TBoton, 800, 400, salir));
	objetos.emplace_back(new Button(ptsjuego, Game::TBoton, 300, 400, jugar));
}


Menu::~Menu()
{
}
void Menu::salir(Game * jg){
	jg->setSalir();
}

void Menu::jugar(Game * jg){
	jg->changeState(new Play(jg));  
}

void Menu::onClick(){
	bool clickeado = false;

	int i = objetos.size() - 1;
	while (!clickeado && i >= 0)
	{
		if (objetos[i]->onClick())
			clickeado = true;
		i--;
	}

}