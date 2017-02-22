#include "objeto.h"



objeto::objeto()
{
}


objeto::~objeto()
{
}
void objeto::move(char c){
	if (c == 'W'){
		if (pimgy>=60)
		pimgy -= 5;
	}
	else if (c == 'S'){
		if (pimgy <= 530)
		pimgy += 5;
	}
}