//GW86_ClrMath_MyVArrEvzi0.h
//Gao-Wei Chang, 180418, 170424.
using namespace System;

namespace GW86 {
namespace ClrMath {
public ref class MyOperand {
  public:
    int num; double* pa; double* pb;
};

public ref class MyMath0 : public MyOperand {
public:
  MyMath0() { };
  MyMath0(int num, double* pa, double* pb) {
    this->num = num; this->pa = pa; this->pb = pb;
  };

  double* sum() {
    double* ps = new double[num];
	for (int i=0; i<num; i++) {
	  ps[i]=pa[i]+pb[i];
	};
	return ps;
  };

  double* sum(int num, double* pa, double* pb) {
    double* ps = new double[num];
    for (int i=0; i<num; i++) {
	  ps[i]=pa[i]+pb[i];
	};
	return ps;
  };
};

public ref class MyMath1 : public MyMath0 {
public:
  MyMath1() {	}; 
  MyMath1(int num, double* pa, double* pb) {
    this->num = num; this->pa = pa; this->pb = pb;
  }; 
  double sprod() {
    double sprod=0;
	for (int i=0; i<num; i++) {
	  sprod=sprod+pa[i]*pb[i];
	};
	return sprod;
  };

  double sprod(int num, double* pa, double* pb) {
    double sprod=0;
	for (int i=0; i<num; i++) {
	  sprod=sprod+pa[i]*pb[i];
	};
	return sprod;
  };
};

} }
