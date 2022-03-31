#include <iostream>
#include "Tile.h"
#include "TileMoney.h"

TileMoney :: TileMoney (unsigned int money1) : Tile()
{
  money = money1;
}

TileMoney :: TileMoney (const TileMoney& to_copy) : Tile(to_copy)
{
  money = to_copy.money;
}

TileMoney :: ~TileMoney ()
{
}

TileMoney& TileMoney :: operator= (const TileMoney& to_copy) 
{
  if (&to_copy != this)
  {
    Tile :: operator= (to_copy);
    money = to_copy.money;
  }

  return *this;
}

Tile* TileMoney :: getClone () const
{
  Tile* to_copy = new TileMoney (*this);
  return to_copy;
}

void TileMoney :: print() const
{
  printOwnerChar();
  cout << "$" << money;
}

void TileMoney :: activate (unsigned int who_rolled,
                            const CellId& cell,
                            Board& board) const
{
  unsigned int affected_player = getAffectedPlayer(who_rolled);
  playerIncreaseMoneyAndPrint(affected_player, money);
}
