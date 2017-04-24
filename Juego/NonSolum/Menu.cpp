#include "Menu.h"
#include "Button.h"
#include "Tienda.h"


Menu::Menu(Game * juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonJ, 100, 100, jugar));
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonS, 300, 200, salir));
	initLibraries();
	sound = new Sound;
	sound->playMusic("../sounds/menuMusic1.mp3", 2);
	
}

Menu::~Menu() {
	sound->stopMusic();
}

void Menu::jugar(Game * jg) {
	jg->changeState(new Tienda(jg));
	//shopSound = new Sound;
	//Problemas para crear musica en tienda ya que se necesita un miembro estatico.
}
	

void Menu::salir(Game * jg){
	jg->setSalir();
}
bool Menu::initLibraries() {
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}
	return true;
}
