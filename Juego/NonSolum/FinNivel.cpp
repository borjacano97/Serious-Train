#include "FinNivel.h"
#include "Button.h"
#include "Tienda.h"

FinNivel::FinNivel(Game* juego, bool v) :Estado(juego)
{		
	victory = v;
	objetos.emplace_back(new Button(ptsjuego, 300, 600, Game::Boton_t::Jugar, jugar));
	initLibraries();

	if (juego->sound != nullptr)  juego->sound->stopMusic();

	juego->sound->playMusic("../sounds/wonLevel.mp3", -1, 20);

	font = new Texturas();
	font->loadFuente("../fonts/fuenteNumbers.ttf", 200);
}

void FinNivel::jugar(Game * jg) {
	if (jg->survival) jg->survival = false;
	if (jg->extrem) jg->extrem = false;
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
void FinNivel::draw(){
	for (auto i : objetos) {
		if (i != nullptr) {
			i->draw();
		}
	}
	if (victory){
		if (ptsjuego->spanish) font->loadFromText(ptsjuego->pRender, "Bien hecho!", fontColor);
		else font->loadFromText(ptsjuego->pRender, "Well done!", fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(90, 180, 90, 30));
	}
	else{
		if (ptsjuego->spanish) font->loadFromText(ptsjuego->pRender, "Fallaste", fontColor);
		else font->loadFromText(ptsjuego->pRender, "Game over", fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(90, 180, 580, 50));
	}
	
}