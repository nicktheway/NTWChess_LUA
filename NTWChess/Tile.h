#pragma once
#ifndef TILE_H
#define TILE_H

#include "ES.h"

class Piece;
class Tile {
private:
	enum EColor color;
	Piece* piece;
	struct Position pos;
public:
	Tile();
	Tile(struct Position pos, enum EColor color);
	Tile(const Tile& tile);
	enum EColor GetColor();
	void SetColor(enum EColor color);
	Piece* GetPiece();
	void SetPiece(Piece& piece);
	struct Position GetPosition();
	void SetPosition(struct Position pos);
	bool isEmpty() const;
	~Tile();
};

#endif