#include "Menu.h"
#include "Button.h"
#include "Tienda.h"
#include "Survival.h"
#include "Extrem.h"



Menu::Menu(Game * juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, 570, 0, Game::Boton_t::Historia, jugar));
	objetos.emplace_back(new Button(ptsjuego, 470, 100, Game::Boton_t::Supervivencia, survMode));

	objetos.emplace_back(new Button(ptsjuego, 370, 200, Game::Boton_t::Extrem, extremo));
	objetos.emplace_back(new Button(ptsjuego, 220, 320, Game::Boton_t::Salir, salir));

	objetos.emplace_back(new Button(ptsjuego, 1050, 630, Game::Boton_t::Spanish, spa));
	objetos.emplace_back(new Button(ptsjuego, 850, 630, Game::Boton_t::English, eng));

	objetos.emplace_back(new Button(ptsjuego, 850, 430, Game::Boton_t::Desb, desb));

	juego->sound->playMusic("../sounds/musicaMenuP.mp3", -1, 17);

	fondo = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::Fondo, Game::Fondo_t::MenuP);

	font = new Texturas();
	font->loadFuente("../fonts/fuenteNumbers.ttf", 200);

	
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
	if (jg->getNivel() >= 9 || jg->desbloquear) {
		jg->survival = true;
		jg->sound->stopMusic();
		jg->pushState(new Survival(jg));
		jg->sound->playMusic("../sounds/levasPolka.mp3", -1, 18);
		jg->sound->playEffect("../sounds/newRound.mp3", 0, 600, 4);
	}	
}
void Menu::extremo(Game * jg) {
	if (jg->getNivel() >= 12 || jg->desbloquear) {
		jg->survival = true;
		jg->extrem = true;
		jg->sound->stopMusic();
		jg->pushState(new Extrem(jg));
		jg->sound->playMusic("../sounds/levasPolka.mp3", -1, 18);
		jg->sound->playEffect("../sounds/newRound.mp3", 0, 600, 4);
	}
}

void Menu::salir(Game * jg){
	jg->setSalir();
}

void Menu::draw(){
	fondo->draw();

	if (ptsjuego->getNivel()<9){
		if (ptsjuego->spanish) font->loadFromText(ptsjuego->pRender, "Llega al nivel 9 para desbloquear!!", fontColor);
		else font->loadFromText(ptsjuego->pRender, "Get level 9 to unlock!!", fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, 350, 100, 120));
	}
    if (ptsjuego->getNivel()<12){
		if (ptsjuego->spanish) font->loadFromText(ptsjuego->pRender, "Llega al nivel 12 para desbloquear!!", fontColor);
		else font->loadFromText(ptsjuego->pRender, "Get level 12 to unlock!!", fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, 350, 10, 230));
	}
	Estado::draw();
}