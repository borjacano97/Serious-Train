#ifndef H_ESTADO_H
#define H_ESTADO_H

#include "Game.h" 
using namespace std;
class Estado: public RaizEstado
{
public:
	Estado(Game * j);
	~Estado();
	Estado_t getEstado() { return estado; }
	void draw();
	void onClick();
	void update(Uint32 d){}
	virtual bool handle_events(SDL_Event * evento);
	void getMousePos(int& x, int& y) { 
	//	cout << "Método copia\nx antes de copiar: " <<x<<"y antes de copiar"<<y<<endl;
	//	cout<< "mx, my" << mx <<", "<< my<<endl;
		x = mx, y = my; 
	//	cout << "x, y depues de copiar: " << x << ", " << y << endl;
	//	cout<<"Fin método copia" << endl;
	}


	std::vector <RaizObjeto*> objetos; // objetos que contiene cada estado	
protected:
	int mx, my;
	Estado_t estado;
	Game* ptsjuego;
};


#endif