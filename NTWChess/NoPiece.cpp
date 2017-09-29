#include "NoPiece.h"

NoPiece::NoPiece()
{
	type = EPTNothing;
}

bool NoPiece::isPossibleDestination(const Tile * destination) const
{
	return true;
}


NoPiece::~NoPiece()
{
}
