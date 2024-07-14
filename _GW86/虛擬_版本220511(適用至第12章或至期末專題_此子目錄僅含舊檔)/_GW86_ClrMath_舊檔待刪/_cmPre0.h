//GW86_ClrMath_CmPre0.h
//Gao-Wei Chang, 210412, 170610, 160701.
#pragma once
namespace GW86 {
namespace ClrMath_CmPre {
using namespace System;
public ref class MyCmSepaPre0 {
public:
  static array<String^>^ cmSepaPre(array<String^>^ szFzArr, int* pLen) {
    array<String^>^ cmPreArr = gcnew array<String^>(*pLen);
    int cnt=0;
    for (int i=0; i<*pLen; i++) {
      if (szFzArr[i]!="") { 
        cmPreArr[cnt]=szFzArr[i]; cnt++; };
	};
    *pLen=cnt;
    return cmPreArr;
  };
}; 
}}

//(註)：
//命令前置處理係檢驗具連續分隔符號分佈的複雜字串分割後，所形成的字串陣列的元素。
//例如，具有兩個相鄰的分隔符號字串，其分隔後形成一空的字串，即""。