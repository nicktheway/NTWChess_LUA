#ifndef ES_H
#define ES_H

#include <string>
using std::string;

enum EColor {
	ECWhite,
	ECBlack,
	ECUndefined
};
string EColorToString(enum EColor color);

enum EPieceType {
	EPTPawn,
	EPTRook,
	EPTKnight,
	EPTBishop,
	EPTQueen,
	EPTKing,
	EPTNothing
};

struct Position {
	int letter;
	int number;

	Position(int l = -1, int n = -1);
	Position(const Position& pos);
	string ToString();
	bool operator==(const Position pos);
	bool isValid();
};
struct Position StringToPosition(string s);

#endif
