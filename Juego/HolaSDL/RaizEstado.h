#ifndef H_RAIZESTADO_H
#define H_RAIZESTADO_H

class RaizEstado
{
public:

	RaizEstado()
	{
	}

	virtual ~RaizEstado()
	{
	}
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void onClick() = 0;
	virtual void move(char c) = 0;
	virtual char getEst() = 0;
};


#endif