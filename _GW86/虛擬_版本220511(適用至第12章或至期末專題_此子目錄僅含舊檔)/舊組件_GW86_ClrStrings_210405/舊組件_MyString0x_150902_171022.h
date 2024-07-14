//GW86_Fm12Strings_MyString0x.h
//�ؼСG�ۭq�r��B�z���O(���ݩ�ۭq�R�W�Ŷ�)�P�䦨���禡�C
//�䤤�r��B�z�]�t�Ʀr�r�ꪺ����(split)�P���(trim)�C 
//Gao-Wei Chang, 150902(140716,140409a).
#pragma once //�M�׹w�](�u�sĶ�@��)
using namespace System;

namespace GW86 {
namespace Fm12Strings {
  using namespace System;
  using namespace System::Collections;
  using namespace System::Windows::Forms;//�����[�J�ѦҡC

  public ref class MyString0 {
	
    //�����禡1:�p�Ʀr��}�C�������ƥ�(�t��r�μƦr�r��)
	public: static int myArr_szCnt0 
		    (String^ str0, array<String^>^ myArr0) {
      array<String^>^ szArr0_split = str0->Split();
	  //���Τ@�j���r�ꬰ�@�r��}�C(�H�w�]���ťզr���������j�r��)�C
      IEnumerator^ enumArr0 = szArr0_split->GetEnumerator();
	  //�̾ڦr��}�C����(�N�X)�إ߭p�ƪ���(�N�X)�C
      int count = 0; String^ str;
      while (enumArr0->MoveNext()) {
	    str=safe_cast<String^>(enumArr0->Current);
	    if (str->Trim()!="") {
	      myArr0[count] = str; count++; };
      };
	  return count;
    }; //End of myArr_szCnt0(...);

    //�����禡2:���λP��צr��}�C�A�Ψ䤸���p��(�ȾA�Ω�Ʀr�r��)�C
    public: static int myArr_sz2num0
		    (String^ str0, array<String^>^ myArr0) {
	  array<Char>^ sepax1a = {' ', ',', ';', '\n', '\r',
			'\t', '(', ')', '[', ']' , '{', '}', '<', '>'};
      array<String^>^ szArr0_split = str0->Split(sepax1a);
	  //���Τ@�j���r�ꬰ�@�r��}�C(�ϥΤW�z�w�q�����j�r�������X)�C
      IEnumerator^ enumArr0 = szArr0_split->GetEnumerator();
      int count = 0; String^ str;
      while (enumArr0->MoveNext()) {
	    str=safe_cast<String^>(enumArr0->Current);
	    if (str->Trim()!="") {
	      myArr0[count] = str;
		  try {//�榡�ഫ���ҥ~(�Ҧp�N��r�ഫ���ƭ�)
		    Convert::ToDouble(myArr0[count]);
	      }//�`�N���B���i������(;)
	      catch (FormatException^ e) {//�����Өҥ~���B�z 
		    //Console::WriteLine(e->Message);
		    MessageBox::Show(e->Message, "Error!");
		    return -1; };
	      count++; };
       };
	   return count;
	  };//End of myArr_sz2num0(...);
	  //�`�N�Ʀr(number)���r��A�Ӽƭ�(value)�h�_�C
	  //�b�����禡2���A�W�[�F�ҥ~�ƥ�B�z�A�ӳB�z
	  //�u���Ʀr�i��ƭȡA�Ӥ�r(�D�Ʀr)�h�_���ҥ~�ƥ�C
  };//End of MyString0

};
};




