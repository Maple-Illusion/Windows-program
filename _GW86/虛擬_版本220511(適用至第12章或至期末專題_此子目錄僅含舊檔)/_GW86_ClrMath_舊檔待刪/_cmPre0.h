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

//(��)�G
//�R�O�e�m�B�z�Y�����s����j�Ÿ����G�������r����Ϋ�A�ҧΦ����r��}�C�������C
//�Ҧp�A�㦳��Ӭ۾F�����j�Ÿ��r��A����j��Φ��@�Ū��r��A�Y""�C