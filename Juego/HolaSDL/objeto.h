#pragma once
#include "Game.h" // tiene que incluirse para que pueda heredar de raizObjeto, y para el puntero

class Objeto: public RaizObjeto 
{
public:
	Objeto();
	~Objeto();
	// Los métodos de raizObjeto los hereda y no hace falta ponerlos aqui
	// Aún así hay que poner otros métodos aquí
	int getx() { return pimgx; }
	int gety() { return pimgy; }
	virtual Direccion getDir() { return dir; };
	bool dentro(int x, int y) const;

protected: // son protegidas porque las subclases usan estas variables, si no serían privadas

	Game* juegootp;
	Game::Texturas_t Ttextura; // array de texturas (aún no declarado en Juego)

	Direccion dir;
	bool destruido = false;
	int alto, ancho; // tamaño del objeto
	
	int pimgx, pimgy; //posición del objeto
};

