#include "menu.h"
#include "button.h"
#include "play.h"


menu::menu(game * juego) :estado(juego)
{
	objetos.emplace_back(new button(ptsjuego, game::TBoton, 500, 400, salir));
	objetos.emplace_back(new button(ptsjuego, game::TBoton, 200, 400, jugar));
}


menu::~menu()
{
}
void menu::salir(game * jg){
	jg->setSalir();
}

void menu::jugar(game * jg){
	jg->changeState(new play(jg));  
}

void menu::onClick(){
	bool clickeado = false;

	int i = objetos.size() - 1;
	while (!clickeado && i >= 0)
	{
		if (objetos[i]->onClick())
			clickeado = true;
		i--;
	}

}