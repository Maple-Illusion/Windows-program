//mid4_clmFzMhVxStA0.h
//Gao-Wei Chang, 211004, 180424, 170610, 160701.
#pragma once
#include "_base\_cmTaskID0.h"
#include "_base\_cmHelp0.h"
#include "_task\_taSTaylor0.h"
#include "_cmPostxSe0.h"
//�e�m�B�z���ޥζ��ǫD�`���n

namespace clmFzMhVxSt {
using namespace GW86::ClrMathMid; 
public ref class MyCmTaskHnd0 {
public:
  static bool cmFzMaVxSt(array<String^>^ szCmd,
	array<String^>^ opcSet) {
	int idOpc; double x; int n;
	if ((szCmd[0] == "")||(szCmd[0] == nullptr))
		return true;
	int taFlag = MyCmPostxSe0::
	  cmFzMaVx(szCmd, opcSet, &idOpc, &x, &n);
	if (taFlag == CMID_SERIES) {
		MyTaskSt0::serExpp(idOpc, x, n); return true;
	};
	if (taFlag == ERR_OPD) return true;
	return false;
  };
};

}