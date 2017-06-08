#ifndef KNIGHT_H_
#define KNIGHT_H_
#include <iostream>
#include "unit.h"
class knight: public unit
{
public:
  knight(int n);
  int attack();
};
#endif //KNIGHT_H_
