#ifndef H_OBJETO_H
#define H_OBJETO_H

#include "Game.h" // tiene que incluirse para que pueda heredar de raizObjeto, y para el puntero

class Objeto: public RaizObjeto 
{
public:
	Objeto();
	~Objeto();
	// Los m�todos de raizObjeto los hereda y no hace falta ponerlos aqui
	// A�n as� hay que poner otros m�todos aqu�
	void draw();
	void update(Uint32 delta){}
	bool onClick() { return true; }
	void move(char c){}
	virtual Direccion getDir() { return dir; };
	Posicion getPos(){ return pos; }
	bool getDest() { return destruido; }
	void destroy() { destruido = true; }
	bool collision(RaizObjeto* other);
	int getPoints() { return 0; }
	
	bool dentro(int x, int y) const;
	Posicion pos; //posici�n del objeto
protected: // son protegidas porque las subclases usan estas variables, si no ser�an privadas
	SDL_Rect rect;
	Game* juegootp;
	Game::Texturas_t Ttextura; // array de texturas (a�n no declarado en Juego)

	
	Direccion dir;
	bool destruido = false;
	int alto, ancho, anchoc; // tama�o del objeto
};


#endif