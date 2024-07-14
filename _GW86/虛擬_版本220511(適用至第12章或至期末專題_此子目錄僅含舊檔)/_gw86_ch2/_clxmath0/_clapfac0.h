//clapfac0.h
//Gao-Wei Chang, 180314.
#pragma once
class MyMath0 {
public:
  static double pow(double x, int n) {
    double pow=1; //(1.1)
    for (int i=0; i<n; i++) //(1.2)
	    pow=pow*x;
    return pow; //(1.3)
  };
public:
  static double fac(int n) {
    double fac=1; //(1.1)
    for (int i=0; i<n; i++) //(1.2)
	    fac=fac*(i+1);
    return fac; //(2.1)
  };
};