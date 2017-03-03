#include "gameOver.h"
#include "button.h"
#include "play.h"


gameOver::gameOver(Game* juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, Game::TBoton, 800, 400, salir));
	objetos.emplace_back(new Button(ptsjuego, Game::TBoton, 300, 400, jugar));
}


gameOver::~gameOver()
{
}


void gameOver::salir(Game * jg){
	jg->setSalir();
}

void gameOver::jugar(Game * jg){
	jg->changeState(new Play(jg));
}

void gameOver::onClick(){
	bool clickeado = false;

	int i = objetos.size() - 1;
	while (!clickeado && i >= 0)
	{
		if (objetos[i]->onClick())
			clickeado = true;
		i--;
	}

}