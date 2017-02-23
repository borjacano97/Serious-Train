#pragma once
#include "game.h" // tiene que incluirse para que pueda heredar de raizObjeto, y para el puntero

class objeto: public raizObjeto 
{
public:
	objeto();
	~objeto();
	// Los métodos de raizObjeto los hereda y no hace falta ponerlos aqui
	// Aún así hay que poner otros métodos aquí
	int getx() { return pimgx; }
	int gety() { return pimgy; }
	bool getI() { return izq; }

protected: // son protegidas porque las subclases usan estas variables, si no serían privadas

	game* juegootp;
	game::Texturas_t Ttextura; // array de texturas (aún no declarado en Juego)
	
	bool izq;
	int alto, ancho; // tamaño del objeto

	int pimgx, pimgy; //posición del objeto
};

