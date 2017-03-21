#ifndef H_ERROR_H
#define H_ERROR_H

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
#endif

