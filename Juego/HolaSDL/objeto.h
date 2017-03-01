#pragma once
#include "game.h" // tiene que incluirse para que pueda heredar de raizObjeto, y para el puntero

class objeto: public raizObjeto 
{
public:
	objeto();
	~objeto();
	// Los m�todos de raizObjeto los hereda y no hace falta ponerlos aqui
	// A�n as� hay que poner otros m�todos aqu�
	int getx() { return pimgx; }
	int gety() { return pimgy; }
	virtual Direccion getDir() { return dir; };
	bool getI() { return izq; }
	bool dentro(int x, int y) const;

protected: // son protegidas porque las subclases usan estas variables, si no ser�an privadas

	game* juegootp;
	game::Texturas_t Ttextura; // array de texturas (a�n no declarado en Juego)
	
	bool izq;
	Direccion dir;
	bool destruido = false;
	int alto, ancho; // tama�o del objeto
	
	int pimgx, pimgy; //posici�n del objeto
};

