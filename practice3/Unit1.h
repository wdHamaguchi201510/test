//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CorepoEng2009.hpp"
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE 管理のコンポーネント
	TLabel *lbl_Title;
	TLabel *lbl_Name;
	TEdit *txt_Name;
	TLabel *lbl_Address;
	TEdit *txt_Address;
	TLabel *lbl_Memo;
	TButton *btn_End;
	TButton *btn_Preview;
	TMemo *txt_Memo;
	TCrpReport *crp_practice3;
	TLabel *lbl_InputPath_Label;
	TEdit *txt_InputPath;
	TButton *btn_InputPath_Dir;
	TOpenDialog *dlg_InputPath;
	TShape *Shape1;
	TRadioButton *rdo_Manual;
	TRadioButton *rdo_FileInput;
	TShape *Shape2;
	TLabel *Label1;
	TXMLDocument *xmlDoc;
	void __fastcall btn_EndClick(TObject *Sender);
	void __fastcall btn_PreviewClick(TObject *Sender);
	void __fastcall btn_InputPath_DirClick(TObject *Sender);
	void __fastcall rdo_ManualClick(TObject *Sender);
	void __fastcall rdo_FileInputClick(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall Ctrl_Enabled();
	UnicodeString __fastcall Search_Xml_TextNode(_di_IXMLNode parentNode, UnicodeString search);
	void __fastcall Preview();
	void __fastcall Preview_Manual(TCrpReport *rpt);
	void __fastcall Preview_FileInput(TCrpReport *rpt);
	//bool __fastcall chk_Blank(TStrings *value);
	//bool __fastcall chk_Blank(UnicodeString *value);
public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
