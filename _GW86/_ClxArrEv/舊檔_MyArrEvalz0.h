//GW86_ClrMath_MyVArrEvz0
//Gao-Wei Chang, 170415.

namespace GW86 {
namespace ClrMath { 
public ref class MyVArrEvz0 {
public:
  int num; double* px; double* py;
  MyVArrEvz0(int num, double* px, double* py) {
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

  double* sum(int num, double* px, double* py) {
	  double* ps = new double[num];
	  for (int i=0; i<num; i++) {
		  ps[i] = px[i]+py[i];
	  };
	  return ps;
  };

  double sprod(int num, double* px, double* py) {
      double sprod = 0;
	  for (int i=0; i<num; i++) {
		  sprod = sprod + px[i]*py[i];
	  };
	  return sprod;
  };

  double sprod() {
      double sprod = 0;
	  for (int i=0; i<num; i++) {
		  sprod = sprod + px[i]*py[i];
	  };
	  return sprod;
  };

};
}
}