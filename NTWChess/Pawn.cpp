#include "Pawn.h"
#include "Tile.h"

Pawn::Pawn(enum EColor color) : Piece(color) {
	type = EPTPawn;
}

bool Pawn::isPossibleDestination(const Tile* destination) const {
	if (destination->isEmpty())
		return true;

	return false;
}

Pawn::~Pawn() {

}
