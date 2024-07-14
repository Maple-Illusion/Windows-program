//GW86_FhDraw_MyVGra0.h.
//Gao-Wei Chang, 210827, 210816, 201012, 180611, 160707, 140307.
#pragma once
#include "c:\_GW86\_FhDraw\_MyRect0.h"
#include "c:\_GW86\_ClrMath\_MySExppStat0.h"
#include "c:\_GW86\_FhDraw\_MyGraphID0.h"
#define PI 3.14159
namespace GW86 {
namespace FhDraw {
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace GW86::ClrMath;

public ref class MyVaGr0 {
public: static void val2pixCoord(MyRect0^ theCoord0, float xval, float yval,
	float* px_coord, float* py_coord, array<float>^ xyspan) {
	float xmin = xyspan[0]; float xmax = xyspan[1];
	float ymin = xyspan[2]; float ymax = xyspan[3];
	float rx = (xval - xmin) / (xmax - xmin);
	float ry = (yval - ymin) / (ymax - ymin);
	*px_coord = (theCoord0->x_begin) + //(1.2a)
		    rx * (theCoord0->x_end - theCoord0->x_begin); 
	*py_coord = (theCoord0->y_end) - //(1.2b)
		    ry * (theCoord0->y_end - theCoord0->y_begin); 
};

public: static void val2pixSize(MyRect0^ theCoord0, float xsize, float ysize,
	float* px_pixels, float* py_pixels, array<float>^ xyspan) {
	float xmin = xyspan[0]; float xmax = xyspan[1];
	float ymin = xyspan[2]; float ymax = xyspan[3];
	float rx = xsize / (xmax - xmin);
	float ry = ysize / (ymax - ymin);
	*px_pixels = rx * (theCoord0->x_end - theCoord0->x_begin);
	*py_pixels =ry * (theCoord0->y_end - theCoord0->y_begin);
};

public: static array<float>^ val2pixGeo(MyRect0^ theCoord0,
	array<float>^ valGeo, array<float>^ xyspan) {
	float xk_loc, yk_loc, w_pix, h_pix;
	MyVaGr0::val2pixCoord(theCoord0, valGeo[0], valGeo[1],
		&xk_loc, &yk_loc, xyspan);
	MyVaGr0::val2pixSize(theCoord0, valGeo[2], valGeo[3],
		&w_pix, &h_pix, xyspan);
	array<float>^ pixGeo = gcnew array<float>(LEN_GEO);
	pixGeo[0] = xk_loc; pixGeo[1] = yk_loc;
	pixGeo[2] = w_pix; pixGeo[3] = h_pix;
	return pixGeo;
};//列管類別資料成員無法取得原生變數位址

public:
static void drawXYAxes(Graphics^ g1, MyRect0^ theCoord0,
  Pen^ myPen1, float xval, float yval, array<float>^ xyspan) {
  float x_coord, y_coord;
  //evalMidAxes(theCoord0, &x_coord, &y_coord, xyspan);
  val2pixCoord(theCoord0, xval, yval, &x_coord, &y_coord, xyspan);
  g1->DrawLine(myPen1, theCoord0->x_begin, y_coord,
		  theCoord0->x_end, y_coord); //(2.1)
  g1->DrawLine(myPen1, x_coord, theCoord0->y_begin,
		  x_coord, theCoord0->y_end); //(2.2)
};

public:
static void drawStem(Graphics^ g1, MyRect0^ theCoord0, Pen^ myPen1,
  float xval, float yval, array<float>^ xyspan) {
  float xmin = xyspan[0]; float xmax = xyspan[1];
  float ymin = xyspan[2]; float ymax = xyspan[3];
  float x_coord, y_coord, y_coord0;
  val2pixCoord(theCoord0, xval, yval, &x_coord, &y_coord, xyspan);
  val2pixCoord(theCoord0, xval, 0, &x_coord, &y_coord0, xyspan);
  g1->DrawLine(myPen1, x_coord, y_coord, x_coord, y_coord0); //(2.1)
};

public:
static void drawCross(Graphics^ g1, Pen^ myPen1,
  float x_coord, float y_coord, float w, float h) {
	g1->DrawLine(myPen1, x_coord - (w /2),  //(2.1)
		y_coord - (h/2), x_coord + (w / 2), y_coord + (h / 2));
	g1->DrawLine(myPen1, x_coord + (w / 2),  //(2.1)
		y_coord - (h / 2), x_coord - (w / 2), y_coord + (h/ 2));
};

public:
static void drawMark(Graphics^ g1, MyRect0^ theCoord0,
  Pen^ myPen1, Brush^ myBrush1, float xval, float yval,
	array<float>^ xyspan, int iMark, float sizMark) {
	float x_coord, y_coord;
	val2pixCoord(theCoord0, xval, yval, &x_coord, &y_coord, xyspan);
	switch (iMark) {	//Brush^ myBrush1 = Brushes::Red;
	  case ID_CROSS:  drawCross(g1, myPen1, x_coord, y_coord, sizMark, sizMark);  break;
      case ID_RECT: g1->DrawRectangle(myPen1, x_coord - (sizMark / 2),  //(2.1)
				            y_coord - (sizMark / 2), sizMark, sizMark); break;
	  case ID_ELLIP: g1->DrawEllipse(myPen1, x_coord - (sizMark / 2), //(2.2)
				            y_coord - (sizMark / 2), sizMark, sizMark); break;
	  case ID_FRECT: g1->FillRectangle(myBrush1, x_coord - (sizMark / 2), //(2.3)
			                 y_coord - (sizMark / 2), sizMark, sizMark); break;
	  case ID_FELLIP: g1->FillEllipse(myBrush1, x_coord - (sizMark / 2), //(2.4)
				y_coord - (sizMark / 2), sizMark, sizMark); break;
		};
};

public:
static void drawSeg(Graphics^ g1, MyRect0^ theCoord0, Pen^ myPen1,
	float xval, float yval, array<float>^ xyspan, int xNum) {
	static int i = 0, nTerm = 0;
	static float x_coord[2], y_coord[2];
	if (xNum == 0) { nTerm = 0; return; };//(1.1):當xNum=0時，重置端點。
	val2pixCoord(theCoord0, xval, yval, &x_coord[i], &y_coord[i], xyspan);
	if ((nTerm == 0) || (nTerm == xNum))//判斷是否為起始點與終點
		g1->DrawLine(myPen1, x_coord[i], y_coord[i],
			x_coord[i], y_coord[i]);
	else g1->DrawLine(myPen1, x_coord[0], y_coord[0],
		x_coord[1], y_coord[1]); //(2.1)
	if (i == 0) i = 1; else i = 0; //(2.2):連續地，非0則1。
	if (nTerm < xNum) nTerm++; else nTerm = 0;//(2.3):0至xNum-1。
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

/*public: static void evalMidAxes(MyRect0^ theCoord0,
	float* px_mid, float* py_mid, array<float>^ xyspan) {
  float xmin = xyspan[0]; float xmax = xyspan[1];
  float ymin = xyspan[2]; float ymax = xyspan[3];
  float xmid = (xmax + xmin) / 2;
  float ymid = (ymax + ymin) / 2;
  val2pCoord(theCoord0, xmid, ymid, px_mid, py_mid, xyspan);
};

public:
static void drawMidAxes(Graphics^ g1, MyRect0^ theCoord0,
  Pen^ myPen1, array<float>^ xyspan) {
  float x_mid, y_mid;
  evalMidAxes(theCoord0, &x_mid, &y_mid, xyspan);
  g1->DrawLine(myPen1, theCoord0->x_begin, y_mid,
										  theCoord0->x_end, y_mid); //(2.1)
  g1->DrawLine(myPen1, x_mid, theCoord0->y_begin,
										  x_mid, theCoord0->y_end); //(2.2)
};*/

