#include<iostream>
#include<string>
#include "ES.h"
#include "Tile.h"
#include "Pawn.h"

using std::cout;
using std::endl;

int main()
{
	struct Position pos(0, 1);
	struct Position pos1(1, 1);
	struct Position pos2(2, 1);

	Tile a(pos, ECWhite);
	Tile b(pos1, ECWhite);
	Tile c(pos2, ECWhite);

	Piece* p;
	Pawn pawn(ECWhite);

	p = &pawn;
	
	a.SetPiece(*p);

	cout << "In position " << pos.ToString() << " there is a " << EColorToString(a.GetColor()) << " tile with an " << EPieceTypeToString(a.GetPiece()->GetType()) << endl;
	cout << "In position " << pos2.ToString() << " there is a " << EColorToString(c.GetColor()) << " tile with an " << EPieceTypeToString(c.GetPiece()->GetType()) << endl;
	cout << pawn.GetTile()->GetPosition().ToString() << endl;

	char ch;

	std::cin >> ch;

	return 0;
}
