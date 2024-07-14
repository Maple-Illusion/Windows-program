//GW86_ClrMath_CmPostSe0.h
//Gao-Wei Chang, 211003, 210930, 170610, 160701.
#pragma once
namespace GW86 {
namespace ClrMathMid {
using namespace System;
public ref class MyCmPostSe0 {
public:
  static int cmFzMaVa(array<String^>^ szCmd,
	array<String^>^ opcSet, int* pidOpc,
	double* px, int* pn) {
	int len = opcSet->Length;
	bool bOpc=false;
	for (int i=0; i<len; i++) {
      if (szCmd[0]==opcSet[i]) {
		*pidOpc = ID_EXP+i;
		bOpc=true; break;
	}; };
	if ((!bOpc)||(szCmd->Length<NO_FIELDS))
		return ERR_CMSE;
	*px=Convert::ToDouble(szCmd[1]);
	*pn=Convert::ToInt32(szCmd[2]);
    return CMID_SERIES;
  };
};

} }