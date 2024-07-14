//GW86_FhDraw_MyVdGr0.h.
//Gao-Wei Chang, 210829, 210816, 201012, 180611, 160707, 140307.
#pragma once
#include "c:\_GW86\_FhDraw\_MyRect0.h"
#include "c:\_GW86\_FhDraw\_MyGraphID0.h"
#include "c:\_GW86\_FhDraw\_MyVaGr0.h"
namespace GW86 {
namespace FhDraw {
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace GW86::ClrMath;

public ref class MyVdGr0 {
public:
static int opdsLen(array<double>^ opdsfull,
	int* pnPtfull, array<double>^ opds) {
  *pnPtfull = opdsfull->Length;
  int len = opds->Length;
  if (len > *pnPtfull) return -1;
  return len;
};

public:
static bool opdsfull(array<double>^ opdsfull, array<double>^ opds) {
  int len, nPtfull;
  len = opdsLen(opdsfull, &nPtfull, opds);
  if (len<0) return 0;
  for (int i = 0; i < nPtfull; i++) opdsfull[i] = 0;
  for (int i = 0; i < len; i++) opdsfull[i] = opds[i];
  return 1;
};

public:
static bool opdsf1shift(bool bDir,
  array<double>^ opdsfull, array<double>^ opds, bool bRst) {
  int len, nPtfull;
  len = opdsLen(opdsfull, &nPtfull, opds);
  if (len < 0) return 0;
  for (int i = 0; i < nPtfull; i++) opdsfull[i] = 0;
  static int iShift = 0;
  if (bRst) iShift = 0;
  for (int i = 0; i < len; i++) {
	int k = i + iShift;
	while (k >= nPtfull) k = k - nPtfull;
	while (k < 0) k = k + nPtfull;
	if ((k >= 0) && (k < nPtfull)) opdsfull[k] = opds[i];
  };
  if (!bDir) iShift++;  else iShift--;
  return 1;
};

public:
static void drawDaStem(Graphics^ g1, MyRect0^ theCoord0,
  Pen^ myPen1, array<double>^ opdsfull, array<float>^ xyspan) {
  int len = opdsfull->Length;
  float* px = new float[len];
  float* py = new float[len];
  float x_coord, y_coord; float sizMark = 10;
  float xRes = (xyspan[1] - xyspan[0]) / (len - 1); //跑计妓セ计ヘ
  for (int i = 0; i < len; i++) {
	px[i] = i * xRes; py[i] = float(opdsfull[i]);
	MyVaGr0::drawStem(g1, theCoord0, myPen1, px[i], py[i], xyspan);
	MyVaGr0::val2pixCoord(theCoord0, px[i], py[i], &x_coord, &y_coord, xyspan);
    g1->DrawEllipse(myPen1, x_coord - (sizMark / 2), //(2.2)
				y_coord - (sizMark / 2), sizMark, sizMark);
  };
  delete[] px; delete[] py;
};

public:
	static void drawDaSteMark(Graphics^ g1, MyRect0^ theCoord0,
		Pen^ myPen1, Brush^ myBrush1, array<double>^ opdsfull,
		array<float>^ xyspan, int iMark, float sizMark) {
		int len = opdsfull->Length;
		float* px = new float[len];
		float* py = new float[len];
		float xRes = (xyspan[1] - xyspan[0]) / (len - 1); //跑计妓セ计ヘ
		for (int i = 0; i < len; i++) {
			px[i] = i * xRes; py[i] = float(opdsfull[i]);
			MyVaGr0::drawStem(g1, theCoord0, myPen1, px[i], py[i], xyspan);
			MyVaGr0::drawMark(g1, theCoord0, myPen1, myBrush1, px[i], py[i], xyspan, iMark, sizMark);
		};
		delete[] px; delete[] py;
	};

public:
	static void drawDaSegMark(Graphics^ g1, MyRect0^ theCoord0,
		Pen^ myPen1, Brush^ myBrush1, array<double>^ opdsfull,
		array<float>^ xyspan, int iMark, float sizMark) {
		int len = opdsfull->Length;
		float* px = new float[len];
		float* py = new float[len];
		float xRes = (xyspan[1] - xyspan[0]) / (len - 1); //跑计妓セ计ヘ
		MyVaGr0::drawSeg(g1, theCoord0, myPen1, 0, 0, xyspan, 0);
		for (int i = 0; i < len; i++) {
			px[i] = i * xRes; py[i] = float(opdsfull[i]);
			MyVaGr0::drawSeg(g1, theCoord0, myPen1, px[i], py[i], xyspan, len);
			MyVaGr0::drawMark(g1, theCoord0, myPen1, myBrush1, px[i], py[i], xyspan, iMark, sizMark);
		};
		delete[] px; delete[] py;
	};

public:
	static void drawDaSegSteMk(Graphics^ g1, MyRect0^ theCoord0,
		Pen^ myPen1, Pen^ myPen2, Pen^ myPen3, Brush^ myBrush1,
		array<double>^ opdsfull, array<float>^ xyspan, int iMark, float sizMark) {
		int len = opdsfull->Length;
		float* px = new float[len];
		float* py = new float[len];
		float xRes = (xyspan[1] - xyspan[0]) / (len - 1); //跑计妓セ计ヘ
		MyVaGr0::drawSeg(g1, theCoord0, myPen1, 0, 0, xyspan, 0);
		for (int i = 0; i < len; i++) {
			px[i] = i * xRes; py[i] = float(opdsfull[i]);
			MyVaGr0::drawStem(g1, theCoord0, myPen1, px[i], py[i], xyspan);
			MyVaGr0::drawSeg(g1, theCoord0, myPen2, px[i], py[i], xyspan, len);
			MyVaGr0::drawMark(g1, theCoord0, myPen3, myBrush1, px[i], py[i], xyspan, iMark, sizMark);
		};
		delete[] px; delete[] py;
	};

};

} }

