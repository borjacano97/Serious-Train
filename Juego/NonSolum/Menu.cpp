#include "Menu.h"
#include "Button.h"
#include "Tienda.h"
#include "Survival.h"


Menu::Menu(Game * juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, 450, 0, Game::Boton_t::Historia, jugar));
	objetos.emplace_back(new Button(ptsjuego, 350, 100, Game::Boton_t::Supervivencia, survMode));
	objetos.emplace_back(new Button(ptsjuego, 250, 200, Game::Boton_t::Salir, salir));
	objetos.emplace_back(new Button(ptsjuego, 1050, 630, Game::Boton_t::Spanish, spa));
	objetos.emplace_back(new Button(ptsjuego, 850, 630, Game::Boton_t::English, eng));

	initLibraries();
	sound = new Sound;
	sound->playMusic("../sounds/musicaMenuP.mp3", 2, 12);
}

Menu::~Menu() {
	sound->stopMusic();
}

void Menu::jugar(Game * jg) {
	if (!jg->tiendaCreada) {
		jg->changeState(new Tienda(jg));
		jg->tiendaCreada = true;
	}
	else jg->popState();
	//shopSound = new Sound;
	//Problemas para crear musica en tienda ya que se necesita un miembro estatico.
}
void Menu::survMode(Game * jg) {
	jg->pushState(new Survival(jg));
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
