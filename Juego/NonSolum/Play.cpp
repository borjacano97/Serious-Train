#include "Play.h"
#include "Bala.h"
#include "Enemigo.h"
#include "Vagon.h"
#include "FinNivel.h"
#include "FinNivelSvl.h"
#include "Trigger.h"

#include <string>
#include <stdlib.h> // para nºs aleatorios
#include <time.h>

#include "Historia.h"

Play::Play(Game * j) : Estado(j)
{	
	//srand(time(NULL));
	//ptsjuego = j;
	initObjects();
	killed = 0;

	font = new Texturas(/*80, 80, 50, 50*/);
	font->loadFuente("../fonts/fuenteNumbers.ttf", 200);

	/*sonido = new Sound;
	sonido->playMusic("../sounds/prueba.mp3", 3, 20);
	/*soundLoss = new Sound;
	soundWon = new Sound;*/
	
	
	fontColor.r = 218;
	fontColor.g = 165;
	fontColor.b = 32;
	

	if (!ptsjuego->survival && (ptsjuego->getNivel()<=10) && (ptsjuego->getNivel() >= 7)){
		fontColor2.r = 218;
		fontColor2.g = 195;
		fontColor2.b = 150;
	}
	else {
		fontColor2.r = 218;
		fontColor2.g = 165;
		fontColor2.b = 32;
	}

	fontColor3.r = 255;
	fontColor3.g = 255;
	fontColor3.b = 255;

	textTut = new Texturas();
	textTut->loadFuente("../fonts/fuenteNumbers.ttf", 200);


	fin = false;

	//j->sound->playEffect("../sounds/trainEffect.mp3", -1, 15, 1);
}


Play::~Play()
{
	freeObjects();
	
}

bool Play::initObjects() { // creaci�n de los objetos dando un puntero, una textura y una posici�n (constructora de objs)

	
	h = new Hud(ptsjuego, this, -10, -20, Game::Hud_t::Hud1, Game::Fondo_t::Control);
	if (!ptsjuego->survival) {
		tray = new Hud(ptsjuego, this, 1200, 0, Game::Hud_t::Trayecto, Game::Fondo_t::Control);
		locom = new Hud(ptsjuego, this, 1223, 280, Game::Hud_t::Tren, Game::Fondo_t::Control);
	}	
	tg = new Trigger(ptsjuego, NULL, 530, -20);
	player = new Personaje(ptsjuego, Game::TPersonaje, 650, 500);
	TrainHp = new barraHP(ptsjuego, Game::TBarra, 123, 14);
	tren.emplace_back(new Vagon(ptsjuego, this, 580, -50, Game::Vagon_t::Locom));
	
	switch (ptsjuego->getNivel()%18)
	{
	case(1) :
	case(2) :
	case(3) :
			if (ptsjuego->survival)esc = new Escenario(ptsjuego, Game::Texturas_t::TFondo, 0, -4280);
			else  esc = new Escenario(ptsjuego, Game::Texturas_t::TPradera, 0, -4280);
		break;
	case(4) :
	case(5) :
	case(6) :
		     esc = new Escenario(ptsjuego, Game::Texturas_t::TFondo, 0, -4280);		    
		break;
	case(7) :
	case(8) :
	case(9) :
	case(10) :
	case(11) :
	case(12) :
		     if (ptsjuego->survival)esc = new Escenario(ptsjuego, Game::Texturas_t::TFondo, 0, -4280);
	         else  esc = new Escenario(ptsjuego, Game::Texturas_t::TDesierto, 0, -4280);
		break;
	case(13):
	case(14):
	case(15):
		     if (ptsjuego->survival)esc = new Escenario(ptsjuego, Game::Texturas_t::TFondo, 0, -4280);
		     else  esc = new Escenario(ptsjuego, Game::Texturas_t::TTramoRoca, 0, -4280);
		break;
	case(16) :
	case(17) :
	case(0) :
			 if (ptsjuego->survival)esc = new Escenario(ptsjuego, Game::Texturas_t::TFondo, 0, -4280);
			 else  esc = new Escenario(ptsjuego, Game::Texturas_t::TTramoFinal, 0, -4280);
		break;
	default:
		break;
	}

	b1 = new Button(ptsjuego, 950, 250, Game::Boton_t::Jugar, reanudar);
	b2 = new Button(ptsjuego, 950, 550, Game::Boton_t::Volver, salir);	
	fondoP = new Hud(ptsjuego, NULL, 0, 0, Game::Hud_t::Fondo, Game::Fondo_t::Pause);
	TTF_Init();
	
	return Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) != -1;
}

