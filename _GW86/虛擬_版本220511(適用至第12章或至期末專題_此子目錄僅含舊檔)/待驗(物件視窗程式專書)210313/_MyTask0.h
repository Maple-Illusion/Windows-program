//clrthd_tdgcn_sumz0.cpp
//Gao-Wei Chang, 180427, 160409.
namespace GW86 {
#define OUTER_CNT 10
#define INNER_CNT 100000000
using namespace System;
using namespace System::Threading;
public ref class MyTask0 { 
  public:
  void tmdLong() {
    for (int i=0; i<OUTER_CNT; i++) {
	  for (long j=0; j<INNER_CNT; j++);
	    Console::WriteLine("[{0}] Child Thread 1", i); }
  };
};  }