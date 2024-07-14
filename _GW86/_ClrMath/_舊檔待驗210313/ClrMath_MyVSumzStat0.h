//ClrMath_MyVSumzStat0.h
//Gao-Wei Chang, 180406, 160429, 131023.
#pragma once

namespace ClrMath {
public ref class MyVSumzStat0 {
public:
  static double x, y;
  static double sum(double x0, double y0) {
      return x0+y0;
  };
 static double sum() {
    return x+y;
  };
};
}


