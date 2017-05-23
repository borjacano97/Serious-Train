#include "FinNivel.h"
#include "Button.h"

FinNivel::FinNivel(Game* juego, bool v) :Estado(juego)
{		
	victory = v;
	if (v) objetos.emplace_back(new Button(ptsjuego, 550, 200, Game::Boton_t::Jugar, jugar));
	else	objetos.emplace_back(new Button(ptsjuego, 550, 580, Game::Boton_t::Volver, jugar));

	initLibraries();
	TTF_Init();

	if (juego->sound != nullptr)  juego->sound->stopMusic();

	juego->sound->playMusic("../sounds/wonLevel.mp3", -1, 20);

	font = new Texturas();
	font->loadFuente("../fonts/fuenteNumbers.ttf", 200);

	fontColor = { 255, 255, 255 };
	if (v)	fondo = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::Fondo, Game::Fondo_t::Win);
	else fondo = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::Fondo, Game::Fondo_t::Lose);

	//textoo = juego->chooseText(juego->arrTextSpa);
}

void FinNivel::jugar(Game * jg) {
	jg->sound->stopMusic();
	jg->popState(); // vuelve a la tienda
}



bool FinNivel::initLibraries() {
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}
	return true;
}
void FinNivel::draw(){
	fondo->draw();
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
	if (ptsjuego->spanish){
		if (!shown){
			textoo = ptsjuego->chooseText(ptsjuego->arrTextSpa);
			shown = true;
		}
		font->loadFromText(ptsjuego->pRender, textoo, fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, 700, 20, 670));
	}
	else{
		if (!shown){
			textoo = ptsjuego->chooseText(ptsjuego->arrTextEng);
			shown = true;
		}
		font->loadFromText(ptsjuego->pRender, textoo, fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, 700, 20, 670));

	}
	
}