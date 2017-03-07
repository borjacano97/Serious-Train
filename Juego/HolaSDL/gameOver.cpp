#include "GameOver.h"
#include "Button.h"
#include "Play.h"


GameOver::GameOver(Game* juego) :Estado(juego)
{	
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonJ, 300, 400, jugar));
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonS, 800, 400, salir));
}


GameOver::~GameOver()
{
}


void GameOver::salir(Game * jg){
	jg->setSalir();
}

void GameOver::jugar(Game * jg){
	jg->changeState(new Play(jg));
}
void GameOver::draw(){
	for (unsigned int i = 0; i < objetos.size(); i++) {
		if (objetos[i] != nullptr)
			objetos[i]->draw();
	}
}
// ADVICE: HAY QUE DISPARAR AL MENOS UNA VEZ CON EL RATÓN EN PLAY PARA QUE FUNCIONE
// CORRECTAMENTE EL GAMEOVER, NO PREGUNTÉIS POR QUE
void GameOver::onClick(){
	bool clickeado = false;

	int i = objetos.size() - 1;
	while (!clickeado && i >= 0)
	{
		if (objetos[i]->onClick())
			clickeado = true;
		i--;
	}

}