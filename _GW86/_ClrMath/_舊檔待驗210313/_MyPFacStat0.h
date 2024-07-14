//GW86_ClrMath_MyPFacStat0.h
//Ga0-Wei Chang, 180407, 170313.
#pragma once
namespace GW86 {
namespace ClrMath {
public ref class MyPFacStat0 {
  public:
  static double pow(double x, int n) {
    double pow=1;
    for (int i=0; i<n; i++)
	  pow = pow * x;
    return pow;
  };

  public:
  static double fac(int n) {
    double fac=1;
    for (int i=1; i<=n; i++)
	  fac = fac * i;
    return fac;
  };
};
} }