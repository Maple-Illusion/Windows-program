//_MyIMBox0.h (¥Ø¿ý_GW86_FmTasks)
//Gao-Wei Chang, 180502.
#pragma once
namespace GW86 {
namespace FmTasks {
public ref class MyIMBcm0 {
public:
  int cnt, tot, td;
  MyFmLab0^ hnd;
  MyIMBcm0(int cnt, int tot, int td) {
    this->cnt=cnt; this->tot=tot;
	this->td=td;
  };
  void show() {
	hnd=gcnew MyFmLab0(this->cnt);
    Application::Run(hnd);
  };
  void tmd() {
    for (int i=0; i<this->tot; i++) {
	  MyTaskCnt0::tmd(this->td);
	  hnd->label1->Text=
		  Convert::ToString((this->cnt)+i); };
  };
};
} }
