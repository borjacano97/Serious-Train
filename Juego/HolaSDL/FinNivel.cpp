#include "FinNivel.h"
#include "Button.h"
#include "Play.h"


FinNivel::FinNivel(Game* juego, bool v) :Estado(juego)
{		
	victory = v;
	if (victory) objetos.emplace_back(new Button(ptsjuego, Game::TBotonJ, 500, 500, jugar)); // hay que poner sdl_center o algo asi xd
	else objetos.emplace_back(new Button(ptsjuego, Game::TBotonS, 500, 500, salir));
}


FinNivel::~FinNivel()
{
}


void FinNivel::salir(Game * jg){
	jg->setSalir();
}

void FinNivel::jugar(Game * jg){
	jg->changeState(new Play(jg));
}
void FinNivel::draw(){
	for (unsigned int i = 0; i < objetos.size(); i++) {
		if (objetos[i] != nullptr)
			objetos[i]->draw();
	}
}
// ADVICE: HAY QUE DISPARAR AL MENOS UNA VEZ CON EL RATÓN EN PLAY PARA QUE FUNCIONE
// CORRECTAMENTE EL GAMEOVER, NO PREGUNTÉIS POR QUE
void FinNivel::onClick(){
	bool clickeado = false;

	int i = objetos.size() - 1;
	while (!clickeado && i >= 0)
	{
		if (objetos[i]->onClick())
			clickeado = true;
		i--;
	}

}