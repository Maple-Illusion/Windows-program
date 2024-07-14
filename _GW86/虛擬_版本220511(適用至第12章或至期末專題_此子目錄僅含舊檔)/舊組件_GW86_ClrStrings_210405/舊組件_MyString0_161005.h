#pragma once //�M�׹w�](�u�sĶ�@��)

//GW86::Fx12Strings, one of my assemblies to process
//strings (i.e., split and trim non-numeric strings). 
//Gao-Wei Chang, 161005, 160707, 140704, 140409.
namespace GW86 {
namespace Fx12Strings {
  using namespace System;
  using namespace System::Collections;
	using namespace System::Windows::Forms; //�����[�J�ѦҡC

	public ref class MyString0 {
	private:
	  static array<Char>^ sepax1a = {' ', ',',  '\n', '\r',
			'\t', '(', ')', '[', ']' , '{', '}', '<', '>'}; //���i�]�t�R�O�����r��';'
	public:
	  static int myArr_sz4cmd //�p�Ʀr��}�C����r/�Ʀr�r��ƥ�
		         (String^ str0, array<String^>^ myArr0) {
        array<String^>^ szArr0_split = str0->Split(sepax1a);
        IEnumerator^ enumArr0 = szArr0_split->GetEnumerator();
        int count = 0; String^ str;
        while (enumArr0->MoveNext()) {
	          str=safe_cast<String^>(enumArr0->Current);
	          if (str->Trim()!="") {
	             myArr0[count] = str;
	             count++; };
        }; //End of while loop.
	    return count;
	  }; //End of myArr_szCnt0(...);

	 public:
	  static int myArr_sz4num
		         (String^ str0, array<String^>^ myArr0) {
        array<String^>^ szArr0_split = str0->Split(sepax1a);
        IEnumerator^ enumArr0 = szArr0_split->GetEnumerator();
        int count = 0; String^ str;
        while (enumArr0->MoveNext()) {
	         str=safe_cast<String^>(enumArr0->Current);
	         if (str->Trim()!="") {
	           myArr0[count] = str;
			   try { //�榡�ഫ���ҥ~(�q��r�ܼƭ�)
		           Convert::ToDouble(myArr0[count]); }
	            catch (FormatException^ e) { 
				   MessageBox::Show(e->Message, "Error!");
				   return -1; };
	            count++; }; 
        }; //End of while loop.
	    return count;
	  }; //End of myArr_sz4num0(...);
	};
	//�`�N�Ʀr(number)���r��A�Ӽƭ�(value)�h�_�C
	//�u���Ʀr�i��ƭȡA�Ӥ�r(�D�Ʀr)�h�_�C
  };
}


