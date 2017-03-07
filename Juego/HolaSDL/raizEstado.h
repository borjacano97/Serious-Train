#pragma once
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
};

