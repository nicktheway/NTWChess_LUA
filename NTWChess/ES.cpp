#include "ES.h"

using std::string;

//---Struct Position member functions START---
Position::Position(int l, int n) {
	letter = l;
	number = n;
}
Position::Position(const Position& pos) {
	letter = pos.letter;
	number = pos.number;
}
string Position::ToString() {
	string s;
	s += (char)('a' + letter);
	s += (char)('1' + number);
	return s;
}
bool Position::operator==(const Position pos) {
	if (letter == pos.letter && number == pos.number)
		return true;
	return false;
}

bool Position::isValid() {
	if (letter < 0 || letter > 25 || number < 0 || number > 25)
		return false;
	return true;
}
//---Struct Position member functions END---

struct Position StringToPosition(string s) {
	struct Position pos;
	struct Position invalidPos(-1, -1);
	if (s.length() != 2) {
		return invalidPos;
	}

	pos.letter = (int)(s[0] - 'a');
	pos.number = (int)(s[1] - '1');
	if (!pos.isValid())
		return invalidPos;
	return pos;
}

string EColorToString(enum EColor color) {
	string s;
	switch (color) {
	case ECWhite:
		s = "ECWhite";
		break;
	case ECBlack:
		s = "ECBlack";
		break;
	default:
		s = "ECUndefined";
	}
	return s;
}

string EPieceTypeToString(EPieceType type)
{
	string s;
	switch (type)
	{
	case EPTPawn:
		s = "EPTPawn";
		break;
	case EPTRook:
		s = "EPTRook";
		break;
	case EPTKnight:
		s = "EPTKnight";
		break;
	case EPTBishop:
		s = "EPTBishop";
		break;
	case EPTQueen:
		s = "EPTQueen";
		break;
	case EPTKing:
		s = "EPTKing";
		break;
	case EPTNothing:
		s = "EPTNothing";
		break;
	default:
		break;
	}
	return s;
}
