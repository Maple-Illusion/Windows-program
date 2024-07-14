#pragma once //�M�׹w�](�u�sĶ�@��)

using namespace System;

//GW86::Fm12Strings, one of my assemblies to process
//strings (i.e., split and trim non-numeric strings). 
//Gao-Wei Chang, 131221.
namespace GW86 {
  namespace Fm12Strings {
    using namespace System;
    using namespace System::Collections;
	using namespace System::Windows::Forms; //�����[�J�ѦҡC

	public ref class MyString0 {
	 public:
	  static int myArr_sz2num0
		         (String^ str0, array<String^>^ myArr0) {
		//�`�N�Ʀr(number)���r��A�Ӽƭ�(value)�h�_�C
		//�u���Ʀr�i��ƭȡA�Ӥ�r(�D�Ʀr)�h�_�C
	    array<Char>^ sepax1a = {' ', ',', ';', '\n', '\r',
			    '\t', '(', ')', '[', ']' , '{', '}', '<', '>'};
        array<String^>^ szArr0_split = str0->Split(sepax1a);

        IEnumerator^ enumArr0 = szArr0_split->GetEnumerator();
        int count = 0;
        String^ str;
        while (enumArr0->MoveNext()) {
	          str=safe_cast<String^>(enumArr0->Current);
	          if (str->Trim()!="") {
	             myArr0[count] = str;
				 try { //�榡�ഫ���ҥ~(�Ҧp�N��r�ഫ���ƭ�)
		               Convert::ToDouble(myArr0[count]);
	             } //�`�N���B���i������(;)
	             catch (FormatException^ e) { //�����Өҥ~���B�z 
		               //Console::WriteLine(e->Message);
					   MessageBox::Show(e->Message, "Error!");
				       return -1;
	             };
	             count++;
              };
        };
	    return count;
	  }; //End of myArr_sz2num0(...);

	};
  };
};
