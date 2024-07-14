//GW86_ClrMath_MyVpSumzx0.h
//Gao-Wei Chang, 180406, 160429, 131023.
#pragma once

namespace GW86 {
namespace ClrMath {
public ref class MyVpSumzx0 {
public:
  double x, y;
public:
  MyMath0(double x, double y) {
    this->x=x; this->y=y;
  };
  static double sum(double x, double y) {
      return x+y;
  };
  double sum() {
    return (this->x)+(this->y);
  };
};

} }

//巢狀命名空間Nested namespace
//公用列管類別

