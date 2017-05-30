#include "FinNivel.h"
#include "Button.h"

FinNivel::FinNivel(Game* juego, bool v) :Estado(juego)
{		
	victory = v;
	if (v) {
		if (ptsjuego->getNivel() == 19)	objetos.emplace_back(new Button(ptsjuego, 550, 650, Game::Boton_t::Jugar, jugar));
		else objetos.emplace_back(new Button(ptsjuego, 550, 200, Game::Boton_t::Jugar, jugar));
	}

	else	objetos.emplace_back(new Button(ptsjuego, 550, 580, Game::Boton_t::Volver, jugar));

	initLibraries();
	TTF_Init();

	if (juego->sound != nullptr)  juego->sound->stopMusic();

	juego->sound->playMusic("../sounds/wonLevel.mp3", -1, 20);

	font = new Texturas();
	font->loadFuente("../fonts/fuenteNumbers.ttf", 200);

	fontColor = { 255, 255, 255 };
	if (v) {
		if (ptsjuego->getNivel() == 19) fondo = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::Fondo, Game::Fondo_t::History);
		else fondo = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::Fondo, Game::Fondo_t::Win);
	}
	else fondo = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::Fondo, Game::Fondo_t::Lose);

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
	if (ptsjuego->extrem){
		if (ptsjuego->spanish) font->loadFromText(ptsjuego->pRender, "Bien hecho, sobreviviste !", fontColor);
		else font->loadFromText(ptsjuego->pRender, "Well done, you have survived!", fontColor);
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(90, 450, 90, 30));
	}
	else {
		if (victory && ptsjuego->getNivel() != 19){
			if (ptsjuego->spanish) font->loadFromText(ptsjuego->pRender, "Bien hecho!", fontColor);
			else font->loadFromText(ptsjuego->pRender, "Well done!", fontColor);
			font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(90, 250, 90, 30));
		}
		else if (!victory){
			if (ptsjuego->spanish) font->loadFromText(ptsjuego->pRender, "Fallaste", fontColor);
			else font->loadFromText(ptsjuego->pRender, "Game over", fontColor);
			font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(90, 250, 580, 50));
		}
	}
	if (ptsjuego->getNivel() != 19 && !ptsjuego->survival) {
		if (ptsjuego->spanish) {
			if (!shown) {
				textoo = ptsjuego->chooseText(ptsjuego->arrTextSpa);
				shown = true;
			}
			font->loadFromText(ptsjuego->pRender, textoo, fontColor);
			font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, 700, 20, 670));
		}
		else {
			if (!shown) {
				textoo = ptsjuego->chooseText(ptsjuego->arrTextEng);
				shown = true;
			}
			font->loadFromText(ptsjuego->pRender, textoo, fontColor);
			font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, 700, 20, 670));

		}
	}
}