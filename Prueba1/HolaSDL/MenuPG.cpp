#include "MenuPG.h"
#include "PlayPG.h"
#include "Boton.h"

MenuPG::MenuPG(JuegoPG * juego) :EstadoPG(juego)
{
	objetos.emplace_back(new Boton(ptsjuego, JuegoPG::BSalir, 800, 400, salir));
	objetos.emplace_back(new Boton(ptsjuego, JuegoPG::BJugar, 400, 400, play));

}


MenuPG::~MenuPG()
{
}


void MenuPG::salir(JuegoPG * jg){
	jg->setSalir();
}

void MenuPG::play(JuegoPG * jg){
	jg->changeState(new PlayPG (jg));
}