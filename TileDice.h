#pragma once

#include <iostream>
#include "Tile.h"
#include "Player.h"
using namespace std;

class TileDice : public Tile
{
  public:
    TileDice (unsigned int money1);
    TileDice (const TileDice& to_copy);
    virtual ~TileDice ();
    TileDice& operator= (const TileDice& to_copy);
    virtual Tile* getClone () const;
    virtual void activate (unsigned int who_rolled,
                           const CellId& cell,
                           Board& board) const;
    virtual void print () const;
    
  private:
    unsigned int dice1;
};