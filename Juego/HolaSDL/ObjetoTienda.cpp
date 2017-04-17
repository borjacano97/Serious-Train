#include "ObjetoTienda.h"
#include "Tienda.h"
//#include "Font.h"

ObjetoTienda::ObjetoTienda(Game* juego, Tienda* ti, float x, float y, int p, Game::Vagon_t tipo, bool est)
{
	TTF_Init();

	juegootp = juego;
	t = ti;

	Ttextura = Game::Texturas_t::TVacioBloq;

	alto = 130;
	ancho = 95;
	precio = p;

	pos.set(x, y);

	tip = tipo;


	puntosText = new Texturas();
	puntosText->loadFuente("../fonts/AlexBrush-Regular.ttf", 400);

	fontColor.r = 218;
	fontColor.g = 165;
	fontColor.b = 32;

	//std::cout << "Mis puntos: " << &puntosText << std::endl;

	estatico = est;
	switch (tipo)
	{
	case Game::Automatico: desb = Game::Texturas_t::TVagonAuto;
		break;
	case Game::Laser: desb = Game::Texturas_t::TVagon1;
		break;
	case Game::Lanzallamas: desb = Game::Texturas_t::TVagon1;
		break;
	default:
		break;
	}
	if (estatico) Ttextura = desb;

}
bool ObjetoTienda::onClick() {
	juegootp->getMousePos(mpbx, mpby);

	if (dentro(mpbx, mpby)) {
		if (!bloqueado && !usado) {
			usado = true;
			t->colocarVagon(tip);

		}
		return true;
	}

	else return false;
}


void ObjetoTienda::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pos.x;
	rect.y = pos.y;
	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);
	if (bloqueado) {
		puntosText->draw(juegootp->pRender, nullptr, &puntosText->myFont.setRect(50, 45, this->pos.x + 25, this->pos.y + 85));
		puntosText->loadFromText(juegootp->pRender, std::to_string(precio), fontColor);
	}
	else {
		puntosText->draw(juegootp->pRender, nullptr, &puntosText->myFont.setRect(50, 45, mpbx, mpby));
		puntosText->loadFromText(juegootp->pRender, " ", fontColor);
	}

}