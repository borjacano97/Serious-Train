#include "PlayPG.h"
#include "Globo.h"
#include "GloboA.h"
#include "Premio.h"
#include "Mariposa.h"
#include "GameOver.h"

PlayPG::PlayPG(JuegoPG * juego) : EstadoPG(juego) 
{
	numglobos = 3;
	numglobosA = 3;
	finglobos = 6;
	points = 0;
	initGlobos();
}


PlayPG::~PlayPG()
{
	ptsjuego->darPuntos(points);
	freeGlobos();
}

void PlayPG::newBaja(ObjetoJuego* po){
	if (static_cast<Globo*>(po) != nullptr)
		finglobos--;
}

void PlayPG::newPuntos(ObjetoJuego* po){

	points += static_cast<ObjetoPG*>(po)->damePuntos();
	
}

void PlayPG::newPremio(){
	dynamic_cast<Premio*>(objetos[numglobos + numglobosA])->reiniciaPremio();
}




bool PlayPG::initGlobos(){
	
	//globos.emplace_back(new Globo(this, TGlobo, /*rand() % 700, rand() % 700*/alto / 2, ancho / 2)); //evaluacion1

	
	for (int i = 0; i < numglobos + numglobosA; i++) { // aleatorio punto 2
		//int x = rand() % 2; // entre 0 y 1
		//if (x == 0)
			objetos.emplace_back(new Globo(ptsjuego, JuegoPG::TGlobo, rand() % 1500, rand() % 800));
		//else
			//objetos.emplace_back(new GloboA(ptsjuego, JuegoPG::TGlobo, rand() % 700, rand() % 700));
	}
	
	objetos.emplace_back(new Premio(ptsjuego, JuegoPG::TPremio, rand() % 1500, rand() % 800));

	objetos.emplace_back(new Mariposa(ptsjuego, JuegoPG::TMariposa, rand() % 1500, rand() % 800));
	objetos.emplace_back(new Mariposa(ptsjuego, JuegoPG::TMariposa, rand() % 1500, rand() % 800));



	return true;
}

void PlayPG::freeGlobos(){
	// lo mismo que en las texturas, borramos los globos y hacemos nulo el puntero
	// en la práctica 2, este array no sólo tiene globos, asi que con el método son destruidos 
	// todos los objetos

	for (int i = 0; i < objetos.size(); i++){
		delete objetos[i];
		objetos[i] = nullptr;

	}
	for (int i = 0; i < objetos.size(); i++){
		delete objetos[i];
		objetos[i] = nullptr;

	}
}

void PlayPG::update(){

	if (finglobos == 0){
		
		ptsjuego->changeState(new GameOver(ptsjuego));
		
	}
	else
		EstadoPG::update();
}

