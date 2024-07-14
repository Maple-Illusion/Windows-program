//GW86_ClrMath_CmTaskSE0.h
//Gao-Wei Chang, 200429, 180424, 170610, 160701.
#pragma once
#include "c:\_GW86_ClrMath\tasks\_MySExppObj0.h"
namespace GW86 {
namespace ClrMath_TaskSEs {
using namespace System;
using namespace GW86::ClrMath;
public ref class MyTask_Series0 {
public:
  static void seriesExpp(int opcode_id, double x, int n) {
    double ratio_x = x;
	double pi_x;
	double theta_x = 2*PI*(x-int(x));//Ñy«×radian3.14159=¨¤«×180¡C
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
      case ID_SINC:
          pi_x = PI * x;
          Console::WriteLine("pi_x = PI*{0:F5}.", x); //(0.2a)
          for (int i = 0; i < n; i++) {
              Console::WriteLine("Iter. {0}: sinc(pi_x)={1}.", i, obj.isinc(pi_x, i));
          };
          break; //(1.6)
      case ID_ATAN:
          for (int i = 0; i < n; i++) {
              Console::WriteLine("Iter. {0}: atan(x)={1}.", i, obj.iatan(x, i));
          }; 
          break; //(1.6)
	}; 
  };
};

}}