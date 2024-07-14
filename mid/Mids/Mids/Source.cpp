#include "C:\Users\ataraxia\Documents\AV_LAB\NTNU_Cpp\_GW86\_ClrMathMid\mid5_clmPrePostxStA0.h"
using namespace System;
using namespace clmPrePostxStA;

void main() {
    Console::WriteLine("數值計算作業系統：VC++/CLR版"); //(0.1a)
    Console::WriteLine("(Gao-Wei Chang, 211004, 160422)"); //(0.1b)
    array<String^>^ opcSerSet = { "exp", "sin", "cos", "sinc", "atan" };
    array<String^>^ opcArrSet = { "arrsum", "innpro" };
    array<Char>^ sepaSet = { ' ', ',', ';' };
    while (1) {
        Console::Write(">>"); //(1.1)
        String^ szInput = Console::ReadLine(); //(1.2)
        array<String^>^ cmFzArr = szInput->Split(sepaSet); //(2.1)
        int len = cmFzArr->Length;
        array<String^>^ cmPreArr = gcnew array<String^>(len); //(2.3)
        cmPreArr = MyCmPre0::cmSepaPre(cmFzArr, &len); //(2.4)
        if (cmPreArr[0] == "quit") break;
        if (cmPreArr[0] == "help")
            MyCmHelp0a::opcHelp(opcSerSet, opcArrSet);
        else if (!MyCmTaskHnd0::cmFzMaVxStA(cmPreArr,
            opcSerSet, opcArrSet))
            Console::WriteLine("Error in format (or opcode).");
    };
    Console::Write("請按任意鍵。"); Console::Read();
}