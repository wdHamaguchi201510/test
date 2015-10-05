//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//#include <IOUtils.hpp>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CorepoEng2009"
#pragma resource "*.dfm"
TForm1 *Form1;

//**************************************************
//【イベント処理】
//**************************************************
//---------------------------------------------------------------------------
/**
 * フォームロード
 */
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	// メソッド内変数宣言

	//**************************************************
	//【活性制御】
	//**************************************************
	Ctrl_Enabled();
}
//---------------------------------------------------------------------------
/**
 * 手入力ラジオボタン押下
 */
void __fastcall TForm1::rdo_ManualClick(TObject *Sender)
{
	// メソッド内変数宣言

	//**************************************************
	//【活性制御】
	//**************************************************
	Ctrl_Enabled();
}
//---------------------------------------------------------------------------
/**
 * ファイル入力ラジオボタン押下
 */
void __fastcall TForm1::rdo_FileInputClick(TObject *Sender)
{
	// メソッド内変数宣言

	//**************************************************
	//【活性制御】
	//**************************************************
	Ctrl_Enabled();
}
//---------------------------------------------------------------------------
/**
 * 終了ボタン押下
 */
void __fastcall TForm1::btn_EndClick(TObject *Sender)
{
	// メソッド内変数宣言

	//**************************************************
	//【終了】
	//**************************************************
	this->Close();
}
//---------------------------------------------------------------------------
/**
 * [入力元] ...ボタン押下
 */
void __fastcall TForm1::btn_InputPath_DirClick(TObject *Sender)
{
	// メソッド内変数宣言

    try
	{
		//**************************************************
		//【ファイル選択ダイアログ】
		//**************************************************
		if (dlg_InputPath->Execute())
		{
			// 設定
			txt_InputPath->Text =dlg_InputPath->FileName;
		}
	}
	catch (int e)
	{
		ShowMessage("入力元の設定中に例外が発生しました。");
	}
}
//---------------------------------------------------------------------------
/**
 * プレビューボタン押下
 */
void __fastcall TForm1::btn_PreviewClick(TObject *Sender)
{
	// メソッド内変数宣言

	try
	{
		//**************************************************
		//【チェック】
		//  共通
		//**************************************************
		//
		// モード
		//
		if (!rdo_Manual->Checked && !rdo_FileInput->Checked)
		{
			// 未選択
			ShowMessage("[手入力]または[ファイル入力]を選択してください。");
			return;
		}

        //**************************************************
		//【チェック】
		//  手入力エリア
		//**************************************************
		if (rdo_Manual->Checked)
		{
			// 氏名
			if (txt_Name->Text.IsEmpty())
			{
				// 未入力
				ShowMessage("[名前]が設定されていません。");
				return;
			}

			// 住所
			if (txt_Address->Text.IsEmpty())
			{
				// 未入力
				ShowMessage("[住所]が設定されていません。");
				return;
			}
		}

		//**************************************************
		//【チェック】
		//  ファイル入力エリア
		//**************************************************
		if (rdo_FileInput->Checked)
		{
			// 入力元
			if (txt_InputPath->Text.IsEmpty())
			{
				// 未入力
				ShowMessage("[入力元]が設定されていません。");
				return;
			}
			if (!FileExists(txt_InputPath->Text))
			{
				// 存在しない
				ShowMessage("[入力元]に指定したファイルが存在しません。");
				return;
			}

			UnicodeString extension = ExtractFileExt(txt_InputPath->Text).LowerCase();

			if (extension != ".csv" && extension != ".xml")
			{
				// 拡張子対象外
				ShowMessage("[入力元]に指定するファイルは、\r\n『CSV』または『XML』のみ有効です。");
				return;
			}
		}

		//**************************************************
		//【プレビュー】
		//**************************************************
        Preview();
	}
	catch (int e)
	{
		ShowMessage("プレビュー処理中に例外が発生しました。");
	}
}
//---------------------------------------------------------------------------

//**************************************************
//【ユーザー定義関数】
//**************************************************
/**
 * 活性制御
 */
void __fastcall TForm1::Ctrl_Enabled()
{
	// メソッド内変数宣言

    //**************************************************
	//【活性制御】
	//**************************************************
	//
	// 名前
	//
	txt_Name->Enabled = rdo_Manual->Checked;
	//
	// 住所
	//
	txt_Address->Enabled = rdo_Manual->Checked;
	//
	// メモ
	//
	txt_Memo->Enabled = rdo_Manual->Checked;
	//
	// 入力元
	//
	txt_InputPath->Enabled = rdo_FileInput->Checked;
	//
	// [入力元] ...ボタン
	//
	btn_InputPath_Dir->Enabled = rdo_FileInput->Checked;
}
//---------------------------------------------------------------------------
/**
 * XMLタグ検索：テキストノード
 */
UnicodeString __fastcall TForm1::Search_Xml_TextNode(_di_IXMLNode parentNode, UnicodeString search)
{
	// メソッド内変数宣言
    UnicodeString ret = "";

    //**************************************************
	//【ノード検索】
	//**************************************************
	for (int i = 0; i < parentNode->GetChildNodes()->Count; i++)
	{
		// 子ノード取得
		_di_IXMLNode node = parentNode->GetChildNodes()->Nodes[i];

		if (node->NodeName == search)
		{
			// 戻り値設定
			ret = node->NodeValue;
			break;
		}

		// XMLタグ検索：テキストノード
        ret = Search_Xml_TextNode(node, search);
	}

	return ret;
}
//---------------------------------------------------------------------------
/**
 * プレビュー処理
 */
