#pragma once
#include <string>

class error 
{
public:
	error(std::string mens);
	~error(); // Hay que declararlo virtual si se hacen m�s subtipos de error
	const std::string& mensaje();

protected:
	std::string mailinfo;
};

