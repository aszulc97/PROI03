#ifndef ARCHER_H_
#define ARCHER_H_
#include <iostream>
#include "unit.h"
class archer: public unit
{
  public:
    archer(int n);
    int attack();
};
#endif //ARCHER_H_
