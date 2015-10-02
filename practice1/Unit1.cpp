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
	//Form1->Close();
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
		//�yCOREPO�Z�b�V�����I���z
		//**************************************************
		if (cwCloseEngine() == FALSE)
		{
			// �Z�b�V�����I�����s
			//ShowMessage("COREPO�Z�b�V�����I�����Ɉُ킪�������܂����B);
			//return;
		}

		//**************************************************
		//�yCOREPO�Z�b�V�����J�n�z
		//**************************************************
		if (cwOpenEngine() == FALSE)
		{
			// �Z�b�V�����J�n���s
			/*
			CrpErrCode = cwGetLastError(&WinErrCode);

			if (CrpErrCode == CRP_SYSTEM_ERROR)
			{
				// Windows����G���[���ʒm���ꂽ�ꍇ�̏������L�q���܂�
			}
			else
			{
				// ���|�[�g����G���W���̃G���[���ʒm���ꂽ�ꍇ�̏������L�q���܂�
			}
			ShowMessage("COREPO�Z�b�V�����J�n���Ɉُ킪�������܂����B" + "\r\n" + "�G���[�R�[�h�F" + CrpErrCode);
			*/
			ShowMessage("COREPO�Z�b�V�����J�n���Ɉُ킪�������܂����B");
			return;
		}

		//**************************************************
		//�y���|�[�g�I�[�v���z
		//**************************************************
		cwRepRet = cwOpenReport("C:/Project/Cpp/test/practice1/practice1.crp");

		if (cwRepRet == 0)
		{
			// ���|�[�g�I�[�v�����s
			ShowMessage("���|�[�g�I�[�v�����Ɉُ킪�������܂����B");
			return;
		}

		//**************************************************
		//�y�v���r���[�z
		//**************************************************
		//
		// ����W���u�J�n
		//
		if (!cwOpenPrintJobEx(
				cwRepRet,								//���|�[�g�n���h��
				"�v���r���[�T���v��",					//����W���u��
				CW_PRTFLG_DIALOG + CW_PREVIEW_NORMAL,	//�I�v�V�����ݒ�
				true,									//����v���r���[�̕\��
				"�v���r���[�T���v�����",				//����v���r���[��ʂ̃^�C�g��
				NULL,									//�v���r���[��\������E�C���h�E
				1										//�������
			)
		)
		{
			// ����W���u�J�n���s
			ShowMessage("����W���u�̊J�n���Ɉُ킪�������܂����B");
			//return;
		}
		//
		// ����f�[�^�ݒ�
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
		// ���
		//
		if (!cwPrintReport(cwRepRet, 0, -1))
		{
			// ������s
			ShowMessage("������Ɉُ킪�������܂����B");
			//return;
		}
		//
		// ����W���u�I��
		//
		if (!cwClosePrintJob(cwRepRet , true))
		{
			// ����W���u�I�����s
			ShowMessage("����W���u�̏I�����Ɉُ킪�������܂����B");
			//return;
		}

		//**************************************************
		//�y���|�[�g�N���[�Y�z
		//**************************************************
		if (cwCloseReport(cwRepRet) == FALSE)
		{
			// ���|�[�g�N���[�Y���s
			//ShowMessage("���|�[�g�N���[�Y���Ɉُ킪�������܂����B");
			//return;
		}

		//**************************************************
		//�yCOREPO�Z�b�V�����I���z
		//**************************************************
		if (cwCloseEngine() == FALSE)
		{
			// �Z�b�V�����I�����s
			//ShowMessage("COREPO�Z�b�V�����I�����Ɉُ킪�������܂����B);
			//return;
		}
	}
	catch (int e)
	{

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
