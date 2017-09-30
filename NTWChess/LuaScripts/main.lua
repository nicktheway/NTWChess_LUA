p1 = Position.new(1, 1)
p2 = Position.new(2, 1)
a1 = Tile.new(p1, 0)
a2 = Tile.new(p2, 1)
b1 = Pawn.new(1)
b2 = Pawn.new(0)
print('Point 1')

print(a1:isEmpty())
b1:SetTile(a1)
print(b1:GetTile().color)
print(a1:isEmpty())

print('Point 2')

b2:SetTile(a2)
print(b2.tile==a2)
print(b2:GetTile().position:toString())
b1:isPossibleDestination(a1)
u1 = NoPiece.new()
u1:isPossibleDestination(a1)

CallPieceFun(b1, a1)
CallPieceFun(u1, a1)
print('Point 3')

pon = Piece.new;
pon = b1
CallPieceFun(pon, a1)
pon = u1
CallPieceFun(pon, a1)

print('END')