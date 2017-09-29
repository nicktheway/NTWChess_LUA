#include<iostream>
#include<string>
#include "ES.h"
#include "Tile.h"

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

	//Piece* p = new Pawn(ECWhite);
	//a.SetPiece(p);

	cout << EColorToString(a.GetColor()) << '\n';
	cout << pos.ToString() << '\n';
	cout << pos2.ToString() << '\n';
	pos2 = pos;
	cout << pos2.ToString() << '\n';
	cout << (pos == pos2) << endl;

	char ch;

	std::cin >> ch;

	return 0;
}
