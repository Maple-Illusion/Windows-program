//GW86_ClrStrings_MyString0.h
//����System::Windows::Forms::Form���R�W
//Gao-Wei Chang, 180428, 171023, 140409.
#pragma once
namespace GW86 {
namespace ClrStrings {
using namespace System;
using namespace System::Collections; //���n�C
using namespace System::Windows::Forms; //���n�C

public ref class MyString0 {
  private: static array<Char>^ cmSepa = {' ', ',', '\r', '\n', //(0.1a)
			    '\t', '(', ')', '[', ']' , '{', '}', '<', '>'};
  //���i�]�t�R�O�����r��';'�A�H�K�P�_�R�O�r��P�ƭ����r��
  //²��a���A�O�d�r��';'�ΥH�ѧO�R�O�μƭȰ}�C�C(�D�`���n)
  private: static array<Char>^ vaSepa = {' ', ',', ';', '\r', '\n', //(0.1b)
			    '\t', '(', ')', '[', ']' , '{', '}', '<', '>'}; //��cmSepa�h�C�@�Ӧr��';'
  public:
    static int szCm2fzA
		         (String^ szInput, array<String^>^ fzArr) {
        array<String^>^ szArr = szInput->Split(cmSepa); //(1.1)
        IEnumerator^ enArr = szArr->GetEnumerator(); //(1.2)
        int cnt = 0; //(1.3)
        while (enArr->MoveNext()) { //(1.4)
	      String^ str=safe_cast<String^>(enArr->Current); //(1.5)
	       if (str->Trim()!="") { fzArr[cnt] = str; cnt++; }; }; //(1.6)
	    return cnt; //(1.7)
	  }; //End of szCm2fzA(...);
	  //�q���Φh�����r���إ����r��}�C�A�íp��䤸���ƥ�

	 public:
	  static int szVA2fzA
		         (String^ szInput, array<String^>^ fzArr) {
        array<String^>^ szArr = szInput->Split(vaSepa); //(2.1)
        IEnumerator^ enArr = szArr->GetEnumerator(); //(2.2)
        int cnt = 0; //(2.3)
        while (enArr->MoveNext()) { //(2.4)
	      String^ str=safe_cast<String^>(enArr->Current); //(2.5)
	      if (str->Trim()!="") {
	        fzArr[cnt] = str; //(2.6)
			try { Convert::ToDouble(fzArr[cnt]); } //(2.7)
	        catch (FormatException^ e) { 
			  MessageBox::Show(e->Message, "Error!"); return -1; };
	        cnt++; }; }; //(2.8)
	    return cnt; //(2.9)
	  }; //End of szVA2fzA(...);
	};
} }

//(��)�G
//�M�׹w�](�u�sĶ�@��)
//�D�`���n�A���B�����ŧi�@�ϰ쪺�C�ޫ���szArr0_split�A
//���i�ϥζǤJ�Ѽ�(�C�ޫ���)���V�禡�ϰ줺���p�⵲�G�A
//�_�h��l�ǤJ���C�ޫ��СA�N�L�k���V�즳�ǤJ����}�C

//�̾کҫ��w���j�r���A�N�@�j�r��Φ��@�w��ת��r��}�C
//�N�w��צr��}�C�إ߯��ް}�C(�N�Ӹs�r��}�C�i��p�ƭӼ�)�C
//�N���ް}�C����U�������j���ഫ���r��C
//�Y�װŦr��e��ťդ����G���Ŧr��A�D�u�C

//GW86::Fx12Strings, one of my assemblies to process
//strings (i.e., split and trim non-numeric strings). 
//Gao-Wei Chang, 170208, 170126.
//161005, 160707, 140704, 140409.
//(��)
//static int myFzArr4szVA
//(String^ szInput, array<String^>^ myFzArr) { ... } 
//�`�N�Ʀr(number)���r��A�Ӽƭ�(value)�h�_�C
//�u���Ʀr�i��ƭȡA�Ӥ�r(�Ʀr)�h�_�C
//�榡�ഫ���ҥ~(�q��r�ܼƭ�)


