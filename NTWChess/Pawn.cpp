#include "Pawn.h"
#include "Tile.h"
#include <iostream>

Pawn::Pawn(enum EColor color) : Piece(color) {
	type = EPTPawn;
}

bool Pawn::isPossibleDestination(const Tile& destination) const {
	//if (destination.isEmpty())
	std::cout << "Pawn IPD\n";

	return false;
}

Pawn::~Pawn() {

}
