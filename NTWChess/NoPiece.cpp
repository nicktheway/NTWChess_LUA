#include "NoPiece.h"
#include <iostream>

NoPiece::NoPiece()
{
	type = EPTNothing;
}

bool NoPiece::isPossibleDestination(const Tile& destination) const
{
	std::cout << "NoPiece EPD\n";
	return true;
}


NoPiece::~NoPiece()
{
}
