//ClrMath_MyPowStat0.h
//Gao-Wei Chang, 180407.
namespace ClrMath {
public ref class MyPowStat0 {
public:
  static double pow(double x, int n) {
    double pow=1; //(1.1)
    for (int i=0; i<n; i++) //(1.2)
	    pow=pow*x;
    return pow; //(1.3)
  };
};
}