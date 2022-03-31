#include <iostream>
#include "Tile.h"
#include "TilePoints.h"

TilePoints :: TilePoints (unsigned int points) : Tile()
{
  points1 = points;
}

TilePoints :: TilePoints (const TilePoints& to_copy) : Tile(to_copy)
{
  points1 = to_copy.points1;
}

TilePoints :: ~TilePoints ()
{

}

TilePoints& TilePoints :: operator= (const TilePoints& to_copy) 
{
  if (&to_copy != this)
  {
    Tile :: operator= (to_copy);
    points1 = to_copy.points1;
  }

  return *this;
}

Tile* TilePoints :: getClone () const
{
  Tile* to_copy = new TilePoints (*this);
  return to_copy;
}

void TilePoints :: print() const
{
  printOwnerChar();
  cout << "*" << points1;
}

void TilePoints :: activate (unsigned int who_rolled,
                             const CellId& cell,
                             Board& board) const
{
  unsigned int affected_player = getAffectedPlayer(who_rolled);
  playerIncreasePointsAndPrint(affected_player, points1);
}
