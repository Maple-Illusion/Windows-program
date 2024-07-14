//_MyTaTmdCstr0.h (¥Ø¿ý_GW86_ClrTask)
//Gao-Wei Chang, 210417, 180502.
#pragma once
namespace GW86 {
namespace ClrTask {
#define OUTER_CNT 10
#define INNER_CNT 100000000
using namespace System;
public ref class MyTaskCstr0 { 
  public:
  String^ str0;
  MyTaskCstr0(String^ str0) {
		this->str0 = str0;
  };
  void tmdLong() {
    for (int i=0; i<OUTER_CNT; i++) {
	  for (long j=0; j<INNER_CNT; j++);
	    Console::WriteLine("[{0}] "+(this->str0), i); }
  };
}; 
}}

