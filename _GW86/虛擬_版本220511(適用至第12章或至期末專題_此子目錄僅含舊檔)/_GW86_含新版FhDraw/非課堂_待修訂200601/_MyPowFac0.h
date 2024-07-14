//GW86_ClrMath_MyPowFac0.h
//Gao-Wei Chang, 180407.
namespace GW86 {
namespace ClrMath {
public ref class MyPowFac0 {
public:
  double pow(double x, int n) {
    double pow=1; //(1.1)
    for (int i=0; i<n; i++) //(1.2)
	    pow=pow*x;
    return pow; //(1.3)
  };
public:
  double fac(int n) {
    double fac=1; //(1.1)
    for (int i=0; i<n; i++) //(1.2)
	    fac=fac*(i+1);
    return fac; //(2.1)
  };
};
} }