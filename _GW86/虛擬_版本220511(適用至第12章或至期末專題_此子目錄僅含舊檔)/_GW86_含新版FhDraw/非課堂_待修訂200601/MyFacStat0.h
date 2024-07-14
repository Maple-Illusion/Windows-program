//ClrMath_MyFacStat0.h
//Gao-Wei Chang, 180407.
namespace ClrMath {
public ref class MyFacStat0 {
public:
  static double fac(int n) {
    double fac=1; //(1.1)
    for (int i=0; i<n; i++) //(1.2)
	    fac=fac*(i+1);
    return fac; //(2.1)
  };
};
}