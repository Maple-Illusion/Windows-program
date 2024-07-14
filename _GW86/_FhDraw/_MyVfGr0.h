//GW86_FhDraw_MyVGra0.h.
//Gao-Wei Chang, 211120, 210827, 210818, 201012, 180611, 160707, 140307.
#pragma once
#include "c:\_GW86\_FhDraw\_MyRect0.h"
#include "c:\_GW86\_ClrMath\_MySExppStat0.h"
#include "c:\_GW86\_FhDraw\_MyGraphID0.h"
#include "c:\_GW86\_FhDraw\_MyVaGr0.h"
#define PI 3.14159
namespace GW86 {
namespace FhDraw {
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace GW86::ClrMath;

public ref class MyVfGr0 {
public:
static void opdSin1shift(bool bDir, array<double>^ opdSin,
  int nPtcyc, array<float>^ xyspan, bool bRst) {
  double T=opdSin[1];
  static double iShift = 0;
  if (bRst) iShift = 0;
  //float scrRes = (xyspan[1] - xyspan[0]) / (nPtcyc - 1);
  //double xDisp = (iShift * scrRes);
  float nTot = float((xyspan[1] - xyspan[0]) / T) * float(nPtcyc) + 1;
  float xRes = (xyspan[1] - xyspan[0]) / float(nTot - 1);
  double xDisp = (iShift * xRes);
  opdSin[2] = xDisp;
  if (!bDir) iShift++; else iShift--;
};

public:
static void drawSine(Graphics^ g1, MyRect0^ theCoord0, Pen^ myPen1,
  array<double>^ opdSin, int nPtcyc, array<float>^ xyspan) {
  double A, T, val2phase, offset;
  A = opdSin[0]; T = opdSin[1]; //週期T = xmax/cyc;
  val2phase = opdSin[2]; offset = opdSin[3];
  float nTot = float((xyspan[1] - xyspan[0])/T) * float(nPtcyc) + 1;
  float xRes = (xyspan[1] - xyspan[0]) / float(nTot - 1);
  float* px = new float[int(nTot)];
  float* py = new float[int(nTot)];
  MyVaGr0::drawSeg(g1, theCoord0, myPen1, 0, 0, xyspan, 0);
  for (int i = 0; i < int(nTot); i++) {
	  px[i] = (i * xRes) + xyspan[0];
	  double rx = (px[i] - val2phase) / T;
	  rx = rx - int(rx);
	  py[i] = float(A * MySExppStat0::sin(2 * PI * rx, 10) + offset);
	  MyVaGr0::drawSeg(g1, theCoord0, myPen1, px[i], py[i], xyspan, int(nTot));
  };
  delete[] px; delete[] py;
};

public:
static void drawSineMark(Graphics^ g1, MyRect0^ theCoord0,
  Pen^ myPen1, Brush^ myBrush1, array<double>^ opdSin,
  int nPtcyc, array<float>^ xyspan, int iMark, float sizMark) {
  double A, T, val2phase, offset; //cyc = 2;
  A = opdSin[0]; T = opdSin[1]; //週期T = xmax/cyc;
  val2phase = opdSin[2]; offset = opdSin[3];
  float nTot=float((xyspan[1] - xyspan[0])/T)*float(nPtcyc)+1;
  float xRes = (xyspan[1] - xyspan[0]) / float(nTot - 1);
  float* px = new float[int(nTot)];
  float* py = new float[int(nTot)];
  MyVaGr0::drawSeg(g1, theCoord0, myPen1, 0, 0, xyspan, 0);
  for (int i = 0; i < int(nTot); i++) {
	px[i] = (i * xRes) + xyspan[0];
	double rx = (px[i] - val2phase) / T;
	rx = rx - int(rx);
	py[i] = float(A * MySExppStat0::sin(2 * PI * rx, 10) + offset);
	MyVaGr0::drawSeg(g1, theCoord0, myPen1, px[i], py[i], xyspan, int(nTot));
	MyVaGr0::drawMark(g1, theCoord0, myPen1, myBrush1, px[i], py[i], xyspan, iMark, sizMark);
  };
 delete[] px; delete[] py;
};

};

} }


//(註)
//GW86_Fx12Graphics_MyVGra0.h
//(0)依據：GW86_Fm12Graphics_MyVGra0x.h
//(1)目標：自訂曲線繪製(curve-drawing)類別函式庫。
// is to add the user defined curve-drawing functions.

//函式myEvalScrData(...)
//(1.1):每一幕顯示的樣本點數，其中加1為含兩端端點。
//(1.2):此式為傳入_totScrSample參數之原生指標。
//(1.4):totScreen代表顯示幕次總數。
//(2.1):不足一幕則以一幕計之，標示目前屏幕目次(從1開始計)與總屏幕數。







