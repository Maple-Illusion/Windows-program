//_MyIMBox0.h (¥Ø¿ý_GW86_FmTasks)
//Gao-Wei Chang, 180502.
#pragma once
namespace GW86 {
namespace FmTasks {
public ref class MyIMBox0 {
public:
  int cnt;
  MyFmLab0^ hnd;
  MyIMBox0(int cnt) {
    this->cnt=cnt;
  };
  void show() {
	hnd=gcnew MyFmLab0(this->cnt);
    Application::Run(hnd);
  };
  void tmd() {
    for (int i=0; i<100; i++) {
	  MyTaskCnt0::tmd(5);
	  hnd->label1->Text=
		  Convert::ToString((this->cnt)+i); };
  };
};
} }
