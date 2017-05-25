#include "PantallaInicio.h"
#include "Menu.h"


PantallaInicio::PantallaInicio(Game* juego) : Estado(juego)
{
	ptsjuego = juego;
	fondo = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::Fondo, Game::Fondo_t::FondoInicio);
	initLibraries();
	iniSound = new Sound;
	iniSound->playMusic("../sounds/iniSound.mp3",-1,17);
}


void PantallaInicio::draw() {
	fondo->draw();
	Estado::draw();
}

void PantallaInicio::update(Uint32 delta) {
	cont+= delta;
	if (cont >= 5000) {
		iniSound->stopMusic();
		ptsjuego->sound->playMusic("../sounds/musicaMenuP.mp3", -1, 17);
		ptsjuego->estados.push(new Menu(ptsjuego));
	}
}

bool PantallaInicio::initLibraries() {

	TTF_Init();

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}
	return true;
}
