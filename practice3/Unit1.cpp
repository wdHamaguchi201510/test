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
//�y�C�x���g�����z
//**************************************************
//---------------------------------------------------------------------------
/**
 * �t�H�[�����[�h
 */
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	// ���\�b�h���ϐ��錾

	//**************************************************
	//�y��������z
	//**************************************************
	Ctrl_Enabled();
}
//---------------------------------------------------------------------------
/**
 * ����̓��W�I�{�^������
 */
void __fastcall TForm1::rdo_ManualClick(TObject *Sender)
{
	// ���\�b�h���ϐ��錾

	//**************************************************
	//�y��������z
	//**************************************************
	Ctrl_Enabled();
}
//---------------------------------------------------------------------------
/**
 * �t�@�C�����̓��W�I�{�^������
 */
void __fastcall TForm1::rdo_FileInputClick(TObject *Sender)
{
	// ���\�b�h���ϐ��錾

	//**************************************************
	//�y��������z
	//**************************************************
	Ctrl_Enabled();
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
 * [���͌�] ...�{�^������
 */
void __fastcall TForm1::btn_InputPath_DirClick(TObject *Sender)
{
	// ���\�b�h���ϐ��錾

    try
	{
		//**************************************************
		//�y�t�@�C���I���_�C�A���O�z
		//**************************************************
		if (dlg_InputPath->Execute())
		{
			// �ݒ�
			txt_InputPath->Text =dlg_InputPath->FileName;
		}
	}
	catch (int e)
	{
		ShowMessage("���͌��̐ݒ蒆�ɗ�O���������܂����B");
	}
}
//---------------------------------------------------------------------------
/**
 * �v���r���[�{�^������
 */
void __fastcall TForm1::btn_PreviewClick(TObject *Sender)
{
	// ���\�b�h���ϐ��錾

	try
	{
		//**************************************************
		//�y�`�F�b�N�z
		//  ����
		//**************************************************
		//
		// ���[�h
		//
		if (!rdo_Manual->Checked && !rdo_FileInput->Checked)
		{
			// ���I��
			ShowMessage("[�����]�܂���[�t�@�C������]��I�����Ă��������B");
			return;
		}

        //**************************************************
		//�y�`�F�b�N�z
		//  ����̓G���A
		//**************************************************
		if (rdo_Manual->Checked)
		{
			// ����
			if (txt_Name->Text.IsEmpty())
			{
				// ������
				ShowMessage("[���O]���ݒ肳��Ă��܂���B");
				return;
			}

			// �Z��
			if (txt_Address->Text.IsEmpty())
			{
				// ������
				ShowMessage("[�Z��]���ݒ肳��Ă��܂���B");
				return;
			}
		}

		//**************************************************
		//�y�`�F�b�N�z
		//  �t�@�C�����̓G���A
		//**************************************************
		if (rdo_FileInput->Checked)
		{
			// ���͌�
			if (txt_InputPath->Text.IsEmpty())
			{
				// ������
				ShowMessage("[���͌�]���ݒ肳��Ă��܂���B");
				return;
			}
			if (!FileExists(txt_InputPath->Text))
			{
				// ���݂��Ȃ�
				ShowMessage("[���͌�]�Ɏw�肵���t�@�C�������݂��܂���B");
				return;
			}

			UnicodeString extension = ExtractFileExt(txt_InputPath->Text).LowerCase();

			if (extension != ".csv" && extension != ".xml")
			{
				// �g���q�ΏۊO
				ShowMessage("[���͌�]�Ɏw�肷��t�@�C���́A\r\n�wCSV�x�܂��́wXML�x�̂ݗL���ł��B");
				return;
			}
		}

		//**************************************************
		//�y�v���r���[�z
		//**************************************************
        Preview();
	}
	catch (int e)
	{
		ShowMessage("�v���r���[�������ɗ�O���������܂����B");
	}
}
//---------------------------------------------------------------------------

//**************************************************
//�y���[�U�[��`�֐��z
//**************************************************
/**
 * ��������
 */
void __fastcall TForm1::Ctrl_Enabled()
{
	// ���\�b�h���ϐ��錾

    //**************************************************
	//�y��������z
	//**************************************************
	//
	// ���O
	//
	txt_Name->Enabled = rdo_Manual->Checked;
	//
	// �Z��
	//
	txt_Address->Enabled = rdo_Manual->Checked;
	//
	// ����
	//
	txt_Memo->Enabled = rdo_Manual->Checked;
	//
	// ���͌�
	//
	txt_InputPath->Enabled = rdo_FileInput->Checked;
	//
	// [���͌�] ...�{�^��
	//
	btn_InputPath_Dir->Enabled = rdo_FileInput->Checked;
}
//---------------------------------------------------------------------------
/**
 * XML�^�O�����F�e�L�X�g�m�[�h
 */
UnicodeString __fastcall TForm1::Search_Xml_TextNode(_di_IXMLNode parentNode, UnicodeString search)
{
	// ���\�b�h���ϐ��錾
    UnicodeString ret = "";

    //**************************************************
	//�y�m�[�h�����z
	//**************************************************
	for (int i = 0; i < parentNode->GetChildNodes()->Count; i++)
	{
		// �q�m�[�h�擾
		_di_IXMLNode node = parentNode->GetChildNodes()->Nodes[i];

		if (node->NodeName == search)
		{
			// �߂�l�ݒ�
			ret = node->NodeValue;
			break;
		}

		// XML�^�O�����F�e�L�X�g�m�[�h
        ret = Search_Xml_TextNode(node, search);
	}

	return ret;
}
//---------------------------------------------------------------------------
/**
 * �v���r���[����
 */
void __fastcall TForm1::Preview()
{
	// ���\�b�h���ϐ��錾
	DWORD CrpErrCode;
	DWORD WinErrCode;
	TcwPrintFlags prtOpt;

	try
	{
		//**************************************************
		//�y���|�[�g�ݒ�z
		//**************************************************
		crp_practice3->ReportPath = "C:/Project/Cpp/test/practice3/practice3.crp";
		prtOpt << cpfDIALOG << cpfSTRETCH <<cpfPREVIEW_MAXIMIZED;

        //**************************************************
		//�y����W���u�J�n�z
		//**************************************************
		if (crp_practice3->OpenPrintJob(
				"",     //����W���u��
				prtOpt,	//�I�v�V�����ݒ�
				true,	//����v���r���[�̕\��
				"",     //����v���r���[��ʂ̃^�C�g��
				NULL    //�v���r���[��\������E�C���h�E
			)  == false)
		{
			// ����W���u�J�n���s
			crp_practice3->ReportPath = "";
			ShowMessage("����W���u�̊J�n���Ɉُ킪�������܂����B");
			//return;
		}

        //**************************************************
		//�y����f�[�^�ݒ�z
		//**************************************************
		if (rdo_Manual->Checked)
		{
			// �����
			Preview_Manual(crp_practice3);
		}
		else if (rdo_FileInput->Checked)
		{
			// �t�@�C������
			Preview_FileInput(crp_practice3);
		}

        //**************************************************
		//�y����i�v���r���[�j�z
		//**************************************************
		crp_practice3->PrintReport();

        //**************************************************
		//�y����W���u�I���z
		//**************************************************
		crp_practice3->ClosePrintJob(true);

		//**************************************************
		//�y���|�[�g�N���[�Y�z
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
 * �v���r���[�����F�����
 */
void __fastcall TForm1::Preview_Manual(TCrpReport *rpt)
{
	// ���\�b�h���ϐ��錾

	try
	{
        //**************************************************
		//�y����f�[�^�ݒ�z
		//**************************************************
		//
		// ���O
		//
		rpt->Item("","lbl_Name")->Text = txt_Name->Text;
		//
		// �Z��
		//
		rpt->Item("","lbl_Address")->Text = txt_Address->Text;
		//
		// ����
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
 * �v���r���[�����F�t�@�C������
 */
void __fastcall TForm1::Preview_FileInput(TCrpReport *rpt)
{
	// ���\�b�h���ϐ��錾
	UnicodeString extension = ExtractFileExt(txt_InputPath->Text).LowerCase();
	UnicodeString name = "";
	UnicodeString address = "";
	UnicodeString memo = "";

	try
	{
        //**************************************************
		//�y�t�@�C���ǂݍ��݁z
		//**************************************************
		//
		// CSV
		//
		if (extension == ".csv")
		{
			TStringList *csvData = new TStringList();

			// �t�@�C���ǂݍ���
			csvData->LoadFromFile(txt_InputPath->Text);

			for (int i = 0; i < csvData->Count; i++)
			{
				UnicodeString readLine = csvData->Strings[i];
				TStringList *comma = new TStringList();

				// �󔒍s
				if (readLine.IsEmpty())
				{
                    continue;
				}

				// �R�����g�A�E�g
				if (readLine.SubString(0,1) == "#")
				{
                    continue;
				}

				// �J���}��؂蕪��
				comma->CommaText = readLine;

				// �t�@�C�����e�擾
				name = comma->Strings[0];
				address = comma->Strings[1];
				memo = comma->Strings[2];

				// �I�u�W�F�N�g�j��
				delete comma;
			}

			// �I�u�W�F�N�g�j��
			delete csvData;
		}
		//
		// XML
		//
		else if (extension == ".xml")
		{
			// �ǂݍ��ݐݒ�
			xmlDoc->DOMVendor = GetDOMVendor("MSXML");
			xmlDoc->Active = true;
			xmlDoc->Encoding = "UTF-8";

			// �t�@�C���ǂݍ���
			xmlDoc->LoadFromFile(txt_InputPath->Text);

			// �t�@�C�����e�擾
			name = Search_Xml_TextNode(xmlDoc->Node,"name");
			address = Search_Xml_TextNode(xmlDoc->Node,"address");
			memo = Search_Xml_TextNode(xmlDoc->Node,"memo");

			// �I�u�W�F�N�g�j��
			xmlDoc->Active = false;
			delete xmlDoc;
		}

		//**************************************************
		//�y����f�[�^�ݒ�z
		//**************************************************
		//
		// ���O
		//
		rpt->Item("","lbl_Name")->Text = name;
		//
		// �Z��
		//
		rpt->Item("","lbl_Address")->Text = address;
		//
		// ����
		//
		rpt->Item("","lbl_Memo")->Text = memo;
    }
	catch (int e)
	{
		throw e;
	}
}
//---------------------------------------------------------------------------

