//_MyFmPhSE0.cpp
//Gao-Wei Chang, 180514.
#include "c:\_GW86_FmTasks\_ClrMath\_MySExpp0x.h"
#include "c:\_GW86_FmTasks\_ClrMath\_MyFmPhase0.h"
#include "c:\_GW86_FmTasks\_ClrMath\_MyFmPhSE0.h"

using namespace GW86::FmTasks;
void MyFmSExp0::button1_Click(Object^ s, EventArgs^ e) {
  textBox1->Text ="sin 0.125 10";
  //theDial1=gcnew MyFmPhase0;
  //theDial1->Show();
}

void MyFmSExp0::button2_Click(Object^ s, EventArgs^ e) {
  String^ szInput = textBox1->Text;
  array<String^>^ szCmd = szInput->Split();
  int len=szCmd->Length;
  int opcode_id;
  bool flag_opcode=false;
  for (int i=0; i<len; i++) {
    if (szCmd[0]==szOpcSet_ser[i]) {
	  opcode_id=i; flag_opcode=true; break; };
  };
  if (!flag_opcode) {
    MessageBox::Show("opcode mismatch.");
	return;
  };
  double x=Convert::ToDouble(szCmd[1]);
  int n=Convert::ToInt32(szCmd[2]);
  _seriesExpp(opcode_id, x, n);
}

void MyFmSExp0::button3_Click(Object^ s, EventArgs^ e) {
  textBox1->Text =""; textBox2->Text =""; szTotal = "";
}

void MyFmSExp0::_seriesExpp(int opcode_id, double x, int n) {
  double ratio_x = x;
  if (MyFmPhase0::flag_phase[1])
	 ratio_x = x/(2*PI);
  if (MyFmPhase0::flag_phase[2])
	 ratio_x = x/360;
  double theta_x = 2*PI*ratio_x;//Ñy«×radian3.14159=¨¤«×180¡C
  MySExpp0x obj;
  switch (opcode_id) {
    case ID_EXP:
	  for (int i = 0; i < n; i++) {
		  double va=obj.exp(x, i);
		  String^ szVa = va.ToString("0.00000");
		  szTotal ="["+i+"] " +szVa+"\r\n";
		  this->textBox2->Text += szTotal; };
	  break;
	case ID_SIN:
	  for (int i = 0; i < n; i++) {
		  double va=obj.sin(theta_x, i);
		  String^ szVa = va.ToString("0.00000");
		  szTotal ="["+i+"] " +szVa+"\r\n";
		  this->textBox2->Text += szTotal; };
	    break;
	  case ID_COS:
	    for (int i = 0; i < n; i++) {
		  double va=obj.cos(theta_x, i);
		  String^ szVa = va.ToString("0.00000");
		    szTotal ="["+i+"] " +szVa+"\r\n";
		  this->textBox2->Text += szTotal; };
		break;
	}; 
  };


