#pragma once
#include <string>

class Error 
{
public:
	Error(std::string mens);
	~Error(); // Hay que declararlo virtual si se hacen más subtipos de error
	const std::string& mensaje();

protected:
	std::string mailinfo;
};

