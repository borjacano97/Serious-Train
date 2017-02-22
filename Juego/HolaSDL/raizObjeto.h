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
	virtual bool onClick() = 0;
	virtual void move(char c) = 0;
};

