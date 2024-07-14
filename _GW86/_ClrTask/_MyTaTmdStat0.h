//_MyTaTmdStat0.h (¥Ø¿ý_GW86_ClrMath)
//Gao-Wei Chang, 210417, 180502.
#pragma once
namespace GW86 {
namespace ClrTask {
#define OUTER_CNT 10
#define INNER_CNT 100000000
using namespace System;
public ref class MyTaskStat0 { 
  public: static void tmdLong() {
    for (int i=0; i<OUTER_CNT; i++) {
	  for (long j=0; j<INNER_CNT; j++);
	  Console::WriteLine("Times: {0}", i);
    };
  };
};
} }

