#pragma once
#include "Juego.h" // tiene que incluirse para que pueda heredar de raizObjeto, y para el puntero

class objeto: public raizObjeto 
{
public:
	objeto();
	~objeto();
	// Los m�todos de raizObjeto los hereda y no hace falta ponerlos aqui
	// A�n as� hay que poner otros m�todos aqu�
	void move(char c);
protected: // son protegidas porque las subclases usan estas variables, si no ser�an privadas

	Juego* juegootp;
	Juego::Texturas_t Ttextura; // array de texturas (a�n no declarado en Juego)
		
	int alto, ancho; // tama�o del objeto

	int pimgx, pimgy; //posici�n del objeto
};

