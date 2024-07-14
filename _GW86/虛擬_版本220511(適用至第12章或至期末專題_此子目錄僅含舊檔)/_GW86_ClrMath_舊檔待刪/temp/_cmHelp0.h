//GW86_ClrMath_CmProcs0.h
//Gao-Wei Chang, 170610, 160701.
#pragma once
namespace GW86 {
namespace ClrMath_CmHelp {
using namespace System;
public ref class MyCmHelp0 {
public:
  static void szOpcHelp(array<String^>^ szOpcSet_ser) {
    Console::WriteLine("*Opcode list:");
	Console::Write("*Set_ser: ");
	MyCmHelp0::szOpcHelp_list(szOpcSet_ser);
  };
  static void szOpcHelp_list(array<String^>^ szOpcSet) {
	  for (int i = 0; i<szOpcSet->Length; i++)
		  Console::Write(szOpcSet[i]+" ");
	  Console::WriteLine();
  };
};

}}