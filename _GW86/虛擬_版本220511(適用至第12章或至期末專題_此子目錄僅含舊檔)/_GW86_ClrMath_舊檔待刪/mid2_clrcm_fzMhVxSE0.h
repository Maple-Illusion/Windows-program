//clrcm_fzMhVxSE0.h
//Gao-Wei Chang, 180424, 170610, 160701.
#pragma once
#include "c:\_GW86_ClrMath\_cmTaskID0.h"
#include "c:\_GW86_ClrMath\temp\_cmHelp0.h"
#include "c:\_GW86_ClrMath\tasks\_taskSE0.h"
#include "c:\_GW86_ClrMath\_cmPostxSE0.h"
//�e�m�B�z���ޥζ��ǫD�`���n

namespace clrcm_fzMhVxSE0 {
using namespace GW86::ClrMath_CmHelp; 
using namespace GW86::ClrMath_TaskSE;
using namespace GW86::ClrMath_CmPostxSE;

public ref class MyCmTaskHnd0 {
public:
  static bool cmFzMaVxSE(array<String^>^ szCmd,
	array<String^>^ szOpcSet) {
	int opcode_id; double x; int n;
	int flag_cmTask = MyCmPostxSE0::
	  cmFzMaVxSE(szCmd, szOpcSet, &opcode_id, &x, &n); 
	if (flag_cmTask==CM_ID_SERIES) {
      MyTask_Series0::seriesExpp(opcode_id, x, n);
	  return true; };
	return false;
	};
};

}