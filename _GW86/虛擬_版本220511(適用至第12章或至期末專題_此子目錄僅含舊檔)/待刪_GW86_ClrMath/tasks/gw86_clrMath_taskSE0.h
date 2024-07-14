//GW86_ClrMath_CmTaskSE0.h
//Gao-Wei Chang, 180422, 170610, 160701.
#pragma once
#include "c:\_GW86_ClrMath\tasks\gw86_clrMath_seriesExpp0x.h"
namespace GW86 {
namespace ClrMath_TaskSE {
using namespace System;
using namespace GW86::ClrMath;
public ref class MyTask_Series0 {
public:
  static void seriesExpp(int opcode_id, double x, int n) {
    double ratio_x = x;
	double theta_x = 2*PI*x;//Ñy«×radian3.14159=¨¤«×180¡C
	MySeriesExpp0x obj;
	switch (opcode_id) {
	  case ID_EXP:
	    for (int i = 0; i < n; i++)
		  Console::WriteLine("For {0}-th iteration, exp({1:F3})= {2}.",
				i, x, obj.exp(x, i));
	    break;
	  case ID_SIN:
	    for (int i = 0; i<n; i++)
	      Console::WriteLine("For {0}-th iteration, sin(2*PI*{1:F3})= {2}.",
			    i, ratio_x, obj.sin(theta_x, i));
	    break;
	  case ID_COS:
		 for (int i = 0; i<n; i++)
		   Console::WriteLine("For {0}-th iteration, cos(2*PI*{1:F3})= {2}.",
				i, ratio_x, obj.cos(theta_x, i));
		break;
	}; 
  };
};

}}