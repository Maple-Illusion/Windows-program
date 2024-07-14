//GW86_ClrMath_CmPostArr0.h
//Gao-Wei Chang, 170610, 160701.
#pragma once
namespace GW86 {
namespace ClrMath_CmPostArr{
using namespace System;
public ref class MyCmPostArr0 {
public:
  static int cmFzMa(array<String^>^ szCmd,
	array<String^>^ szOpcSet, int* ptr_opcode_id) {
	int len = szOpcSet->Length;
	for (int i=0; i<len; i++) {
      if (szCmd[0]==szOpcSet[i]) {
		*ptr_opcode_id = ID_ARRSUM+i;
		return CM_ID_ARRAY;
	}; };
	return CM_ID_ERROR;
  };
};

}}