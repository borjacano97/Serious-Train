#include "Menu.h"
#include "Button.h"
#include "Tienda.h"
#include "Survival.h"
#include "Extrem.h"



Menu::Menu(Game * juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, 450, 0, Game::Boton_t::Historia, jugar));
	objetos.emplace_back(new Button(ptsjuego, 350, 100, Game::Boton_t::Supervivencia, survMode));

	objetos.emplace_back(new Button(ptsjuego, 250, 200, Game::Boton_t::Extrem, extremo));
	objetos.emplace_back(new Button(ptsjuego, 120, 320, Game::Boton_t::Salir, salir));

	objetos.emplace_back(new Button(ptsjuego, 1050, 630, Game::Boton_t::Spanish, spa));
	objetos.emplace_back(new Button(ptsjuego, 850, 630, Game::Boton_t::English, eng));


	juego->sound->playMusic("../sounds/musicaMenuP.mp3", -1, 17);

	fondo = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::Fondo, Game::Fondo_t::MenuP);

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
	jg->sound->playMusic("../sounds/levasPolka.mp3", -1, 18);
	jg->sound->playEffect("../sounds/newRound.mp3", 0, 600, 4);
}
void Menu::extremo(Game * jg) {
	jg->survival = true;
	jg->extrem = true;
	jg->sound->stopMusic();
	jg->pushState(new Extrem(jg));
	jg->sound->playMusic("../sounds/levasPolka.mp3", -1, 18);
	jg->sound->playEffect("../sounds/newRound.mp3", 0, 600, 4);
}

void Menu::salir(Game * jg){
	jg->setSalir();
}

void Menu::draw(){
	fondo->draw();
	Estado::draw();
}