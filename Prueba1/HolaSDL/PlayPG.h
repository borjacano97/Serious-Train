#pragma once
#include "EstadoPG.h"

class PlayPG: public EstadoPG
{
public:
	PlayPG(JuegoPG * juego);
	~PlayPG();


	void newBaja(ObjetoJuego* po); 
	void newPuntos(ObjetoJuego* po); 
	void newPremio(); 
	void update();


private:
	int numglobos;
	int numglobosA;
	int finglobos;
	bool initGlobos();
	void freeGlobos();
	int points;
};

