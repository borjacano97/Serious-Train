#include "Button.h"


Button::Button(Game* juego,  float x, float y, Game::Boton_t tipo, CallBack_t * cbCons)
{
	TTF_Init();

	juegootp = juego;
	t = tipo;

	pos.set(x, y);

	alto = 90;
	ancho = 200;


	cb = cbCons;

	texto = new Texturas();
	texto->loadFuente("../fonts/fuenteNumbers.ttf", 250);

	fontColor.r = 218;
	fontColor.g = 218;
	fontColor.b = 218;
	switch (t)
	{	
	case Game::Jugar:Ttextura = Game::Texturas_t::TBotonV;
		break;
	case Game::Salir: Ttextura = Game::Texturas_t::TBotonR;
		break;
	case Game::Supervivencia: Ttextura = Game::Texturas_t::TBotonV;
		break;
	case Game::Historia:Ttextura = Game::Texturas_t::TBotonV;
		break;
	case Game::Volver:Ttextura = Game::Texturas_t::TBotonR;
		break;
	case Game::Controles:Ttextura = Game::Texturas_t::TBotonA;
		break;
	case Game::Spanish: 
		textB = "Spanish";
		Ttextura = Game::Texturas_t::TBotonA;
		break;
	case Game::English: 
		textB = "English";
		Ttextura = Game::Texturas_t::TBotonA;
		break;

	case Game::Mute:
		Ttextura = Game::Texturas_t::TBotonMute;
		break;

	case Game::Unmute:
		Ttextura = Game::Texturas_t::TBotonMuteado;
		break;
	default:
		break;
	}
}

bool Button::onClick(){
	juegootp->getMousePos(mpbx, mpby);

	juegootp->sound->playEffect("../sounds/buttonSound.mp3", 0, 100, 2);
	std::cout << "EYYY: " << clickado;
	if (dentro(mpbx, mpby)){
		if (t == Game::Mute && !clickado){
			Ttextura = Game::Texturas_t::TBotonMuteado;
			clickado = true;
			std::cout << "EYYY: " << clickado;
		}

		else if (Ttextura == Game::Texturas_t::TBotonMuteado && clickado)
		{
			Ttextura = Game::Texturas_t::TBotonMute;
			clickado = false;
		}
		/*if (t == Game::Unmute && !clickado){
			Ttextura = Game::Texturas_t::TBotonMute;
			clickado = false;
		}*/
		cb(juegootp);
		return true;
	}
	else return false;
}
void Button::draw() {
	

	switch (t)
	{
	case Game::Jugar:
		if (juegootp->spanish)	textB = "Continuar";
		else textB = "Continue";
		break;
	case Game::Salir:
		if (juegootp->spanish) textB = "Salir";
		else textB = "Exit";
		break;
	case Game::Supervivencia:
		if (juegootp->spanish) textB = "Supervivencia";
		else textB = "Survival";
		break;
	case Game::Historia:
		if (juegootp->spanish) textB = "Historia";
		else textB = "The Story";
		break;
	case Game::Volver:
		if (juegootp->spanish) textB = "Volver";
		else textB = "Back";
		break;
	case Game::Controles:
		if (juegootp->spanish) textB = "Controles";
		else textB = "Controls";
		break;

	case Game::Mute:
		ancho = 60;
		alto = 60;
		break;

	case Game::Unmute:
		ancho = 60;
		alto = 60;
		break;
	default:
		break;

	}
	rect.h = alto;
	rect.w = ancho;
	rect.x = pos.x;
	rect.y = pos.y;
	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);
	if (textB == "Supervivencia")h = 120;
	else h = 90;
	texto->draw(juegootp->pRender, nullptr, &texto->myFont.setRect(a, h, this->pos.x + 60, this->pos.y + 24));
	texto->loadFromText(juegootp->pRender, textB , fontColor);
}
