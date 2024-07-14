//GW86_Fm12Strings_MyString0x.h
//目標：自訂字串處理類別(隸屬於自訂命名空間)與其成員函式。
//其中字串處理包含數字字串的分割(split)與整修(trim)。 
//Gao-Wei Chang, 150902(140716,140409a).
#pragma once //專案預設(只編譯一次)
using namespace System;

namespace GW86 {
namespace Fm12Strings {
  using namespace System;
  using namespace System::Collections;
  using namespace System::Windows::Forms;//必須加入參考。

  public ref class MyString0 {
	
    //成員函式1:計數字串陣列之元素數目(含文字或數字字串)
	public: static int myArr_szCnt0 
		    (String^ str0, array<String^>^ myArr0) {
      array<String^>^ szArr0_split = str0->Split();
	  //分割一大筆字串為一字串陣列(以預設的空白字元做為分隔字元)。
      IEnumerator^ enumArr0 = szArr0_split->GetEnumerator();
	  //依據字串陣列物件(代碼)建立計數表物件(代碼)。
      int count = 0; String^ str;
      while (enumArr0->MoveNext()) {
	    str=safe_cast<String^>(enumArr0->Current);
	    if (str->Trim()!="") {
	      myArr0[count] = str; count++; };
      };
	  return count;
    }; //End of myArr_szCnt0(...);

    //成員函式2:分割與整修字串陣列，及其元素計數(僅適用於數字字串)。
    public: static int myArr_sz2num0
		    (String^ str0, array<String^>^ myArr0) {
	  array<Char>^ sepax1a = {' ', ',', ';', '\n', '\r',
			'\t', '(', ')', '[', ']' , '{', '}', '<', '>'};
      array<String^>^ szArr0_split = str0->Split(sepax1a);
	  //分割一大筆字串為一字串陣列(使用上述定義的分隔字元之集合)。
      IEnumerator^ enumArr0 = szArr0_split->GetEnumerator();
      int count = 0; String^ str;
      while (enumArr0->MoveNext()) {
	    str=safe_cast<String^>(enumArr0->Current);
	    if (str->Trim()!="") {
	      myArr0[count] = str;
		  try {//格式轉換之例外(例如將文字轉換為數值)
		    Convert::ToDouble(myArr0[count]);
	      }//注意此處不可有分號(;)
	      catch (FormatException^ e) {//對應該例外之處理 
		    //Console::WriteLine(e->Message);
		    MessageBox::Show(e->Message, "Error!");
		    return -1; };
	      count++; };
       };
	   return count;
	  };//End of myArr_sz2num0(...);
	  //注意數字(number)為字串，而數值(value)則否。
	  //在成員函式2中，增加了例外事件處理，來處理
	  //只有數字可轉數值，而文字(非數字)則否之例外事件。
  };//End of MyString0

};
};




