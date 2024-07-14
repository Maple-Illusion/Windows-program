//_mid0_clmFzMaVaSe0_例外處理.cpp
//Gao-Wei Chang, 211004, 210412, 200429, 180422, 170610, 160701, 160422.
#include "c:\_GW86\_ClrMathMid\mid0_clmFzMaVaSe0.h"
using namespace System;
using namespace clmFzMaVaSe;

void main() {
  Console::WriteLine("數值計算作業系統：VC++/CLR版"); //(0.1a)
  Console::WriteLine("(Gao-Wei Chang, 211004, 160422)"); //(0.1b)
  array<String^>^ opcSerSet = { "exp", "sin", "cos"};
  while (1) {
	  Console::Write(">>"); //(1.1)
	  String^ szInput = Console::ReadLine(); //(1.2)
	  array<String^>^ szCmd = szInput->Split(); //(1.3)
	  if (szCmd[0] == "quit") break;
	  if (!MyCmTaskHnd0::cmFzMaVaSe(szCmd, opcSerSet))
	    Console::WriteLine("Error in format (or opcode)");
  };
  Console::Write("請按任意鍵。"); Console::Read();
}

//(註)：
//(2.1)-(2.4)為具有前置處理版本。
//此外無前置處理版可取消字元陣列sepaSet的定義。








