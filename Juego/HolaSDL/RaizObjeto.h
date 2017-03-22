#ifndef H_RAIZOBJETO_H
#define H_RAIZOBJETO_H

class RaizObjeto
{

public:
	class Direccion {
	public:
		int x, y;
		Direccion() :x(0), y(0) {};
		Direccion(int a, int b) :x(a), y(b) {};
		~Direccion() {};
		
		void operator=(Direccion &other) {
			this->x = other.x;
			this->y = other.y;
		}

		Direccion set(int a, int b) { x = a; y = b; };

	};
public:
	RaizObjeto(){}
	virtual ~RaizObjeto(){}

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual bool onClick() = 0;
	virtual void move(char c) = 0;
	virtual int getx() = 0;
	virtual int gety() = 0;
	virtual Direccion getDir() = 0;
	virtual char getId() = 0;
	virtual bool getDest() = 0;
	virtual void destroy() = 0;
};


#endif