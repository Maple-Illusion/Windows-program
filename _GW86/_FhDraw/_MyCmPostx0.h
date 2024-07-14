//GW86_FhDraw_MyCmPostx0.h
//Gao-Wei Chang, 220306, 211122, 210912, 210902, 210831, 200603, 180527, 171010.
#pragma once
#include "_MyCmTabID0.h"
namespace GW86 {
namespace FhDraw {
using namespace System;
using namespace System::Windows::Forms;
public ref class MyCmPostx0: public MyCmTab0 {
public:
static array<float>^ opds2valGeo(array<double>^ opds) {
	array<float>^ valGeo = gcnew array<float>(LEN_GEO);
	for (int i = 0; i < LEN_GEO; i++) valGeo[i] = float(opds[i]);
	return valGeo;
};

public:
static array<String^>^ cmDivArr(String^ szInput, String^ szSepa) {
	//array<Char>^ chArr = MyCmPostx0::_filtSepSpa(szSepa);
	array<Char>^ chArr = _filtSepSpa(szSepa);
	array<String^>^ divArr0 = szInput->Split(chArr);
	int nDiv = divArr0->Length;
	if (nDiv > NO_DIV) return divArr0;
	array<String^>^ divArr1 = gcnew array<String^>(NO_DIV);
	for (int i = 0; i < NO_DIV; i++) divArr1[i] = "";
	for (int i = 0; i < nDiv; i++) {
		divArr1[i] = _filtDivSpa(divArr0[i]);
	};
	return divArr1;
};

public:
static array<Char>^ _filtSepSpa(String^ szSepa) {
	array<String^>^ sepaArr = szSepa->Split();
	int len = sepaArr->Length; int cnt = 0;
	array<String^>^ szTmp = gcnew array<String^>(len);
	for (int i = 0; i < len; i++) {
		if (sepaArr[i] != "") {
			szTmp[cnt] = sepaArr[i]; cnt++;
		};
	};
	array<Char>^ chArr = gcnew array<Char>(cnt);
	for (int i = 0; i < cnt; i++) {
		if (szTmp[i]->Length != 1) {
			MessageBox::Show("Error: multiple chars.");
			array<Char>^ errChArr = { 'F' };
			return errChArr;
		};
		chArr[i] = Convert::ToChar(szTmp[i]);
	};
	return chArr;
};

public:
static String^ _filtDivSpa(String^ cmDiv) {
  array<String^>^ szArr = cmDiv->Split();
  int len =szArr->Length; int cnt = 0;
  array<String^>^ filterArr = gcnew array<String^>(len);
  for (int i = 0; i < len; i++) {
	  if (szArr[i] != "") {
		  filterArr[cnt] = szArr[i]; cnt++;
	  };
  };
  String^ szFilterDiv = "";
  for (int i = 0; i < cnt; i++) {
	  szFilterDiv += filterArr[i];
	  if (i < cnt - 1) szFilterDiv += " ";
  };
  return szFilterDiv;
};

public:
static array<bool>^ setDivState(array<String^>^ divArr) {
	array<bool>^ bDiv = gcnew array<bool>(NO_DIV);
	for (int i = 0; i < NO_DIV; i++) {
		bDiv[i] = 0; if (divArr[i] != "") bDiv[i] = 1;
	};
	return bDiv;
}

public: //可適用於精簡版，但具較高容忍度
static array<double>^ szOpdsEval(String^ szOpdsInp, String^ szOpdsTxt) {
  array<double>^ opdsInp = _szOpds2VA(szOpdsInp);
  array<double>^ opdsTxt = _szOpds2VA(szOpdsTxt);
  int len0 = opdsTxt->Length;
  int len1 = opdsInp->Length;
  //if (len1<len0) return opdsTxt;
  if (len1 > len0) {
	  for (int i = 0; i < len0; i++)
		  opdsTxt[i] = opdsInp[i];
  };
  return opdsTxt;
}//於容錯版，此處修訂為若讀入字串之數字欄位長度較預設者短，則以預設者為準。
//此外，若讀入字串之數字欄位長度較預設者長，則取與預設者等長部分。

public: //不適用於精簡版，但具較高容忍度
static array<double>^ szOpdsEvalx(String^ szOpdsInp, String^ szOpdsTxt) {
  array<double>^ opdsInp = _szOpds2VA(szOpdsInp);
  array<double>^ opdsTxt = _szOpds2VA(szOpdsTxt);
  int len = opdsInp->Length;
  for (int i = 0; i < len; i++)
    opdsTxt[i] = opdsInp[i];
  return opdsTxt;
}

public:
static array<double>^ _szOpds2VA(String^ szOpds) {
	array<String^>^ szArr = szOpds->Split();
	int len = szArr->Length;
	int cnt = 0;
	array<String^>^ szTmp = gcnew array<String^>(len);
	for (int i = 0; i < len; i++) {
		if (szArr[i] != "") {
			szTmp[cnt] = szArr[i]; cnt++;
		};
	};
	array<double>^ opds = gcnew array<double>(cnt);
	for (int i = 0; i < cnt; i++) {
		try {
			opds[i]=Convert::ToDouble(szTmp[i]); }
		catch (FormatException^ e) {
			MessageBox::Show(e->Message);
		};
	};
	return opds;
}

public:
static String^ va2szOpds(array<double>^ opds) {
  int len = opds->Length;
  String^ szOpds = "";
  for (int i = 0; i < len; i++) {
	  szOpds += opds[i].ToString();
	  if (i < len - 1) szOpds += " ";
  };
  return szOpds;
}

public:
static array<double>^ cmTaFzMa(String^ divArr0, int* pidOpc, int* piErr) {
	array<String^>^ szCmd = divArr0->Split();
	int cmLen = szCmd->Length; *piErr = 0;
	array<double>^ opds = gcnew array<double>(cmLen - 1);//扣除opcode
	int len = MyCmTab0::szOpcSet->Length;
	if (len != MyCmTab0::idOpcSet->Length)
		*piErr = ERR_OPCSET;
    bool bOpc = false;
	for (int i=0; i<len; i++) {
      if (szCmd[0]==szOpcSet[i]) {
		*pidOpc =  idOpcSet[i];
		bOpc=true; break;
	}; };
	if (!bOpc) *piErr = ERR_OPC;
	for (int i = 0; i < cmLen - 1; i++) { //扣除opcode
		try { opds[i] = Convert::ToDouble(szCmd[i + 1]); }
		catch (FormatException^ e) {
			MessageBox::Show(e->Message);
			*piErr = ERR_OPDS;
		};
	};
    return opds;
};

public: static void cmErrHnd(int iErr) {
  switch (iErr) {
    case ERR_OPCSET:
	  MessageBox::Show("Error in setting opcSet.");
	  break;
	case ERR_OPC:
	  MessageBox::Show("Error in the opcode.");
	  break;
	case ERR_OPDS:
		MessageBox::Show("Error in the opds.");
		break;
  };
};

};
} }

