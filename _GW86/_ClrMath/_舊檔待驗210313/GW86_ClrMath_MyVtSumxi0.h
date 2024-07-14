//GW86_ClrMath_MyVpSumInhx0.h
//Gao-Wei Chang, 180406, 160429, 131023.
#pragma once
#include "ClrMath_MySumStat0.h"

namespace GW86 {
namespace ClrMath {
public ref class MyVpSumInhx0: public ClrMath::MySumStat0 {
public:
  double x, y;
public:
  MyMath0(double x, double y) {
    this->x=x; this->y=y;
  };
  double sum() {
    return (this->x)+(this->y);
  };
};

} }




