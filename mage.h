#ifndef MAGE_H_
#define MAGE_H_
#include <iostream>
#include "unit.h"
class mage : public unit
{
public:
  mage(int n);
  int attack();
};
#endif //MAGE_H_
