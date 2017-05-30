#include "Creditos.h"
#include "Menu.h"


Creditos::Creditos(Game* juego) :Estado(juego)
{
	letras = new Hud(ptsjuego, NULL, 230, 720, Game::Hud_t::Creditos, Game::Fondo_t::History);
}
void Creditos::draw(){
	ptsjuego->texts[91]->draw(ptsjuego->pRender, nullptr, nullptr);
	letras->draw();
}
void Creditos::update(Uint32 d){
	letras->update(d);
	if (conTiempo >= 35000){
		ptsjuego->popState();
	}
	else conTiempo += d;
}
