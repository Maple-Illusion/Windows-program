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
  A = opdSin[0]; T = opdSin[1]; //�g��T = xmax/cyc;
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
  A = opdSin[0]; T = opdSin[1]; //�g��T = xmax/cyc;
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


//(��)
//GW86_Fx12Graphics_MyVGra0.h
//(0)�̾ڡGGW86_Fm12Graphics_MyVGra0x.h
//(1)�ؼСG�ۭq���uø�s(curve-drawing)���O�禡�w�C
// is to add the user defined curve-drawing functions.

//�禡myEvalScrData(...)
//(1.1):�C�@����ܪ��˥��I�ơA�䤤�[1���t��ݺ��I�C
//(1.2):�������ǤJ_totScrSample�ѼƤ���ͫ��СC
//(1.4):totScreen�N����ܹ����`�ơC
//(2.1):�����@���h�H�@���p���A�Хܥثe�̹��ئ�(�q1�}�l�p)�P�`�̹��ơC







