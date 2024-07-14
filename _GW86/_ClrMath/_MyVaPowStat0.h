//_ClrMath_MyVaPowStat0.h
//Ga0-Wei Chang, 210313, 180407, 170313.
#pragma once
namespace GW86 {
namespace ClrMath {
public ref class MyVaPowStat0 {
  public:
  static double x; static int n;
  static double pow(double x, int n) {
    double pow=1;
    for (int i=0; i<n; i++)
	  pow = pow * x;
    return pow;
  };
  static double pow() {
    double pow=1;
    for (int i=0; i<n; i++)
	  pow = pow * x;
    return pow;
  };
};
} }