#include "Historia.h"
#include "Button.h"

Historia::Historia(Game* juego) :Estado(juego)
{

	int posBotony;
	int posBotonx;
	switch (juego->getNivel())
	{
	case 1:
	case 7:
		posBotony = 480;
		posBotonx = 1050;
		break;
	case 4:
	case 10:
		posBotony = 600;
		posBotonx = 1000;
		break;
	case 13:
		posBotony = 580;
		posBotonx = 1050;
		break;
	default:
		break;
	}


	objetos.emplace_back(new Button(ptsjuego, posBotonx, posBotony, Game::Boton_t::Jugar, jugar));

	fondo = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::Fondo, Game::Fondo_t::Historia1);
	letras = new Hud(ptsjuego, NULL, 100, 720, Game::Hud_t::LetrasHist, Game::Fondo_t::Historia1);
}

void Historia::draw() {
	fondo->draw();
	letras->draw();
	Estado::draw();
	if (cont <= 250) {
		cont ++;
		ptsjuego->texts[43]->setColor(cont, cont, cont);
		ptsjuego->texts[43]->setColor(255 - cont);
		ptsjuego->texts[43]->draw(ptsjuego->pRender, nullptr, nullptr);
	}
}
void Historia::jugar(Game* juego) {
	juego->popState();
}
void Historia::update(Uint32 d) {
	letras->update(d);
}