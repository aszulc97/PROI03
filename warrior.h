#ifndef WARRIOR_H_
#define WARRIOR_H_
#include <iostream>
#include "unit.h"
class warrior: public unit
{
public:
  warrior(int n);
  int attack();
};
#endif //WARRIOR_H_
