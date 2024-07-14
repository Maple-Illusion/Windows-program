//GW86_ClrMath_CmHelps0.h
//Gao-Wei Chang, 2110004, 210930, 170610, 160701.
#pragma once
#include "_cmHelp0.h"
namespace GW86 {
namespace ClrMathMid {
using namespace System;
public ref class MyCmHelp0a {
public:
  static void opcHelp(array<String^>^ opcSerSet,
	array<String^>^ opcArrSet) {
    Console::WriteLine("*Opcode list:");
	Console::Write("*serSet: ");
	MyCmHelp0::opcHelpList(opcSerSet);
	Console::Write("*arrSet: ");
	MyCmHelp0::opcHelpList(opcArrSet);
  };

};

} }