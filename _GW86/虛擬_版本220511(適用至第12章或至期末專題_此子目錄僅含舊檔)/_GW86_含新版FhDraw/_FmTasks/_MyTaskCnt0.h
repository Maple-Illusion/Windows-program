//_MyTaskCnt0.h (¥Ø¿ý_GW86_FmTasks)
//Gao-Wei Chang, 180502.
#pragma once
namespace GW86 {
namespace FmTasks {
#define OUTER_CNT 1
#define INNER_CNT 100000000
public ref class MyTaskCnt0 { 
  public:
  static void tmd(int cnt) {
	int tmd_cnt = cnt*OUTER_CNT;
    for (int i=0; i<tmd_cnt; i++)
	  for (long j=0; j<INNER_CNT; j++);
  };
};
} }

