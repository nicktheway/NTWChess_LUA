#ifndef PIECE_H
#define PIECE_H

class Tile;
#include "ES.h"
class Piece {
private:
	enum EColor color;
	Tile* tile;
protected:
	enum EPieceType type;
public:
	Piece();
	Piece(enum EColor color);
	Piece(const Piece& piece);
	void SetTile(Tile* tile);
	enum EPieceType GetType();
	enum EColor GetColor();
	virtual bool isPossibleDestination(const Tile* destination) const = 0;
	~Piece();
};


#endif /* end of include guard:  */
