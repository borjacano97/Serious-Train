#include "FinNivelSvl.h"
#include "Button.h"
#include "Menu.h"


FinNivelSvl::FinNivelSvl(Game* juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, 550, 500, Game::Boton_t::Volver, volver));
	TTF_Init();

	if (juego->sound != nullptr)  juego->sound->stopMusic();

	juego->sound->playMusic("../sounds/wonLevel.mp3", -1, 20);

	font = new Texturas();
	font->loadFuente("../fonts/fuenteNumbers.ttf", 200);

	fontColor = { 255, 255, 255 };
	fondo = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::Fondo, Game::Fondo_t::Lose);
}

void FinNivelSvl::volver(Game * jg) {
	jg->sound->stopMusic();
	jg->survival = false;
	jg->extrem = false;

	jg->changeState(new Menu(jg)); // vuelve al menu
}
void FinNivelSvl::draw(){
	fondo->draw();
	for (auto i : objetos) {
		if (i != nullptr) {
			i->draw();
		}
	}
	string text1 = " rondas!!";
	string text2 = " rounds!!";
	if (ptsjuego->contRondas == 1) {
		text1 = " ronda!!"; 
		text2 = " round!!";
	}
	if (ptsjuego->spanish) font->loadFromText(ptsjuego->pRender, "Has aguantado " + to_string(ptsjuego->contRondas) + text1, fontColor);
	else font->loadFromText(ptsjuego->pRender, "You have survived " + to_string(ptsjuego->contRondas) + text2, fontColor);
	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(60, 380, 480, 50));
	
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