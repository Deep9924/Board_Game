#include <iostream>
#include "Tile.h"
#include "TileDice.h"

TileDice :: TileDice (unsigned int dice) : Tile()
{
  dice1 = dice;
}

TileDice :: TileDice (const TileDice& to_copy) : Tile(to_copy)
{
  dice1 = to_copy.dice1;
}

TileDice :: ~TileDice ()
{

}

TileDice& TileDice :: operator= (const TileDice& to_copy) 
{
  if (&to_copy != this)
  {
    Tile :: operator= (to_copy);
    dice1 = to_copy.dice1;
  }

  return *this;
}

Tile* TileDice :: getClone () const
{
  Tile* to_copy = new TileDice (*this);
  return to_copy;
}

void TileDice :: print() const
{
  printOwnerChar();
  cout << "#" << dice1;
}

void TileDice :: activate (unsigned int who_rolled,
                           const CellId& cell,
                           Board& board) const
{
  unsigned int affected_player = getAffectedPlayer(who_rolled);
  playerIncreaseDiceAndPrint(affected_player, dice1);
}
