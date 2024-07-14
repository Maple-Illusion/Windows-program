#pragma once //盡箇砞(絪亩Ω)

using namespace System;

//GW86::Fm12Strings, one of my assemblies to process
//strings (i.e., split and trim non-numeric strings). 
//Gao-Wei Chang, 131221.
namespace GW86 {
  namespace Fm12Strings {
    using namespace System;
    using namespace System::Collections;
	using namespace System::Windows::Forms; //ゲ斗把σ

	public ref class MyString0 {
	 public:
	  static int myArr_sz2num0
		         (String^ str0, array<String^>^ myArr0) {
		//猔種计(number)﹃τ计(value)玥
		//Τ计锣计τゅ(獶计)玥
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
				 try { //Α锣传ぇㄒ(ㄒ盢ゅ锣传计)
		               Convert::ToDouble(myArr0[count]);
	             } //猔種矪ぃΤだ腹(;)
	             catch (FormatException^ e) { //癸莱赣ㄒぇ矪瞶 
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
