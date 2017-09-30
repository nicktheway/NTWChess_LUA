#include "Piece.h"
#include "Tile.h"
#include <iostream>

Piece::Piece() {
	std::cout << "IN PIECE()\n";
	this->type = EPTNothing;
	this->color = ECUndefined;
	this->tile = NULL;
}

Piece::Piece(enum EColor color) {
	//std::cout << "IN PIECE'S 2arg CON\n";
	this->type = EPTNothing;
	this->color = color;
	this->tile = NULL;
}

Piece::Piece(const Piece& piece) {
	//std::cout << "IN PIECE'S COPY CON\n";
	this->type = piece.type;
	this->color = piece.color;
	this->tile = NULL;
}

Piece::~Piece() {
	std::cout << "IN ~PIECE\n";

}

void Piece::SetTile(Tile& tile) {
	//std::cout << "IN PIECE::SetTile\n";
	this->tile = &tile;
	if (tile.GetPiece() != this)
		tile.SetPiece(*this);
}

enum EPieceType Piece::GetType() {
	return type;
}

enum EColor Piece::GetColor() {
	return color;
}

void Piece::SetColor(EColor color)
{
	this->color = color;
}

Tile * Piece::GetTile()
{
	return tile;
}
