//ClrMath_MyPowStat0.h
//Ga0-Wei Chang, 210313, 180407, 170313.
#pragma once
//namespace GW86 {
namespace ClrMath {
public ref class MyPowStat0 {
  public:
  static double pow(double x, int n) {
    double pow=1;
    for (int i=0; i<n; i++)
	  pow = pow * x;
    return pow;
  };
};
}
//}