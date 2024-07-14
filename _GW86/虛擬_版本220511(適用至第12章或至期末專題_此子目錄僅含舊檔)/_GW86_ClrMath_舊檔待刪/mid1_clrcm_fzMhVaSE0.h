//Clr12_CmFzMhVaSE0.h
//Gao-Wei Chang, 180424, 170610, 160701.
#pragma once
#include "c:\_GW86_ClrMath\_cmTaskID0.h"
#include "c:\_GW86_ClrMath\temp\_cmHelp0.h"
#include "c:\_GW86_ClrMath\tasks\_taskSE0.h"
#include "c:\_GW86_ClrMath\temp\_cmPostSE0.h"
//前置處理之引用順序非常重要

namespace clrcm_fzMhVaSE0 {
using namespace GW86::ClrMath_CmHelp; 
using namespace GW86::ClrMath_TaskSE;
using namespace GW86::ClrMath_CmPostSE;

public ref class MyCmTaskHnd0 {
public:
  static bool cmFzMaVaSE(array<String^>^ szCmd,
	array<String^>^ szOpcSet) {
	int opcode_id; double x; int n;
	int flag_cmTask = MyCmPostSE0::
	  cmFzMaVaSE(szCmd, szOpcSet, &opcode_id, &x, &n); 
	if (flag_cmTask==CM_ID_SERIES) {
      MyTask_Series0::seriesExpp(opcode_id, x, n);
	  return true; };
	return false;
	};
};

}