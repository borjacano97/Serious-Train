#include "FinNivel.h"
#include "Button.h"
#include "Tienda.h"

FinNivel::FinNivel(Game* juego, bool v) :Estado(juego)
{		
	victory = v;
	objetos.emplace_back(new Button(ptsjuego, 300, 600, Game::Boton_t::Jugar, jugar));
	initLibraries();

	if (juego->sound != nullptr)  juego->sound->stopMusic();

	juego->sound->playMusic("../sounds/wonLevel.mp3", 2, 20);
}

void FinNivel::jugar(Game * jg) {
	if (jg->survival) jg->survival = false;
	jg->sound->stopMusic();
	jg->popState(); // vuelve a la tienda
}

void FinNivel::salir(Game * jg){
	jg->sound->stopMusic();
	jg->setSalir();
}

bool FinNivel::initLibraries() {
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}
	return true;
}