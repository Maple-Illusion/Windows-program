//_cmPostxSe0.h
//Gao-Wei Chang, 211004, 210930, 170610, 160701.
#pragma once
namespace GW86 {
namespace ClrMathMid {
using namespace System;
public ref class MyCmPostxSe0 {
public:
  static int cmFzMaVx(array<String^>^ szCmd,
	array<String^>^ opcSet, int* pidOpc, double* px, int* pn) {
	int len = opcSet->Length;
	bool bOpc=false;
	for (int i=0; i<len; i++) {
      if (szCmd[0]==opcSet[i]) {
		*pidOpc = ID_EXP+i;
		bOpc=true; break;
	}; };
	if ((!bOpc) || (szCmd->Length < NO_FIELDS))
		return ERR_CMSE;
    try {
	  *px=Convert::ToDouble(szCmd[1]);
	  *pn=Convert::ToInt32(szCmd[2]); }
	catch (FormatException^ e) {
	  Console::WriteLine(e->Message);
	  return ERR_OPD;
	};
    return CMID_SERIES;
  };
};

} }