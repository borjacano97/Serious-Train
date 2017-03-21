#include "FinNivel.h"
#include "Button.h"
#include "Play.h"
#include "Nivel1.h"
#include "Nivel2.h"

FinNivel::FinNivel(Game* juego, bool v) :Estado(juego)
{		
	victory = v;
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonJ, 300, 500, jugar)); // hay que poner sdl_center o algo asi xd
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonS, 500, 500, salir));
}


FinNivel::~FinNivel()
{
}


void FinNivel::salir(Game * jg){
	jg->setSalir();
}

void FinNivel::jugar(Game * jg){
	jg->changeState(new Play(jg));
	switch (jg->getNivel())
		 {
		case(1): {
			jg->changeState(new Nivel1(jg));
			break;}
		case(2): {
			jg->changeState(new Nivel2(jg));
			break;}
		default:
			break;}
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