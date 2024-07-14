//_CmPostArr0.h
//Gao-Wei Chang, 211004, 210930, 170610, 160701.
#pragma once
namespace GW86 {
namespace ClrMathMid {
using namespace System;
public ref class MyCmPostArr0 {
public:
  static int cmFzMa(array<String^>^ szCmd,
	array<String^>^ opcSet, int* pidOpc) {
	int len = opcSet->Length;
	for (int i=0; i<len; i++) {
      if (szCmd[0]==opcSet[i]) {
		*pidOpc = ID_ARRSUM+i;
		return CMID_ARRAY;
	}; };
	//Console::WriteLine("Error in format (or opcode).");
	return ERR_CMARR;
  };
};

} }