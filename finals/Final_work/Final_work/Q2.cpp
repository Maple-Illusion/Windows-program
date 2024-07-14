
#include "Q2_F.h"

using namespace F2;


void myform::_drawGeo
(Pen^ myPen1, int idOpc, array<double>^ opds) {
	Picbox1->Refresh();
	int x0, y0, x1, y1, w, h;
	x0 = int(opds[0]); y0 = int(opds[1]);
	switch (idOpc) {
	case ID_LINE:
		x1 = int(opds[2]); y1 = int(opds[3]);
		G1->DrawLine(myPen1, x0, y0, x1, y1);
		break;
	case ID_RECTANGLE:
		w = int(opds[2]); h = int(opds[3]);
		G1->DrawRectangle(myPen1, x0, y0, w, h);
		break;
	case ID_ELLIPSE:
		w = int(opds[2]); h = int(opds[3]);
		G1->DrawEllipse(myPen1, x0, y0, w, h);
		break;
	};
}
