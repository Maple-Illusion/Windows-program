//GW86_ClrMath_CmPre0.h
//Gao-Wei Chang, 170610, 160701.
#pragma once
namespace GW86 {
namespace ClrMath_CmPre {
using namespace System;
public ref class MyCmSepaPre0 {
public:
  static int cmSepa_len(array<String^>^ cmFzArr) {
    int szCnt=0;
    for (int i=0; i<cmFzArr->Length; i++) {
      if (cmFzArr[i]!="") szCnt++; };
    return szCnt;
  };

  static array<String^>^ cmSepaPre(array<String^>^ szCmd, int szCnt) {
    array<String^>^ cmFzArr = gcnew array<String^>(szCnt);
    int cnt=0;
    for (int i=0; i<szCmd->Length; i++) {
      if (szCmd[i]!="") { 
        cmFzArr[cnt]=szCmd[i]; cnt++; };
	};
    return cmFzArr;
  };
}; 

}}

//(��)�G
//�R�O�e�m�B�z�Y�����s����j�Ÿ����G�������r����Ϋ�A�ҧΦ����r��}�C�������C
//�Ҧp�A�㦳��Ӭ۾F�����j�Ÿ��r��A����j��Φ��@�Ū��r��A�Y""�C