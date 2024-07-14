//GW86_ClrMath_MyFacStat0.h
//Ga0-Wei Chang, 180407, 170313.
#pragma once
namespace GW86 {
namespace ClrMath {
public ref class MyFacStat0 {
  public:
  static double fac(int n) {
    double fac=1;
    for (int i=1; i<=n; i++)
	  fac = fac * i;
    return fac;
  };
};
} }