void __fastcall TForm1::Preview()
{
	// メソッド内変数宣言
	DWORD CrpErrCode;
	DWORD WinErrCode;
	TcwPrintFlags prtOpt;

	try
	{
		//**************************************************
		//【レポート設定】
		//**************************************************
		crp_practice3->ReportPath = "C:/Project/Cpp/test/practice3/practice3.crp";
		prtOpt << cpfDIALOG << cpfSTRETCH <<cpfPREVIEW_MAXIMIZED;

        //**************************************************
		//【印刷ジョブ開始】
		//**************************************************
		if (crp_practice3->OpenPrintJob(
				"",     //印刷ジョブ名
				prtOpt,	//オプション設定
				true,	//印刷プレビューの表示
				"",     //印刷プレビュー画面のタイトル
				NULL    //プレビューを表示するウインドウ
			)  == false)
		{
			// 印刷ジョブ開始失敗
			crp_practice3->ReportPath = "";
			ShowMessage("印刷ジョブの開始中に異常が発生しました。");
			//return;
		}

        //**************************************************
		//【印刷データ設定】
		//**************************************************
		if (rdo_Manual->Checked)
		{
			// 手入力
			Preview_Manual(crp_practice3);
		}
		else if (rdo_FileInput->Checked)
		{
			// ファイル入力
			Preview_FileInput(crp_practice3);
		}

        //**************************************************
		//【印刷（プレビュー）】
		//**************************************************
		crp_practice3->PrintReport();

        //**************************************************
		//【印刷ジョブ終了】
		//**************************************************
		crp_practice3->ClosePrintJob(true);

		//**************************************************
		//【レポートクローズ】
		//**************************************************
		crp_practice3->ReportPath = "";
    }
	catch (int e)
	{
		throw e;
	}
}
//---------------------------------------------------------------------------
/**
 * プレビュー処理：手入力
 */
void __fastcall TForm1::Preview_Manual(TCrpReport *rpt)
{
	// メソッド内変数宣言

	try
	{
        //**************************************************
		//【印刷データ設定】
		//**************************************************
		//
		// 名前
		//
		rpt->Item("","lbl_Name")->Text = txt_Name->Text;
		//
		// 住所
		//
		rpt->Item("","lbl_Address")->Text = txt_Address->Text;
		//
		// メモ
		//
		rpt->Item("","lbl_Memo")->Text = txt_Memo->Text;
    }
	catch (int e)
	{
		throw e;
	}
}
//---------------------------------------------------------------------------
/**
 * プレビュー処理：ファイル入力
 */
void __fastcall TForm1::Preview_FileInput(TCrpReport *rpt)
{
	// メソッド内変数宣言
	UnicodeString extension = ExtractFileExt(txt_InputPath->Text).LowerCase();
	UnicodeString name = "";
	UnicodeString address = "";
	UnicodeString memo = "";

	try
	{
        //**************************************************
		//【ファイル読み込み】
		//**************************************************
		//
		// CSV
		//
		if (extension == ".csv")
		{
			TStringList *csvData = new TStringList();

			// ファイル読み込み
			csvData->LoadFromFile(txt_InputPath->Text);

			for (int i = 0; i < csvData->Count; i++)
			{
				UnicodeString readLine = csvData->Strings[i];
				TStringList *comma = new TStringList();

				// 空白行
				if (readLine.IsEmpty())
				{
                    continue;
				}

				// コメントアウト
				if (readLine.SubString(0,1) == "#")
				{
                    continue;
				}

				// カンマ区切り分解
				comma->CommaText = readLine;

				// ファイル内容取得
				name = comma->Strings[0];
				address = comma->Strings[1];
				memo = comma->Strings[2];

				// オブジェクト破棄
				delete comma;
			}

			// オブジェクト破棄
			delete csvData;
		}
		//
		// XML
		//
		else if (extension == ".xml")
		{
			// 読み込み設定
			xmlDoc->DOMVendor = GetDOMVendor("MSXML");
			xmlDoc->Active = true;
			xmlDoc->Encoding = "UTF-8";

			// ファイル読み込み
			xmlDoc->LoadFromFile(txt_InputPath->Text);

			// ファイル内容取得
			name = Search_Xml_TextNode(xmlDoc->Node,"name");
			address = Search_Xml_TextNode(xmlDoc->Node,"address");
			memo = Search_Xml_TextNode(xmlDoc->Node,"memo");

			// オブジェクト破棄
			xmlDoc->Active = false;
			delete xmlDoc;
		}

		//**************************************************
		//【印刷データ設定】
		//**************************************************
		//
		// 名前
		//
		rpt->Item("","lbl_Name")->Text = name;
		//
		// 住所
		//
		rpt->Item("","lbl_Address")->Text = address;
		//
		// メモ
		//
		rpt->Item("","lbl_Memo")->Text = memo;
    }
	catch (int e)
	{
		throw e;
	}
}
//---------------------------------------------------------------------------

