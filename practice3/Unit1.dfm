object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #35506#38988#65299
  ClientHeight = 477
  ClientWidth = 469
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 50
    Top = 70
    Width = 400
    Height = 215
    Brush.Style = bsClear
  end
  object lbl_Title: TLabel
    Left = 0
    Top = 0
    Width = 465
    Height = 30
    Alignment = taCenter
    AutoSize = False
    Caption = #35506#38988#65299
    Color = 16744448
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Layout = tlCenter
  end
  object lbl_Name: TLabel
    Left = 70
    Top = 90
    Width = 50
    Height = 20
    AutoSize = False
    Caption = #21517#21069#65306
  end
  object lbl_Address: TLabel
    Left = 70
    Top = 130
    Width = 50
    Height = 20
    AutoSize = False
    Caption = #20303#25152#65306
  end
  object lbl_Memo: TLabel
    Left = 70
    Top = 170
    Width = 50
    Height = 20
    AutoSize = False
    Caption = #12513#12514#65306
  end
  object lbl_InputPath_Label: TLabel
    Left = 70
    Top = 346
    Width = 50
    Height = 20
    AutoSize = False
    Caption = #20837#21147#20803#65306
  end
  object Shape2: TShape
    Left = 50
    Top = 320
    Width = 400
    Height = 89
    Brush.Style = bsClear
  end
  object Label1: TLabel
    Left = 120
    Top = 375
    Width = 114
    Height = 20
    Alignment = taRightJustify
    AutoSize = False
    Caption = #8251'CSV'#12289'XML'#12398#12415#26377#21177
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object txt_Name: TEdit
    Left = 130
    Top = 87
    Width = 150
    Height = 21
    TabOrder = 0
  end
  object txt_Address: TEdit
    Left = 130
    Top = 127
    Width = 150
    Height = 21
    TabOrder = 1
  end
  object btn_End: TButton
    Left = 350
    Top = 430
    Width = 100
    Height = 30
    Caption = #32066#20102
    TabOrder = 4
    OnClick = btn_EndClick
  end
  object btn_Preview: TButton
    Left = 222
    Top = 430
    Width = 100
    Height = 30
    Caption = #12503#12524#12499#12517#12540
    TabOrder = 3
    OnClick = btn_PreviewClick
  end
  object txt_Memo: TMemo
    Left = 130
    Top = 167
    Width = 300
    Height = 100
    TabOrder = 2
  end
  object txt_InputPath: TEdit
    Left = 130
    Top = 343
    Width = 275
    Height = 21
    TabOrder = 5
  end
  object btn_InputPath_Dir: TButton
    Left = 405
    Top = 343
    Width = 25
    Height = 21
    Caption = '...'
    TabOrder = 6
    OnClick = btn_InputPath_DirClick
  end
  object rdo_Manual: TRadioButton
    Left = 30
    Top = 50
    Width = 90
    Height = 17
    Caption = #25163#20837#21147
    TabOrder = 7
    OnClick = rdo_ManualClick
  end
  object rdo_FileInput: TRadioButton
    Left = 30
    Top = 300
    Width = 90
    Height = 17
    Caption = #12501#12449#12452#12523#20837#21147
    TabOrder = 8
    OnClick = rdo_FileInputClick
  end
  object crp_practice3: TCrpReport
    Copies = 1
    Top = 448
  end
  object dlg_InputPath: TOpenDialog
    Left = 32
    Top = 448
  end
  object xmlDoc: TXMLDocument
    Left = 64
    Top = 448
    DOMVendorDesc = 'MSXML'
  end
end
