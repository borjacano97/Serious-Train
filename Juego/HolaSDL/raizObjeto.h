#pragma once
class raizObjeto
{
public:

	raizObjeto()
	{
	}
	
	virtual ~raizObjeto()
	{
	}
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void onClick() = 0;
	virtual void move(char c) = 0;
	virtual int getx() = 0;
	virtual int gety() = 0;
	virtual bool getI() = 0;
	virtual char getId() = 0;
	virtual bool getDest() = 0;
};