void Play::freeObjects() {
	// c++11
	TTF_Quit();
	for (auto o : tren) {
		delete o;
	}
	for (auto o : enems) {
		delete o;
	}
	for (auto b : balas) {
		delete b;
	}
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1;
}
void Play::draw() {
	esc->draw();

	for (auto i : tren) {
		i->draw();
	}
	for (auto i : enems) {
		if (i != nullptr) {
			i->draw();
		}
	}
	for (auto i : balas) {
		if (i != nullptr) {
			i->draw();
		}
	}

	player->draw();
	h->draw();


	if (!ptsjuego->survival) {
		switch (ptsjuego->getNivel()) {
		case(11):
		case(12):
			if (!ptsjuego->survival) {
				ptsjuego->texts[43]->setColor(255);
				ptsjuego->texts[43]->draw(ptsjuego->pRender, nullptr, nullptr); // nocheeeee
			}
			break;
		default:
			break;
		}
	}

	if (!ptsjuego->survival) {

		if (ptsjuego->spanish) {
			font->loadFromText(ptsjuego->pRender, " Nivel: " + std::to_string(ptsjuego->getNivel()), fontColor2);
		}
		else {
			font->loadFromText(ptsjuego->pRender, " Level: " + std::to_string(ptsjuego->getNivel()), fontColor2);
		}
		font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, 90, 300, 53));

	}
	// control de capa de noche en extrem 
	if (ptsjuego->extrem ) {
		if (contAlpha2 >= 1300 && alphaCont < 255) {
			contAlpha2 = 0;
			alphaCont++;
		}
		else contAlpha2 += d;
		ptsjuego->texts[43]->setColor(255 - alphaCont);
		ptsjuego->texts[43]->draw(ptsjuego->pRender, nullptr, nullptr);
	}
	// control de capa de noche en nvl 13
	else if (!ptsjuego->survival && ptsjuego->getNivel() == 13) {
		if (contAlpha2 >= 600 && alphaCont < 255) {
			contAlpha2 = 0;
			alphaCont++;
		}
		else contAlpha2 += d;
		ptsjuego->texts[43]->setColor(255 - alphaCont);
		ptsjuego->texts[43]->draw(ptsjuego->pRender, nullptr, nullptr);
	}
	// control de capa de noche en nvl 10
	else if (!ptsjuego->survival && ptsjuego->getNivel() == 10) {
		if (contAlpha2 >= 600 && alphaCont < 255) {
			contAlpha2 = 0;
			alphaCont++;
		}
		else contAlpha2 += d;
		ptsjuego->texts[43]->setColor(alphaCont);
		ptsjuego->texts[43]->draw(ptsjuego->pRender, nullptr, nullptr);
	}

	if (tray != nullptr) tray->draw();
	if (locom != nullptr) locom->draw();
	TrainHp->draw();
	if (armaActual != nullptr) armaActual->draw(); // quitar comprobación de nullptr si se traslada al modo Historia
	if (!ptsjuego->survival) {
		font->loadFromText(ptsjuego->pRender, "$ " + std::to_string(ptsjuego->coins), fontColor);
		int cosa = 50;
		if (ptsjuego->coins >= 1000) cosa = 80;
		if (ptsjuego->coins >= 10000) cosa = 110;
		if (ptsjuego->bigHP)font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, cosa , 150, 46));
		else font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, cosa, 150, 53));
	}

	if (!ptsjuego->survival && !tutorial && ptsjuego->getNivel() == 1) {

		if (enem < 1) {
			if (contTexto <= 4500) {
				if (ptsjuego->spanish) {
					textTut->loadFromText(ptsjuego->pRender, "Muevete con WASD!!", fontColor);
					textTut->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(35, 350, 50, 170));
				}
				else {
					textTut->loadFromText(ptsjuego->pRender, "Move with WASD!!", fontColor);
					textTut->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(35, 350, 50, 170));
				}
				contTexto += d;
			}
			else {
				if (ptsjuego->spanish) {
					textTut->loadFromText(ptsjuego->pRender, "Pausa el juego con ESC !!", fontColor);
					textTut->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(35, 350, 50, 170));
				}
				else {
					textTut->loadFromText(ptsjuego->pRender, "Pause the game with ESC !!", fontColor);
					textTut->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(35, 350, 50, 170));
				}
			}
		}
		else if (enem < 3) {
			if (ptsjuego->spanish) {
				textTut->loadFromText(ptsjuego->pRender, "Dispara con el raton!!", fontColor);
				textTut->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(35, 350, 50, 170));
			}
			else {
				textTut->loadFromText(ptsjuego->pRender, "Shoot with the mouse!", fontColor);
				textTut->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(35, 350, 50, 170));
			}
		}
	}

	if (ptsjuego->survival) {
		if (!ptsjuego->extrem) {
			if (ptsjuego->spanish) {
				font->loadFromText(ptsjuego->pRender, " Ronda: " + std::to_string(ptsjuego->contRondas), fontColor);
			}
			else {
				font->loadFromText(ptsjuego->pRender, " Round: " + std::to_string(ptsjuego->contRondas), fontColor);
			}

			font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(40, 90, 150, 53));


			if (newRonda && ptsjuego->spanish) {
				font->loadFromText(ptsjuego->pRender, " Nueva    Ronda:  " + std::to_string(ptsjuego->contRondas), fontColor);
				font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(220, 500, 400, 120));
			}
			if (newRonda && !ptsjuego->spanish) {
				font->loadFromText(ptsjuego->pRender, " New    Round:    " + std::to_string(ptsjuego->contRondas), fontColor);
				font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(220, 500, 400, 120));
			}
		}


		if (ptsjuego->extrem) {
			if (ptsjuego->spanish && enem < 2 && textInit < 2000) {
				font->loadFromText(ptsjuego->pRender, "A g u a n t a   h a s t a   e l   a m a n e c e r", fontColor);
				font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(130, 950, 140, 270));
			}
			if (!ptsjuego->spanish && enem < 2 && textInit < 2000) {
				font->loadFromText(ptsjuego->pRender, "S u r v i v e   u n t i l   d a w n", fontColor);
				font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(130, 950, 140, 270));
			}
		}
		else {
			if (ptsjuego->spanish && enem < 2 && textInit < 2000) {
				font->loadFromText(ptsjuego->pRender, "L o s   C o w b o y s   n a c e n ,   n o   s e   h a c e n", fontColor);
				font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(130, 950, 140, 270));
			}
			if (!ptsjuego->spanish && enem < 2 && textInit < 2000) {
				font->loadFromText(ptsjuego->pRender, "C o w b o y s   a r e   b o r n ,   t h e y   a i n t   m a d e", fontColor);
				font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(130, 950, 140, 270));
			}
		}
	}
	if (ptsjuego->paused) {
		fondoP->draw();
		if (ptsjuego->spanish) {
			textTut->loadFromText(ptsjuego->pRender, "PAUSA", fontColor3);
			textTut->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(100, 350, 150, 60));
		}
		else {
			textTut->loadFromText(ptsjuego->pRender, "PAUSE", fontColor3);
			textTut->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(100, 350, 150, 60));
		}
		b1->draw();
		b2->draw();
	}

}


