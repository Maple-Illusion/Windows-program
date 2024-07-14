//GW86_ClrMath_MyArrEvah0
//Gao-Wei Chang, 210404, 210323, 170415.

namespace GW86 {
namespace ClrArr { 
public ref class MyArrEvah0 {
public:
	int num; array<double>^ px; array<double>^ py;
  MyArrEvah0() {};
  MyArrEvah0(int num, array<double>^ px, array<double>^ py) {
	  this->num = num;
	  this->px = px; this->py = py;
  };
  array<double>^ sum(int num, array<double>^ px, array<double>^ py) {
    array<double>^ ps = gcnew array<double>(num);
	for (int i=0; i<num; i++) {
		  ps[i] = px[i]+py[i];
	};
	return ps;
  };

  array<double>^ sum() {
	  array<double>^ ps = gcnew array<double>(num);
	  for (int i = 0; i < this->num; i++) {
		  ps[i] = this->px[i] + this->py[i];
	  };
	  return ps;
  };

  double sprod(int num, array<double>^ px, array<double>^ py) {
	  double sprod = 0;
	  for (int i = 0; i < num; i++) {
		  sprod = sprod + px[i] * py[i];
	  };
	  return sprod;
  };

  double sprod() {
      double sprod = 0;
	  for (int i=0; i<this->num; i++) {
		  sprod = sprod + this->px[i]* this->py[i];
	  };
	  return sprod;
  };

};
} }