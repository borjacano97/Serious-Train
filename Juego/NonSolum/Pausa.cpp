#include "Pausa.h"
#include "Button.h"
#include "Play.h"


Pausa::Pausa(Game* juego) : Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, 140, 250, Game::Boton_t::Volver, salir));
	//objetos.emplace_back(new Button(ptsjuego, 550, 500, Game::Boton_t::Controles, control));
	objetos.emplace_back(new Button(ptsjuego, 920, 250, Game::Boton_t::Jugar, reanudar));

	fondo = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::Fondo, Game::Fondo_t::Pause);

	font = new Texturas();
	font->loadFuente("../fonts/fuenteNumbers.ttf", 200);
	fontColor.r = 255;
	fontColor.g = 255;
	fontColor.b = 255;
}

void Pausa::reanudar(Game * jg) {
	jg->popState();
}
void Pausa::salir(Game * jg){
	jg->survival = false;
	jg->extrem = false;
	jg->popState();
	jg->popState();
}

bool Pausa::initLibraries() {
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}
	return true;
}
void Pausa::draw(){
	fondo->draw();

	if (ptsjuego->spanish) font->loadFromText(ptsjuego->pRender, "Pausa", fontColor);
	else font->loadFromText(ptsjuego->pRender, "Pause", fontColor);
	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(90, 180, 500, 30));

	Estado::draw();
}