//GW86_ClrMath_CmPostxSE0.h
//Gao-Wei Chang, 170610, 160701.
#pragma once
namespace GW86 {
namespace ClrMath_CmPostxSE {
using namespace System;
public ref class MyCmPostxSE0 {
public:
  static int cmFzMaVxSE(array<String^>^ szCmd,
	array<String^>^ szOpcSet, int* ptr_opcode_id,
	double* px, int* pn) {
	int len = szOpcSet->Length;
	bool flag_opcode=false;
	for (int i=0; i<len; i++) {
      if (szCmd[0]==szOpcSet[i]) {
		*ptr_opcode_id = ID_EXP+i;
		flag_opcode=true; break;
	}; };
	if ((!flag_opcode)||(szCmd->Length<NO_FIELDS))
		return CM_ID_ERROR;
    try {
	  *px=Convert::ToDouble(szCmd[1]);
	  *pn=Convert::ToInt32(szCmd[2]); }
	catch (FormatException^ e) {
	  Console::WriteLine(e->Message);
	  return CM_ID_ERROR; };
    return CM_ID_SERIES;
  };
};

}}