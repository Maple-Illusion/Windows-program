//_mid1_clmFzMhVaSe0_�ҥ~�B�z.cpp
//Gao-Wei Chang, 230227, 211004, 200429, 180422, 170610, 160422.
#include "c:\_GW86\_ClrMathMid\mid1_clmFzMhVaSe0.h"
using namespace System;
using namespace clmFzMhVaSe;

void main() {
  Console::WriteLine("�ƭȭp��@�~�t�ΡGVC++/CLR��"); //(0.1a)
  Console::WriteLine("(Gao-Wei Chang, 211004, 160422)"); //(0.1b)
  array<String^>^ opcSerSet = { "exp", "sin", "cos"};
  while (1) {
	  Console::Write(">>"); //(1.1)
	  String^ szInput = Console::ReadLine(); //(1.2)
	  array<String^>^ szCmd = szInput->Split(); //(1.3)
	  if (szCmd[0] == "quit") break;
	  if (szCmd[0] == "help")
		  MyCmHelp0::opcHelp(opcSerSet);
	  else if(!MyCmTaskHnd0::cmFzMaVaSe(szCmd, opcSerSet))
		  Console::WriteLine("Error in format (or opcode)");
  };
  Console::Write("�Ы����N��C"); Console::Read();
}

//(��)�G
//(2.1)-(2.4)���㦳�e�m�B�z�����C
//���~�L�e�m�B�z���i�����r���}�CsepaSet���w�q�C








