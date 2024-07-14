//_MyCmPost0.h
//Gao-Wei Chang, 220507, 200603, 200531, 180527, 171010.
#pragma once
namespace GW86 {
namespace FpDraw {
using namespace System;
using namespace System::Windows::Forms;
public ref class MyCmPost0 {
public:
  static int cmFzMa(array<String^>^ szCmd,
	array<String^>^ szOpcSet, array<double>^ opds) {
	int idOpc; bool bOpc = false;
	int len = szOpcSet->Length;
	for (int i=0; i<len; i++) {
      if (szCmd[0]==szOpcSet[i]) {
		idOpc = ID_LINE+i;
		bOpc=true; break;
	}; };
	if (!bOpc) return ID_ERROR;
	len = szCmd->Length;
	for (int i = 0; i < len-1; i++) { //扣除opcode
	  try { opds[i] = Convert::ToDouble(szCmd[i + 1]); }
	  catch (FormatException^ e) {
		MessageBox::Show(e->Message);
		return ID_ERROR;}; 
	};
    return idOpc;
  };
};
}
}

//(註)：
//在此標頭檔中，命令後處理函式
//MyCmPostDraw0::cmFzMaGeo
//可視為一般命令後處理之模版。
//新增。用於直接繪製原始數值座標。
//if ((!bOpc)||(szCmd->Length<NO_FIELDS))