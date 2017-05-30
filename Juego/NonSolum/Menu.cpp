#include "Menu.h"
#include "Button.h"
#include "Tienda.h"
#include "Survival.h"



Menu::Menu(Game * juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, 570, 0, Game::Boton_t::Historia, jugar));
	objetos.emplace_back(new Button(ptsjuego, 470, 100, Game::Boton_t::Supervivencia, survMode));

	objetos.emplace_back(new Button(ptsjuego, 370, 200, Game::Boton_t::Extrem, extremo));
	objetos.emplace_back(new Button(ptsjuego, 220, 320, Game::Boton_t::Salir, salir));

	objetos.emplace_back(new Button(ptsjuego, 1050, 630, Game::Boton_t::Spanish, spa));
	objetos.emplace_back(new Button(ptsjuego, 850, 630, Game::Boton_t::English, eng));

	//objetos.emplace_back(new Button(ptsjuego, 850, 430, Game::Boton_t::Desb, desb));


	fondo = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::Fondo, Game::Fondo_t::MenuP);

	font = new Texturas();
	font->loadFuente("../fonts/fuenteNumbers.ttf", 200);

	fontColor2.r = 205;
	fontColor2.g = 205;
	fontColor2.b = 205;

	ptsjuego->sound->playMusic("../sounds/musicaMenuP.mp3", -1, 6);
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
		jg->bigHP = false;
		jg->survival = true;
		jg->sound->stopMusic();
		jg->changeState(new Survival(jg));
		jg->sound->playMusic("../sounds/survivalMusic.mp3", -1, 200);
	}	
}
void Menu::extremo(Game * jg) {
	if (jg->getNivel() >= 19 || jg->desbloquear) {
		jg->bigHP = false;
		jg->survival = true;
		jg->extrem = true;
		jg->sound->stopMusic();
		jg->changeState(new Survival(jg));
		jg->sound->playMusic("../sounds/survivalMusic.mp3", -1, 200);
	}
}

void Menu::salir(Game * jg){
	jg->setSalir();
}

void Menu::draw(){
	fondo->draw();

	font->loadFromText(ptsjuego->pRender, "Version 1.0", fontColor2);
	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(30, 80, 10, 680));

	font->loadFromText(ptsjuego->pRender, "NON", fontColor2);
	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(100, 250, 850, 80));
	font->loadFromText(ptsjuego->pRender, "SOLUM", fontColor2);
	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(100, 350, 800, 200));

	if (ptsjuego->getNivel()<9){
		font->loadFromText(ptsjuego->pRender, "(lvl 9)", fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, 150, 280, 120));
	}
    if (ptsjuego->getNivel()<19){
		font->loadFromText(ptsjuego->pRender, "(lvl 19)", fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, 150, 180, 230));
	}
	Estado::draw();

	if (cont <= 250) {
		cont+=5;
		ptsjuego->texts[43]->setColor(cont, cont, cont);
		ptsjuego->texts[43]->setColor(255 - cont);
		ptsjuego->texts[43]->draw(ptsjuego->pRender, nullptr, nullptr);
	}	
}