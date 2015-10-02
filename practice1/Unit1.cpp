//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CorepoEng2009"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
/**
 * フォームロード
 */
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	// メソッド内変数宣言
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
	//Form1->Close();
	this->Close();
}
//---------------------------------------------------------------------------
/**
 * プレビューボタン押下
 */
void __fastcall TForm1::btn_PreviewClick(TObject *Sender)
{
	// メソッド内変数宣言
	DWORD CrpErrCode;
	DWORD WinErrCode;
	int cwRepRet = 0;

	try
	{
		//**************************************************
		//【チェック】
		//**************************************************
		/*
		//
		// 名前
		//
		if (chk_Blank(txt_Name->Text))
		{
			// 未入力
			ShowMessage("名前が未入力です。");
			return;
		}
		//
		// 住所
		//
		if (chk_Blank(txt_Address->Text))
		{
			// 未入力
			ShowMessage("住所が未入力です。");
			return;
		}
		//
		// メモ
		//
		if (chk_Blank(txt_Memo->Text))
		{
			// 未入力
			ShowMessage("メモが未入力です。");
			return;
		}
		*/
        //**************************************************
		//【COREPOセッション終了】
		//**************************************************
		if (cwCloseEngine() == FALSE)
		{
			// セッション終了失敗
			//ShowMessage("COREPOセッション終了中に異常が発生しました。);
			//return;
		}

		//**************************************************
		//【COREPOセッション開始】
		//**************************************************
		if (cwOpenEngine() == FALSE)
		{
			// セッション開始失敗
			/*
			CrpErrCode = cwGetLastError(&WinErrCode);

			if (CrpErrCode == CRP_SYSTEM_ERROR)
			{
				// Windowsからエラーが通知された場合の処理を記述します
			}
			else
			{
				// レポート印刷エンジンのエラーが通知された場合の処理を記述します
			}
			ShowMessage("COREPOセッション開始中に異常が発生しました。" + "\r\n" + "エラーコード：" + CrpErrCode);
			*/
			ShowMessage("COREPOセッション開始中に異常が発生しました。");
			return;
		}

		//**************************************************
		//【レポートオープン】
		//**************************************************
		cwRepRet = cwOpenReport("C:/Project/Cpp/test/practice1/practice1.crp");

		if (cwRepRet == 0)
		{
			// レポートオープン失敗
			ShowMessage("レポートオープン中に異常が発生しました。");
			return;
		}

		//**************************************************
		//【プレビュー】
		//**************************************************
		//
		// 印刷ジョブ開始
		//
		if (!cwOpenPrintJobEx(
				cwRepRet,								//レポートハンドル
				"プレビューサンプル",					//印刷ジョブ名
				CW_PRTFLG_DIALOG + CW_PREVIEW_NORMAL,	//オプション設定
				true,									//印刷プレビューの表示
				"プレビューサンプル画面",				//印刷プレビュー画面のタイトル
				NULL,									//プレビューを表示するウインドウ
				1										//印刷部数
			)
		)
		{
			// 印刷ジョブ開始失敗
			ShowMessage("印刷ジョブの開始中に異常が発生しました。");
			//return;
		}
		//
		// 印刷データ設定
		//
		if (cwSetText(
				cwRepRet,
				"",
				"lbl_Name",
				txt_Name->Text.c_str()
			) < 0)
		{
		}
		if (cwSetText(
				cwRepRet,
				"",
				"lbl_Address",
				txt_Address->Text.c_str()
			) < 0)
		{
		}
		if (cwSetText(
				cwRepRet,
				"",
				"lbl_Memo",
				txt_Memo->Text.c_str()
			) < 0)
		{
		}
		//
		// 印刷
		//
		if (!cwPrintReport(cwRepRet, 0, -1))
		{
			// 印刷失敗
			ShowMessage("印刷中に異常が発生しました。");
			//return;
		}
		//
		// 印刷ジョブ終了
		//
		if (!cwClosePrintJob(cwRepRet , true))
		{
			// 印刷ジョブ終了失敗
			ShowMessage("印刷ジョブの終了中に異常が発生しました。");
			//return;
		}

		//**************************************************
		//【レポートクローズ】
		//**************************************************
		if (cwCloseReport(cwRepRet) == FALSE)
		{
			// レポートクローズ失敗
			//ShowMessage("レポートクローズ中に異常が発生しました。");
			//return;
		}

		//**************************************************
		//【COREPOセッション終了】
		//**************************************************
		if (cwCloseEngine() == FALSE)
		{
			// セッション終了失敗
			//ShowMessage("COREPOセッション終了中に異常が発生しました。);
			//return;
		}
	}
	catch (int e)
	{

	}
}
//---------------------------------------------------------------------------
/**
 * 【チェック処理】空白
 */
/*
bool __fastcall chk_Blank(UnicodeString *value)
{
	// メソッド内変数宣言
	bool ret = true;

	try
	{
		//**************************************************
		//【チェック処理】
		//  空白
		//**************************************************
		if (strlen(value) == 0)
		{
			// 空白
			ret = false;
		}
		if (value == '\0')
		{
			// NULL
			ret = false;
		}
	}
	catch (int e)
	{
		ret = false;
	}
	return ret;
}
*/
