#ifndef NOPIECE_H
#define NOPIECE_H

#include "Piece.h"
class NoPiece :
	public Piece
{
public:
	NoPiece();
	virtual bool isPossibleDestination(const Tile* destination) const override;
	~NoPiece();
};


#endif // !NOPIECE_H