//GW86_ClaArr_MyArrEv0
//Gao-Wei Chang, 210324, 180415, 170410.
#pragma once
namespace GW86 {
namespace ClaArr { 
public class MyArrEv0 {
public:
  int num; double* px; double* py; //(0.1)
  MyArrEv0() {}; //(0.2)
  MyArrEv0(int num, double* px, double* py) {
   this->num=num; this->px=px; this->py=py;
  }; //(0.3)

  double* sum() { 
    double* ps = new double[this->num];
    for (int i=0; i<this->num; i++) {
		ps[i] = this->px[i] + this->py[i];
    };
    return ps;
  };

  void sum(int num, double* ps, double* px, double* py) {
      for (int i = 0; i < num; i++) {
	    ps[i] = px[i] + py[i];
	  };
  }; //(1.1)
  double* sum(int num, double* px, double* py) {
	  double* ps = new double[num];
	  for (int i=0; i<num; i++) {
		  ps[i] = px[i]+py[i];
	  };
	  return ps;
  };

  double sprod() {
	  double sprod = 0;
	  for (int i = 0; i < this->num; i++) {
		  sprod = sprod + this->px[i] * this->py[i];
	  };
	  return sprod;
  };

  double sprod(int num, double* px, double* py) {
    double sprod = 0;
	for (int i=0; i<num; i++) {
	  sprod = sprod + px[i]*py[i];
	};
	return sprod;
  };
};
} }