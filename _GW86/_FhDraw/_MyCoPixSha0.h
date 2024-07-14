//GW86_FhDraw_MyCoPixSha0.h.
//Gao-Wei Chang, 210829, 210820, 200913, 200713.
#pragma once
#include <math.h>
#define PI 3.14159
namespace GW86 {
namespace FhDraw {
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
public ref class MyCoPixSha0 {
public:
static void drawClkMark(Graphics^ g1, Pen^ myPen1, Font^ myFont1, array<float>^shaGeo) {
  float pbx0 = shaGeo[0]; float pby0 = shaGeo[1];
  float patth = shaGeo[3];
  g1->DrawEllipse(myPen1, pbx0 - (patth / 2), pby0 - (patth / 2), patth, patth); //圖形盒寬度之半為直徑
  g1->DrawString(L"12", myFont1, Brushes::Blue, float(pbx0 - 11), float(pby0 - patth*2 / 3));
  g1->DrawString(L"6", myFont1, Brushes::Blue, float(pbx0 - 7), float(pby0 + patth*2 / 3 - 19));
  g1->DrawString(L"3", myFont1, Brushes::Blue, float(pbx0 - 18 + patth*2 / 3), float(pby0 - 10));
  g1->DrawString(L"9", myFont1, Brushes::Blue, float(pbx0 - patth*2 / 3 + 2), float(pby0 - 10));
};

public:
static void drawClkHLine(Graphics^ g1, Pen^ myPen1, array<float>^ shaGeo) {
  float pbx0 = shaGeo[0]; float pby0 = shaGeo[1];
  float patth = shaGeo[3];
  float x0 = pbx0 - (patth / 2); //具初始角度設定
  float y0 = pby0, y1 = y0;
  float x1 = pbx0 + (patth / 2);
  g1->DrawLine(myPen1, x0, y0, x1, y1);
};

public:
static void drawClkVLine(Graphics^ g1, Pen^ myPen1, array<float>^ shaGeo) {
	float pbx0 = shaGeo[0]; float pby0 = shaGeo[1];
	float patth = shaGeo[3];
	float x0 = pbx0; //具初始角度設定
	float y0 = pby0-(patth / 2), y1 = pby0 + (patth / 2);
	float x1 = x0;
	g1->DrawLine(myPen1, x0, y0, x1, y1);
};

public:
static void drawClkCross(Graphics^ g1, Pen^ myPen1, array<float>^ clkGeo) {
	MyCoPixSha0::drawClkHLine(g1, myPen1, clkGeo);
	MyCoPixSha0::drawClkVLine(g1, myPen1, clkGeo);
}

public:
static void drawClkLine(Graphics^ g1, Pen^ myPen1,
  array<float>^ shaGeo, int cnt, int nSlice) {
  float pbx0 = shaGeo[0]; float pby0 = shaGeo[1];
  float len = shaGeo[3];
  float theta = float(2 * PI * cnt / nSlice);
  float x1 = float(pbx0 - (len / 2) * cos(theta + PI / 2)); //具初始角度設定
  float y1 = float(pby0 - (len / 2) * sin(theta + PI / 2));
  g1->DrawLine(myPen1, pbx0, pby0, x1, y1);
};

public:
static void drawCirLine(Graphics^ g1, Pen^ myPen1, array<float>^ shaGeo, int cnt, int nSlice) {
  float pbx0 = shaGeo[0]; float pby0 = shaGeo[1];
  float len = shaGeo[3];
  float theta = float(2 * PI * cnt / nSlice);
  float x0 = float(pbx0 - (len / 2) * cos(theta + PI / 2));
  float y0 = float(pby0 - (len / 2) * sin(theta + PI / 2));
  float x1 = float(pbx0 + (len / 2) * cos(theta + PI / 2));
  float y1 = float(pby0 + (len / 2) * sin(theta + PI / 2));
  g1->DrawLine(myPen1, x0, y0, x1, y1);
};

public:
static void drawCoRect(Graphics^ g1, Pen^ myPen1,
	array<float>^ shaGeo, int cnt, int nSlice) {
	float pbx0 = shaGeo[0];	float pby0 = shaGeo[1];
	float pattw = shaGeo[2]; float patth = shaGeo[3];
	float w = pattw * cnt / nSlice;
	float h = patth * cnt / nSlice;
	g1->DrawRectangle(myPen1, (pbx0 - w / 2), (pby0 - h / 2), w, h);
};

static void fillCoRect(Graphics^ g1, Brush^ myBrush1,
	array<float>^ shaGeo, int cnt, int nSlice) {
	float pbx0 = shaGeo[0];	float pby0 = shaGeo[1];
	float pattw = shaGeo[2]; float patth = shaGeo[3];
	float w = pattw * cnt / nSlice;
	float h = patth * cnt / nSlice;
	g1->FillRectangle(myBrush1, (pbx0 - w / 2), (pby0 - h / 2), w, h);
};

public:
static void drawCoEllip(Graphics^ g1, Pen^ myPen1,
  array<float>^ shaGeo, int cnt, int nSlice) {
  float pbx0 = shaGeo[0];	float pby0 = shaGeo[1];
  float pattw = shaGeo[2]; float patth = shaGeo[3];
  float w = pattw * cnt / nSlice;
  float h = patth * cnt / nSlice;
  g1->DrawEllipse(myPen1, (pbx0 - w / 2), (pby0 - h / 2), w, h);
};

public:
static void fillCoEllip(Graphics^ g1, Brush^ myBrush1,
  array<float>^ shaGeo, int cnt, int nSlice) {
  float pbx0 = shaGeo[0];	float pby0 = shaGeo[1];
  float pattw = shaGeo[2]; float patth = shaGeo[3];
  float w = pattw * cnt / nSlice;
  float h = patth * cnt / nSlice;
  g1->FillEllipse(myBrush1, (pbx0 - w / 2), (pby0 - h / 2), w, h);
};


};
} }


