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
 * �t�H�[�����[�h
 */
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	// ���\�b�h���ϐ��錾
}
//---------------------------------------------------------------------------
/**
 * �I���{�^������
 */
void __fastcall TForm1::btn_EndClick(TObject *Sender)
{
	// ���\�b�h���ϐ��錾

	//**************************************************
	//�y�I���z
	//**************************************************
	this->Close();
}
//---------------------------------------------------------------------------
/**
 * �v���r���[�{�^������
 */
void __fastcall TForm1::btn_PreviewClick(TObject *Sender)
{
	// ���\�b�h���ϐ��錾
	DWORD CrpErrCode;
	DWORD WinErrCode;
	int cwRepRet = 0;
	TcwPrintFlags prtOpt;

	try
	{
		//**************************************************
		//�y�`�F�b�N�z
		//**************************************************
		/*
		//
		// ���O
		//
		if (chk_Blank(txt_Name->Text))
		{
			// ������
			ShowMessage("���O�������͂ł��B");
			return;
		}
		//
		// �Z��
		//
		if (chk_Blank(txt_Address->Text))
		{
			// ������
			ShowMessage("�Z���������͂ł��B");
			return;
		}
		//
		// ����
		//
		if (chk_Blank(txt_Memo->Text))
		{
			// ������
			ShowMessage("�����������͂ł��B");
			return;
		}
		*/

		//**************************************************
		//�y�v���r���[�z
		//**************************************************
		//
		// ���|�[�g�ݒ�
		//
		crp_Practice2->ReportPath = "C:/Project/Cpp/test/practice2/practice2.crp";
		prtOpt << cpfDIALOG << cpfSTRETCH <<cpfPREVIEW_MAXIMIZED;
		//
		// ����W���u�J�n
		//
		if (crp_Practice2->OpenPrintJob(
				"",     //����W���u��
				prtOpt,	//�I�v�V�����ݒ�
				true,	//����v���r���[�̕\��
				"",     //����v���r���[��ʂ̃^�C�g��
				NULL    //�v���r���[��\������E�C���h�E
			)  == false)
		{
			// ����W���u�J�n���s
			crp_Practice2->ReportPath = "";
			ShowMessage("����W���u�̊J�n���Ɉُ킪�������܂����B");
			//return;
		}
		//
		// ����f�[�^�ݒ�
		//
		crp_Practice2->Item("","lbl_Name")->Text = txt_Name->Text;
		crp_Practice2->Item("","lbl_Address")->Text = txt_Address->Text;
		crp_Practice2->Item("","lbl_Memo")->Text = txt_Memo->Text;
		//
		// ���
		//
		crp_Practice2->PrintReport();
		//
		// ����W���u�I��
		//
		crp_Practice2->ClosePrintJob(true);

		//**************************************************
		//�y���|�[�g�N���[�Y�z
		//**************************************************
		crp_Practice2->ReportPath = "";
	}
	catch (int e)
	{
		ShowMessage("��O���������܂����B");
	}
}
//---------------------------------------------------------------------------
/**
 * �y�`�F�b�N�����z��
 */
/*
bool __fastcall chk_Blank(UnicodeString *value)
{
	// ���\�b�h���ϐ��錾
	bool ret = true;

	try
	{
		//**************************************************
		//�y�`�F�b�N�����z
		//  ��
		//**************************************************
		if (strlen(value) == 0)
		{
			// ��
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

