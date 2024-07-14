//GW86_ClrMath_CmHelps0.h
//Gao-Wei Chang, 170610, 160701.
#pragma once
namespace GW86 {
namespace ClrMath_CmHelps {
using namespace System;
public ref class MyCmHelps0 {
public:
  static void szOpcHelp(array<String^>^ szOpcSet_ser,
	array<String^>^ szOpcSet_arr) {
    Console::WriteLine("*Opcode list:");
	Console::Write("*Set_ser: ");
	szOpcHelp_list(szOpcSet_ser);
	Console::Write("*Set_arr: ");
	szOpcHelp_list(szOpcSet_arr);
  };

  static void szOpcHelp_list(array<String^>^ szOpcSet) {
    for (int i = 0; i<szOpcSet->Length; i++)
	  Console::Write(szOpcSet[i]+" ");
    Console::WriteLine();
  };
};

}}