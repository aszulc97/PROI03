#ifndef RIDER_H_
#define RIDER_H_
#include <iostream>
#include "unit.h"
class rider: public unit
{
public:
  rider(int n);
  int attack();
};
#endif //RIDER_H_
