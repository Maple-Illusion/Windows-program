//GW86_ClrMath_MyArrEv0
//Gao-Wei Chang, 180415, 170410.

namespace GW86 {
namespace ClrMath { 
public ref class MyArrEv0 {
public:
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
};
}
}