//_MyVaPowzPtr0.h
//Gao-Wei Chang, 210324, 170429, 170327.
#pragma once
namespace GW86 {
namespace ClrMath {
public ref class MyVaPowzPtr0 {
public:
  double x; int n;
  MyVaPowzPtr0() {};
  MyVaPowzPtr0(double x, int n) {
    this->x=x; this->n=n;
  };
  double pow() {
    double pow = 1;
    for (int i=0; i<this->n; i++) pow = pow * (this->x);
      return pow;
  };
  double pow(double x, int n) {
    double pow = 1;
    for (int i=0; i<n; i++) pow = pow * x;
       return pow;
  };
};
}
}