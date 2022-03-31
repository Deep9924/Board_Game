#pragma once

#include <iostream>
#include "Tile.h"
#include "Player.h"
using namespace std;

class TilePoints : public Tile
{
  public:
    TilePoints (unsigned int money1);
    TilePoints (const TilePoints& to_copy);
    virtual ~TilePoints ();
    TilePoints& operator= (const TilePoints& to_copy);
    virtual Tile* getClone () const;
    virtual void activate (unsigned int who_rolled,
                           const CellId& cell,
                           Board& board) const;
    virtual void print () const;

  private:
    unsigned int points1;
};