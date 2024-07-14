//GW86_ClrMath_TaskArr0.h
//Gao-Wei Chang, 170610, 160701.
#pragma once
#include "c:\_GW86_ClrMath\tasks\gw86_clrMath_arrEval0.h"
namespace GW86 {
namespace ClrMath_TaskArr {
using namespace System;
using namespace GW86::ClrMath;
public ref class MyTask_Arr0 {
public:
  static int arrEval(int opcode_id) {
    Console::WriteLine("Array 1:");
    String^ szInput1 = Console::ReadLine();
    array<String^>^ szArr1 = szInput1->Split();
    int len1 = szArr1->Length;
    Console::WriteLine("Array 2:");
    String^ szInput2 = Console::ReadLine();
    array<String^>^ szArr2 = szInput2->Split();
    int len2 = szArr2->Length;
	if (len1!=len2) {
	  Console::WriteLine("Mismatch in element No.");
	  return CM_ID_ERROR; };
	array<double>^ hnd_sum = gcnew array<double>(len1);
	switch (opcode_id) {
	  case ID_ARRSUM:
	    hnd_sum = MyArrEval0::sum(szArr1, szArr2);
	    Console::WriteLine("Sum of arrays:");
	    for (int i=0; i<len1; i++)
		  Console::Write("{0} ", hnd_sum[i]);
	    Console::WriteLine();
		break;
	  case ID_INNERPRO:
	    double inner_pro = MyArrEval0::innerPro(szArr1, szArr2);
	    Console::WriteLine("Inner product: {0}.", inner_pro);
		break;
	};
	return 1;
  };
};

}}