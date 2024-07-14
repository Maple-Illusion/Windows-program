//clrcm_fzMhVxSeA0.h
//Gao-Wei Chang, 180424, 170610, 160701.
#pragma once
#include "c:\_GW86_ClrMath\_cmTaskID0.h"
#include "c:\_GW86_ClrMath\_cmHelps0.h"
#include "c:\_GW86_ClrMath\tasks\_TaskSEs0.h"
#include "c:\_GW86_ClrMath\_cmPostxSE0.h"
#include "c:\_GW86_ClrMath\tasks\_TaskArr0.h"
#include "c:\_GW86_ClrMath\_cmPostArr0.h"
//前置處理之引用順序非常重要

namespace clrcm_fzMhVxSeA {
using namespace GW86::ClrMath_CmHelps; 
using namespace GW86::ClrMath_TaskSEs;
using namespace GW86::ClrMath_CmPostxSE;
using namespace GW86::ClrMath_TaskArr;
using namespace GW86::ClrMath_CmPostArr;

public ref class MyCmTaskHnd0 {
public:
  static bool cmFzMaVxSeA(array<String^>^ szCmd,
	array<String^>^ szOpcSet, array<String^>^ szOpcSet_arr) {
	int opcode_id; double x; int n;
	int flag_cmTask = MyCmPostxSE0::
	  cmFzMaVxSE(szCmd, szOpcSet, &opcode_id, &x, &n); 
	if (flag_cmTask==CM_ID_SERIES) {
      MyTask_Series0::seriesExpp(opcode_id, x, n);
	  return true; };
	flag_cmTask = MyCmPostArr0::
	  cmFzMa(szCmd, szOpcSet_arr, &opcode_id);
	if (flag_cmTask==CM_ID_ARRAY) {
	   MyTask_Arr0::arrEval(opcode_id);
	   return true; };
	return false;
	};
};

}