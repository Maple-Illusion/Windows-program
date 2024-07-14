//_MyVaSumPtr0.h
//Gao-Wei Chang, 210417, 180406, 160429, 131023.
#pragma once
namespace GW86 {
namespace ClrTask {
public ref class MyTaSumPtr0 {
public:
  double x, y, result; //(1.0)
  MyTaSumPtr0() {}; //(1.1)
  MyTaSumPtr0(double x, double y) {
      this->x = x; this->y = y;
  }; //(1.2)
public: void sum() { //(2.1)
    result= (this->x)+(this->y);
  };
  double sum(double x, double y) { //(2.1)
      return x+y;
  };
};
}
}

