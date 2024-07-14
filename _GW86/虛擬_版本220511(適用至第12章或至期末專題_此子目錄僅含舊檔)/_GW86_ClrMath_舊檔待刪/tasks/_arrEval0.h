//gw86_clrMath_arrEval0.h
//Gao-Wei Chang, 170624.
using namespace System;
namespace GW86 {
namespace ClrMath {
public ref class MyArrEval0 {
  public:
  static array<double>^ sum(array<String^>^ szArr1,
	array<String^>^ szArr2) {
	int len = szArr1->Length;
	array<double>^ hnd_sum = gcnew array<double>(len);
	for (int i = 0; i < len; i++) {
	  hnd_sum[i]=Convert::ToDouble(szArr1[i])+
		                  Convert::ToDouble(szArr2[i]); };
	return hnd_sum;
  };

  static double innerPro(array<String^>^ szArr1,
	array<String^>^ szArr2) {
	int len = szArr1->Length;
    double summ=0;
	for (int i = 0; i < len; i++) {
	  summ+=Convert::ToDouble(szArr1[i])*
		            Convert::ToDouble(szArr2[i]); };
	return summ;
  };
};
} }