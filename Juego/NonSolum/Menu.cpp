#include "Menu.h"
#include "Button.h"
#include "Tienda.h"
#include "Survival.h"



Menu::Menu(Game * juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, 450, 0, Game::Boton_t::Historia, jugar));
	objetos.emplace_back(new Button(ptsjuego, 350, 100, Game::Boton_t::Supervivencia, survMode));

	objetos.emplace_back(new Button(ptsjuego, 250, 200, Game::Boton_t::Controles, control));
	objetos.emplace_back(new Button(ptsjuego, 150, 300, Game::Boton_t::Salir, salir));

	objetos.emplace_back(new Button(ptsjuego, 1050, 630, Game::Boton_t::Spanish, spa));
	objetos.emplace_back(new Button(ptsjuego, 850, 630, Game::Boton_t::English, eng));


	juego->sound->playMusic("../sounds/musicaMenuP.mp3", 2, 17);

	/*TTF_Init();
	font = new Texturas();
	font->loadFuente("../fonts/fuenteNumbers.ttf", 200);*/

}

Menu::~Menu() {
	
}

void Menu::jugar(Game * jg) {
	jg->sound->stopMusic();
	if (!jg->tiendaCreada) {
		jg->changeState(new Tienda(jg));
		jg->tiendaCreada = true;
	}
	else jg->popState();
	//shopSound = new Sound;
	//Problemas para crear musica en tienda ya que se necesita un miembro estatico.
}
void Menu::survMode(Game * jg) {
	jg->survival = true;
	jg->sound->stopMusic();
	jg->pushState(new Survival(jg));
	jg->sound->playMusic("../sounds/levasPolka.mp3", 5, 18);
	jg->sound->playEffect("../sounds/newRound.mp3", 0, 600, 4);
}

void Menu::salir(Game * jg){
	jg->setSalir();
}

