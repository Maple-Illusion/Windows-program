//ClrMath_MyTaSumStat0.h
//Gao-Wei Chang, 210417, 210313, 180406, 160429, 131023.
#pragma once
namespace GW86 {
namespace ClrTask {
public ref class MyTaSumStat0 {
public:
  static double x, y, result;
  static void sum() {
    result=x+y;
  };
  static void wtsum() {
      result = x + y;
      Console::WriteLine("The sum is {0}.", result);
  };
};
}
}

