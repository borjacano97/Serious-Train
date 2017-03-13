#include "Menu.h"
#include "Button.h"
#include "Play.h"


Menu::Menu(Game * juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonJ, 300, 400, jugar));
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonS, 800, 400, salir));
}


Menu::~Menu()
{
}
void Menu::salir(Game * jg){
	jg->setSalir();
}

void Menu::jugar(Game * jg){
	jg->changeState(new Play(jg, 1));  
}
void Menu::draw(){
	for (unsigned int i = 0; i < objetos.size(); i++) {
		if (objetos[i] != nullptr)
			objetos[i]->draw();
	}
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