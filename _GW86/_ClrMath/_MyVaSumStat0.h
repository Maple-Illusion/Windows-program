//ClrMath_MyVaSumStat0.h
//Gao-Wei Chang, 210417, 210313, 180406, 160429, 131023.
#pragma once
namespace GW86 {
namespace ClrMath {
public ref class MyVaSumStat0 {
public:
  static double x, y;
  static double sum() {
    return x+y;
  };
  static double sum(double x, double y) {
    return x+y;
  };
public:
  static double result;
  static void sum1() {
    result=x+y;
  };
};
}
}

