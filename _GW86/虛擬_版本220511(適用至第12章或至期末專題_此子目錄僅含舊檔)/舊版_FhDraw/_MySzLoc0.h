//GW86_FhDraw_MySzLoc0.h.
//Gao-Wei Chang, 200713.
#pragma once
namespace GW86 {
namespace FhDraw {
public ref class MySzLoc0 {
#define DH_SPA 15
#define OFFSET 12
public:
static int dhInc(int nList) {
  static int iList = 0;
  int dh = iList * DH_SPA + OFFSET;
  iList++; if (iList >= nList) iList = 0;
  return dh;
}

};
} }

