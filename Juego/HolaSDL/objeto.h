#pragma once
#include "Game.h" // tiene que incluirse para que pueda heredar de raizObjeto, y para el puntero

class Objeto: public RaizObjeto 
{
public:
	Objeto();
	~Objeto();
	// Los m�todos de raizObjeto los hereda y no hace falta ponerlos aqui
	// A�n as� hay que poner otros m�todos aqu�
	int getx() { return pimgx; }
	int gety() { return pimgy; }
	virtual Direccion getDir() { return dir; };
	bool dentro(int x, int y) const;

protected: // son protegidas porque las subclases usan estas variables, si no ser�an privadas

	Game* juegootp;
	Game::Texturas_t Ttextura; // array de texturas (a�n no declarado en Juego)

	Direccion dir;
	bool destruido = false;
	int alto, ancho; // tama�o del objeto
	
	int pimgx, pimgy; //posici�n del objeto
};

