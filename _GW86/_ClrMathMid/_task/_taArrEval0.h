//_TaskArr0.h
//Gao-Wei Chang, 211004, 210930, 170610, 160701.
#pragma once
#include "_arrEval0.h"
namespace GW86 {
namespace ClrMathMid {
using namespace System;
using namespace GW86::ClrMath;
public ref class MyTaskArr0 {
public:
  static int arrEval(int idOpc) {
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
	  return ERR_CMARR; };
	array<double>^ hnd_sum = gcnew array<double>(len1);
	switch (idOpc) {
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

} }