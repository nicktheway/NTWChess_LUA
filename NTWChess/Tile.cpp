#include "Tile.h"
#include "Piece.h"
#include "NoPiece.h"

#include <iostream>
//---Class Tile member functions START---
Tile::Tile() {
	this->pos.number = -1;
	this->pos.letter = -1;
	this->color = ECUndefined;
	this->piece = new NoPiece();
	//std::cout <<"IN TILE()\n";
}

Tile::Tile(struct Position pos, enum EColor color) {
	//std::cout << "IN TILE'S 2 Arg CON\n";
	this->pos = pos;
	this->color = color;
	this->piece = new NoPiece();
}
Tile::Tile(const Tile& tile) {
	//std::cout << "IN TILE'S COPY CON\n";
	this->pos = tile.pos;
	this->color = tile.color;
	this->piece = new NoPiece();
}

Tile::~Tile() {
	delete piece;
}

Piece* Tile::GetPiece() {
	return piece;
}

void Tile::SetPiece(Piece& piece) {
	//std::cout << "IN TILE::SetPiece\n";
	*this->piece = piece;
	if (piece.GetTile() != this)
		piece.SetTile(*this);
}

struct Position Tile::GetPosition() {
	return pos;
}

void Tile::SetPosition(Position pos)
{
	this->pos = pos;
}

enum EColor Tile::GetColor() {
	return color;
}

void Tile::SetColor(EColor color)
{
	this->color = color;
}

bool Tile::isEmpty() const {
	if (piece->GetType() == EPTNothing)
		return true;
	return false;
}
//---Class Tile member functions END---
