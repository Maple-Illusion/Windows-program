//GW86_ClrMath_MyVSumzStat0.h
//Gao-Wei Chang, 180406, 160429, 131023.
#pragma once

namespace GW86 {
namespace ClrMath {
public ref class MyVSumzStat0 {
public:
  static double x, y;
public:
  static double sum(double x0, double y0) {
      return x0+y0;
  };
  static double sum() {
    return x+y;
  };
};

} }

//巢狀命名空間Nested namespace
//公用列管類別

