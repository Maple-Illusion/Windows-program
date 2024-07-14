//_cmHelp0.h
//Gao-Wei Chang, 211004, 170610, 160701.
#pragma once
namespace GW86 {
namespace ClrMathMid {
using namespace System;
public ref class MyCmHelp0 {
public:
  static void opcHelp(array<String^>^ opcSerSet) {
    Console::WriteLine("*Opcode list:");
	Console::Write("*serSet: ");
    opcHelpList(opcSerSet);
  };
  static void opcHelpList(array<String^>^ opcSet) {
	  for (int i = 0; i<opcSet->Length; i++)
		  Console::Write(opcSet[i]+" ");
	  Console::WriteLine();
  };
};

}}