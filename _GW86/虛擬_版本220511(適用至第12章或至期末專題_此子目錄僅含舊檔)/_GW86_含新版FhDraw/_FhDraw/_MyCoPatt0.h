//GW86_FhDraw_MyCoPatt0.h.
//Gao-Wei Chang, 200913, 200713.
#pragma once
#include <math.h>
#define PI 3.14159
namespace GW86 {
	namespace FhDraw {
		using namespace System;
		using namespace System::Windows::Forms;
		using namespace System::Drawing;
		public ref class MyCoPatt0 {
		public:
			static void drCirLine(Graphics^ g1, Pen^ myPen1,
				int cnt, int nSlice, int pbx0, int pby0, int pbh) {
				double len = pbh / 2;
				double theta = 2 * PI * cnt / nSlice;
				int x0 = int(pbx0 - (len / 2) * cos(theta + PI / 2));
				int y0 = int(pby0 - (len / 2) * sin(theta + PI / 2));
				int x1 = int(pbx0 + (len / 2) * cos(theta + PI / 2));
				int y1 = int(pby0 + (len / 2) * sin(theta + PI / 2));
				g1->DrawLine(myPen1, x0, y0, x1, y1);
			}
			static void drClkLine(Graphics^ g1, Pen^ myPen1,
				int cnt, int nSlice, int pbx0, int pby0, int pbh) {
				double len = pbh / 2;
				double theta = 2 * PI * cnt / nSlice;
				int x1 = int(pbx0 - (len / 2) * cos(theta + PI / 2)); //具初始角度設定
				int y1 = int(pby0 - (len / 2) * sin(theta + PI / 2));
				g1->DrawLine(myPen1, pbx0, pby0, x1, y1);
			}

		public:
			static void drCoRect(Graphics^ g1, Pen^ myPen1,
				int cnt, int nSlice, int pbx0, int pby0, int pattw, int patth) {
				int w = pattw * cnt / nSlice;
				int h = patth * cnt / nSlice;
				g1->DrawRectangle(myPen1, (pbx0 - w / 2), (pby0 - h / 2), w, h);
			}

		public:
			static void drCoEllip(Graphics^ g1, Pen^ myPen1,
				int cnt, int nSlice, int pbx0, int pby0, int pattw, int patth) {
				int w = pattw * cnt / nSlice;
				int h = patth * cnt / nSlice;
				g1->DrawEllipse(myPen1, (pbx0 - w / 2), (pby0 - h / 2), w, h);
			};
		};

	}
}


