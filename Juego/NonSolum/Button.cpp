#include "Button.h"


Button::Button(Game* juego, Game::Texturas_t text, float x, float y, Game::Boton_t tipo, CallBack_t * cbCons)
{
	TTF_Init();

	juegootp = juego;
	t = tipo;

	pos.set(x, y);

	alto = 100;
	ancho = 200;

	Ttextura = text;

	cb = cbCons;

	texto = new Texturas();
	texto->loadFuente("../fonts/fuenteNumbers.ttf", 250);

	fontColor.r = 218;
	fontColor.g = 218;
	fontColor.b = 218;
	switch (t)
	{	
	case Game::Jugar: textB = "Continuar";
		break;
	case Game::Salir:  textB = "Salir";
		break;
	case Game::Supervivencia:  textB = "Supervivencia";
		break;
	case Game::Historia:  textB = "Historia";
		break;
	default:
		break;
	}
}

bool Button::onClick(){
	juegootp->getMousePos(mpbx, mpby);

	if (dentro(mpbx, mpby)){
		cb(juegootp);
		return true;
	}
	else return false;
}
void Button::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pos.x;
	rect.y = pos.y;
	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);

	texto->draw(juegootp->pRender, nullptr, &texto->myFont.setRect(40, 70, this->pos.x +70, this->pos.y + 30));
	texto->loadFromText(juegootp->pRender, textB , fontColor);
}
