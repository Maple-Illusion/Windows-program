//_MyVaPowzStat0.h
//Gao-Wei Chang, 210319, 170429, 170327.
#pragma once
namespace GW86 {
namespace ClrMath {
public ref class MyVaPowzStat {
public:
  double x; int n;
  MyVaPowzStat(double x0, int n0) {
    x=x0; n=n0;
  };
  double pow() {
    double pow = 1;
    for (int i=0; i<n; i++) pow = pow * x;
      return pow;
  };
  static double pow(double x0, int n0) {
    double pow = 1;
    for (int i=0; i<n0; i++) pow = pow * x0;
       return pow;
   };
};
}
}