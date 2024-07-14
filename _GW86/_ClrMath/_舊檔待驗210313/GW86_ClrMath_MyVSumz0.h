//GW86_ClrMath_MyVSumz0.h
//Gao-Wei Chang, 180406, 160429, 131023.
#pragma once

namespace GW86 {
namespace ClrMath {
public ref class MyVSumz0 {
public:
  double x, y;
public:
  MyMath0(double x0, double y0) {
    x=x0; y=y0;
  };
  double sum(double x0, double y0) {
      return x0+y0;
  };
  double sum() {
    return x+y;
  };
};

} }

//巢狀命名空間Nested namespace
//公用列管類別