void Play::update(Uint32 delta) {
	d = delta;
	textInit += delta;
	// no entiendo por que no me deja meterlo en la constructora :(
	if (!hist && !ptsjuego->survival) { 

		switch (ptsjuego->getNivel())
		{
		case 1:
		case 4:
		case 7:
		case 13:
		case 16:
			ptsjuego->pushState(new Historia(ptsjuego));
			break;
		default:
			break;
		}
		hist = true; // pa que no entre aqui tol puto rato		
	}

	if (locom != nullptr) locom->update(delta);
	esc->update(delta);
	for (auto i : tren) {
		i->update(delta);
	}

	for (auto i : balas) {
		if (i != nullptr) {
			i->update(delta);
		}
	}

	//if (tg->collision(player))	player->update(delta); //fuck, no va por la fucking move que tenemos de player
	player->update(delta);
	TrainHp->update(delta);
	if (TrainHp->getDest()) {
		if (ptsjuego->survival)ptsjuego->changeState(new FinNivelSvl(ptsjuego));
		else ptsjuego->changeState(new FinNivel(ptsjuego, false));
		soundLoss->playMusic("../sounds/lossLevel.mp3", -1, 20);
	}
	else if (fin){
			if (contWin >= 2000){
				ptsjuego->incrNivel();
				ptsjuego->changeState(new FinNivel(ptsjuego, true));
				soundWon->playMusic("../sounds/wonLevel.mp3", -1, 20);
			}
			else contWin += delta;
	}
	

	else {
		for (unsigned int i = 0; i < enems.size(); i++) {

			if (enems[i] != nullptr) {
				
				if (tg->collision(enems[i])) {
					
					TrainHp->damage(Game::EnemyDmg_t::Simple);
					enems[i]->parar();
					esc->ralentizar(delta);
				}
				
				enems[i]->update(delta);
			}
			if (enems[i] != nullptr && enems[i]->getDest()) {
				if (!ptsjuego->survival) ptsjuego->addCoins(enems[i]->getPoints());
				delete enems[i];
				enems[i] = nullptr;
				killed++;
			}
		}
		for (unsigned int j = 0; j < balas.size(); j++) {

			if (balas[j] != nullptr && balas[j]->getDest()) {
				delete balas[j];
				balas[j] = nullptr;
			}
		}
	}
	if (!roto && TrainHp->romper()){
		roto = true;
		for (auto i : tren) {
			i->romper();
		}
	}
	Estado::update(delta);
}
void Play::move(char c) {
	player->move(c); // El Dios de la programaci�n quiere suicidarse. Pero no puede, es inmortal.
}

void Play::onClick() {
	if (ptsjuego->paused) {
		bool clickeado = false;		

		if (b1->onClick() || b2->onClick())	clickeado = true;		
	}	
}
