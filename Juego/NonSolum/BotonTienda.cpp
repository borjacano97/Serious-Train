#include "BotonTienda.h"
#include "Tienda.h"


BotonTienda::BotonTienda(Game* juego, Tienda*ti, ObjetoTienda*obj, Game::Texturas_t text, float x, float y, Game::Boton_t tipo)
{
	TTF_Init();

	juegootp = juego;
	t = ti;
	o = obj;
	
	Ttextura = text;
	if (tipo == Game::Boton_t::Comprar) {
		alto = 40;
		ancho = 90;
		textB = "";
	}
	else if (tipo == Game::Boton_t::Salir) {

		alto = 80;
		ancho = 130;
		textB = "Salir";
	}
	else if (tipo == Game::Boton_t::Recolocar) {

		alto = 100;
		ancho = 190;
		textB = "Recolocar";
	}
	else if (tipo == Game::Boton_t::Jugar) {

		alto = 100;
		ancho = 190;
		textB = "Jugar";
	}
	

	pos.set(x, y);
	tip = tipo;

	destruido = false;

	texto = new Texturas();
	texto->loadFuente("../fonts/fuenteNumbers.ttf", 250);

	fontColor.r = 218;
	fontColor.g = 218;
	fontColor.b = 218;
}

bool BotonTienda::onClick() {
	juegootp->getMousePos(mpbx, mpby);

	if (dentro(mpbx, mpby)) {
		switch (tip)
		{
		case Game::Comprar:
			if (o->getBloq() && o->getPrecio() <= juegootp->coins) {
				t->comprar(o);
				destruido = true;
			}
			break;
		case Game::Jugar:
			t->jugar(juegootp);
			break;
		case Game::Recolocar:
			t->recolocar(juegootp);
			break;
		case Game::Salir:
			t->salir(juegootp);
			break;
		default:
			break;
		}			
		return true;
	}
	else return false;
}

void BotonTienda::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pos.x;
	rect.y = pos.y;
	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);

	texto->draw(juegootp->pRender, nullptr, &texto->myFont.setRect(40, 70, this->pos.x + 70, this->pos.y + 30));
	texto->loadFromText(juegootp->pRender, textB, fontColor);
}