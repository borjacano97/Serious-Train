#include "Pausa.h"
#include "Button.h"
#include "Play.h"


Pausa::Pausa(Game* juego) : Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonJ, 300, 500, reanudar)); // hay que poner sdl_center o algo asi xd
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonS, 500, 500, salir));
}


Pausa::~Pausa()
{
}

void Pausa::salir(Game * jg){
	jg->setSalir();
}

void Pausa::reanudar(Game * jg){
	jg->popState();
}
void Pausa::draw(){
	for (unsigned int i = 0; i < objetos.size(); i++) {
		if (objetos[i] != nullptr)
			objetos[i]->draw();
	}
}
void Pausa::update(Uint32 delta){
	for (unsigned int i = 0; i < objetos.size(); i++) {
		if (objetos[i] != nullptr)
			objetos[i]->update(delta);
	}
}

void Pausa::onClick(){
	bool clickeado = false;

	int i = objetos.size() - 1;
	while (!clickeado && i >= 0)
	{
		if (objetos[i]->onClick())
			clickeado = true;
		i--;
	}

}
