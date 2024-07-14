//_MyVaSumPtr0.h
//Gao-Wei Chang, 210324, 180406, 160429, 131023.
#pragma once
namespace GW86 {
namespace ClrMath {
public ref class MyVaSumPtr0 {
public:
  double x, y; //(1.0)
  MyVaSumPtr0() {}; //(1.1)
  MyVaSumPtr0(double x, double y) {
      this->x = x; this->y = y;
  }; //(1.2)
public: double sum() { //(2.1)
    return (this->x)+(this->y);
  };
  double sum(double x, double y) { //(2.1)
      return x+y;
  };
};
}
}

