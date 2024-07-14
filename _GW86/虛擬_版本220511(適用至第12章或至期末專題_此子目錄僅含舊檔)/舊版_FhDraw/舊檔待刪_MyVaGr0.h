//GW86_FhDraw_MyVGra0.h.
//Gao-Wei Chang, 210827, 210816, 201012, 180611, 160707, 140307.
#pragma once
#include "c:\_GW86\_FhDraw\_MyRect0.h"
#include "c:\_GW86\_ClrMath\_MySExppStat0.h"
//#include "c:\_GW86\_FhDraw\_MyGraphID0.h"
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

