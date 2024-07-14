//_ClrMath_MyVaPFacStat0.h
//Ga0-Wei Chang, 210313, 180407, 170313.
#pragma once
#include "_MyVaPowStat0.h"
namespace GW86 {
namespace ClrMath {
public ref class MyVaFacStat0 {
  public: static double fac(int n) {
    double fac = 1; //(1.1)
      for (int i = 0; i < n; i++) fac = fac * (i + 1); //(1.2)
    return fac; //(0.0)
  };
    public: static int n;
    public: static double fac() {
        double fac = 1; //(1.1)
        for (int i = 0; i < n; i++) fac = fac * (i + 1); //(1.2)
        return fac; //(0.0)
    };
};
} }

//未來修訂_宜加入this指標