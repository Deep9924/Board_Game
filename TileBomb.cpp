#include "TileBomb.h"
#include "Board.h"

TileBomb :: TileBomb () : Tile()
{
}

TileBomb :: TileBomb (const TileBomb& to_copy) : Tile(to_copy)
{
}

TileBomb :: ~TileBomb ()
{
}

TileBomb& TileBomb :: operator= (const TileBomb& to_copy)
{
  if (&to_copy != this)
  {
    Tile :: operator= (to_copy);
  }
  return *this;
}

Tile* TileBomb :: getClone () const
{
  Tile* to_copy = new TileBomb (*this);
  return to_copy;
}

void TileBomb :: print () const
{
  cout << " Q ";
}

void TileBomb :: activate (unsigned int who_rolled,
                           const CellId& cell,
                           Board& board) const
{
  CellId North = toCellId(cell.row - 1, cell.column);
  CellId South = toCellId(cell.row + 1, cell.column);
  CellId East = toCellId(cell.row, cell.column + 1);
  CellId West = toCellId(cell.row, cell.column - 1);
  TileMoney bombTile(0);

  if (isOnBoard(cell))
    board.setAt(cell, bombTile, who_rolled);
  if (isOnBoard(North))
    board.setAt(North, bombTile, who_rolled);
  if (isOnBoard(South))
    board.setAt(South, bombTile, who_rolled);
  if (isOnBoard(East))
    board.setAt(East, bombTile, who_rolled);
  if (isOnBoard(West))
    board.setAt(West, bombTile, who_rolled);

  cout << endl << "  BOOM!" << endl;
  board.print();
}