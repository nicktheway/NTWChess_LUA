#ifndef PAWN_H
#define PAWN_H

#include"piece.h"

class Pawn : public Piece {
public:
	Pawn(enum EColor color);
	virtual bool isPossibleDestination(const Tile* destination) const override;
	~Pawn();
};

#endif /* end of include guard:  */
