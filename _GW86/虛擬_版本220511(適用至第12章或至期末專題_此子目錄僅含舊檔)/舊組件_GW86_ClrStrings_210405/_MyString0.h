//GW86_ClrStrings_MyString0.h
//類似System::Windows::Forms::Form之命名
//Gao-Wei Chang, 180428, 171023, 140409.
#pragma once
namespace GW86 {
namespace ClrStrings {
using namespace System;
using namespace System::Collections; //必要。
using namespace System::Windows::Forms; //必要。

public ref class MyString0 {
  private: static array<Char>^ cmSepa = {' ', ',', '\r', '\n', //(0.1a)
			    '\t', '(', ')', '[', ']' , '{', '}', '<', '>'};
  //不可包含命令結尾字元';'，以便判斷命令字串與數值欄位字串
  //簡單地說，保留字元';'用以識別命令或數值陣列。(非常重要)
  private: static array<Char>^ vaSepa = {' ', ',', ';', '\r', '\n', //(0.1b)
			    '\t', '(', ')', '[', ']' , '{', '}', '<', '>'}; //較cmSepa多列一個字元';'
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
	  //從分割多個欄位字串到建立欄位字串陣列，並計算其元素數目

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

//(註)：
//專案預設(只編譯一次)
//非常重要，此處必須宣告一區域的列管指標szArr0_split，
//不可使用傳入參數(列管指標)指向函式區域內之計算結果，
//否則原始傳入的列管指標，將無法指向原有傳入之位址。

//依據所指定分隔字元，將一大字串形成一已整修的字串陣列
//將已整修字串陣列建立索引陣列(將該群字串陣列進行計數個數)。
//將索引陣列中當下的元素強制轉換為字串。
//若修剪字串前後空白之結果為空字串，非真。

//GW86::Fx12Strings, one of my assemblies to process
//strings (i.e., split and trim non-numeric strings). 
//Gao-Wei Chang, 170208, 170126.
//161005, 160707, 140704, 140409.
//(註)
//static int myFzArr4szVA
//(String^ szInput, array<String^>^ myFzArr) { ... } 
//注意數字(number)為字串，而數值(value)則否。
//只有數字可轉數值，而文字(數字)則否。
//格式轉換之例外(從文字至數值)


