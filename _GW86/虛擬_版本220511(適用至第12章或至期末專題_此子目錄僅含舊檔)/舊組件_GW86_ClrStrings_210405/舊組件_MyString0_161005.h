#pragma once //盡箇砞(絪亩Ω)

//GW86::Fx12Strings, one of my assemblies to process
//strings (i.e., split and trim non-numeric strings). 
//Gao-Wei Chang, 161005, 160707, 140704, 140409.
namespace GW86 {
namespace Fx12Strings {
  using namespace System;
  using namespace System::Collections;
	using namespace System::Windows::Forms; //ゲ斗把σ

	public ref class MyString0 {
	private:
	  static array<Char>^ sepax1a = {' ', ',',  '\n', '\r',
			'\t', '(', ')', '[', ']' , '{', '}', '<', '>'}; //ぃ㏑挡Юじ';'
	public:
	  static int myArr_sz4cmd //璸计﹃皚ぇゅ/计﹃计ヘ
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
			   try { //Α锣传ぇㄒ(眖ゅ计)
		           Convert::ToDouble(myArr0[count]); }
	            catch (FormatException^ e) { 
				   MessageBox::Show(e->Message, "Error!");
				   return -1; };
	            count++; }; 
        }; //End of while loop.
	    return count;
	  }; //End of myArr_sz4num0(...);
	};
	//猔種计(number)﹃τ计(value)玥
	//Τ计锣计τゅ(獶计)玥
  };
}


