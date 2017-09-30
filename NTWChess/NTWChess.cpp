#include<iostream>
#include<string>
#include "ES.h"
#include "Tile.h"
#include "Pawn.h"
#include "sol.hpp"
#include "lua.hpp"

using std::cout;
using std::endl;
bool BindDataToLua(sol::state& lua);
int main()
{
	struct Position pos(0, 1);
	struct Position pos1(1, 1);
	struct Position pos2(2, 1);

	Tile a(pos, ECWhite);
	Tile b(pos1, ECWhite);
	Tile c(pos2, ECWhite);

	Piece* p;
	Pawn pawnW(ECWhite);
	Pawn pawnB(ECBlack);
	p = &pawnW;
	
	a.SetPiece(*p);
	b.SetPiece(pawnB);
	cout << "In position " << pos.ToString() << " there is a " << EColorToString(a.GetColor()) << " tile with an " 
		<< EPieceTypeToString(a.GetPiece()->GetType()) << " of color " << EColorToString(a.GetPiece()->GetColor())  << endl;
	cout << "In position " << pos1.ToString() << " there is a " << EColorToString(b.GetColor()) << " tile with an " 
		<< EPieceTypeToString(b.GetPiece()->GetType()) << " of color " << EColorToString(b.GetPiece()->GetColor()) << endl;
	cout << "In position " << pos2.ToString() << " there is a " << EColorToString(c.GetColor()) << " tile with an " 
		<< EPieceTypeToString(c.GetPiece()->GetType()) << " of color " << EColorToString(c.GetPiece()->GetColor()) << endl;
	cout << pawnW.GetTile()->GetPosition().ToString() << endl;

	cout << a.isEmpty() << " and b: " << b.isEmpty() << " and c: " << c.isEmpty() << endl;
	cout << pawnW.isPossibleDestination(c) << endl;


	sol::state lua;
	sol::load_result script1 = lua.load_file("LuaScripts/main.lua");
	BindDataToLua(lua);
	script1();

	char ch;

	std::cin >> ch;

	return 0;
}


bool BindDataToLua(sol::state& lua) {
	
	lua.open_libraries(sol::lib::base, sol::lib::package);
	
	lua.new_usertype<struct Position>("Position",
		sol::constructors<Position(int, int), Position(const Position&)>(),
		"toString", &Position::ToString,
		"isValid", &Position::isValid,
		"number", &Position::number,
		"letter", &Position::letter
		);

	lua.new_usertype<Tile>("Tile",
		sol::constructors<Tile(struct Position, enum EColor), Tile()>(),
		"SetPiece", &Tile::SetPiece,
		"GetPiece", &Tile::GetPiece,
		"isEmpty", &Tile::isEmpty,
		"color", sol::property(&Tile::GetColor, &Tile::SetColor),
		"position", sol::property(&Tile::GetPosition, &Tile::SetPosition)
		);

	lua.new_usertype<Piece>("Piece",
		"SetTile", &Piece::SetTile,
		"GetTile", &Piece::GetTile,
		"color", sol::property(&Piece::GetColor, &Piece::SetColor),
		"tile", sol::property(&Piece::GetTile, &Piece::SetTile)
		);

	lua.new_usertype<Pawn>("Pawn",
		sol::constructors<Pawn(enum EColor)>(),
		sol::base_classes, sol::bases<Piece>()
		);
	return true;
}