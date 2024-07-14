//GW86_ClrMath_MyVArrEv0
//Gao-Wei Chang, 170415.

namespace GW86 {
namespace ClrMath { 
public ref class MyVArrEv0 {
public:
  int num; double* px; double* py;
  MyVArrEv0(int num, double* px, double* py) {
	  this->num = num;
	  this->px = px; this->py = py;
  };

  double* sum() {
    double* ps = new double[this->num];
	for (int i=0; i<this->num; i++) {
		  ps[i] = this->px[i]+this->py[i];
	};
	return ps;
  };

  double sprod() {
      double sprod = 0;
	  for (int i=0; i<num; i++) {
		  sprod = sprod + px[i]*py[i];
	  };
	  return sprod;
  };

};
} }