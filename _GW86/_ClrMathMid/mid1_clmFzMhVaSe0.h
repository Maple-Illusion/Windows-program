//mid1_clmFzMhVaSe0.h
//Gao-Wei Chang, 211004, 180424, 170610, 160701.
#pragma once
#include "_base\_cmTaskID0.h"
#include "_base\_cmHelp0.h"
#include "_task\_taSExpp0.h"
#include "_cmPostSe0.h"
//前置處理之引用順序非常重要

namespace clmFzMhVaSe {
using namespace GW86::ClrMathMid; 
public ref class MyCmTaskHnd0 {
public:
  static bool cmFzMaVaSe(array<String^>^ szCmd,
	array<String^>^ opcSet) {
	int idOpc; double x; int n;
	if ((szCmd[0] == "")||(szCmd[0] == nullptr))
		return true;
	int taFlag = MyCmPostSe0::
	  cmFzMaVa(szCmd, opcSet, &idOpc, &x, &n);
	if (taFlag == CMID_SERIES) {
		MyTaskSe0::serExpp(idOpc, x, n); return true;
	};
	return false;
  };
};

}