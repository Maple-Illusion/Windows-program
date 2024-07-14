//_taSExpp0.h
//Gao-Wei Chang, 211004, 200429, 180424, 170610, 160701.
#pragma once
#include "C:\Users\ataraxia\Documents\AV_LAB\NTNU_Cpp\_GW86\_ClrMath\_MySExppObj0.h" //同第3章
namespace GW86 {
namespace ClrMathMid {
using namespace System;
using namespace GW86::ClrMath;
public ref class MyTaskSe0 {
public:
  static void serExpp(int opcode_id, double x, int n) {
    double ratio_x = x;
	double theta_x = 2*PI*(x-int(x));//弳度radian3.14159=角度180。
	MySExppObj0 obj;
	Console::WriteLine("No. of iterations (iters.) or n = {0}.", n);
	switch (opcode_id) {
	  case ID_EXP:
		for (int i = 0; i < n; i++) {
		  Console::WriteLine("Iter. {0}: exp({1:F3})={2}.", i, x, obj.iexp(x, i));
		}
	    break;
	  case ID_SIN:
		  Console::WriteLine("theta = 2*PI*{0:F5}.", x); //(0.2a)
		  for (int i = 0; i < n; i++) {
			  Console::WriteLine("Iter. {0}: sin(theta)={1}.", i, obj.isin(theta_x, i));
		  };
	    break;
	  case ID_COS:
		  Console::WriteLine("theta = 2*PI*{0:F5}.", x); //(0.2a)
		  for (int i = 0; i < n; i++) {
			  Console::WriteLine("Iter. {0}: cos(theta)={1}.", i, obj.icos(theta_x, i));
		  };
		break;
	}; 
  };
};
}}