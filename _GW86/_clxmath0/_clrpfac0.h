//_clrpfac0.h
//Gao-Wei Chang, 210302, 180321.
#pragma once
ref class MyMath0 {
public:
  static double x; static int n;
  static double pow() {
    double pow=1; //(1.1)
    for (int i=0; i<n; i++) //(1.2)
	    pow=pow*x;
    return pow; //(1.3)
  };
public:
  static double fac() {
    double fac=1; //(1.1)
    for (int i=0; i<n; i++) //(1.2)
	    fac=fac*(i+1);
    return fac; //(2.1)
  };
};