object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 350
  ClientWidth = 606
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 30
    Height = 13
    Caption = 'Discos'
  end
  object Label2: TLabel
    Left = 48
    Top = 247
    Width = 35
    Height = 13
    Caption = 'Torre 1'
  end
  object Label3: TLabel
    Left = 200
    Top = 247
    Width = 35
    Height = 13
    Caption = 'Torre 2'
  end
  object Label4: TLabel
    Left = 344
    Top = 247
    Width = 35
    Height = 13
    Caption = 'Torre 3'
  end
  object Label5: TLabel
    Left = 480
    Top = 29
    Width = 65
    Height = 13
    Caption = 'Torre a Sacar'
  end
  object Label6: TLabel
    Left = 480
    Top = 77
    Width = 68
    Height = 13
    Caption = 'Torre a Mover'
  end
  object Edit1: TEdit
    Left = 8
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 135
    Top = 22
    Width = 75
    Height = 25
    Caption = 'Iniciar'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 61
    Width = 121
    Height = 180
    Lines.Strings = (
      '')
    TabOrder = 2
  end
  object Memo2: TMemo
    Left = 152
    Top = 61
    Width = 121
    Height = 180
    Lines.Strings = (
      '')
    TabOrder = 3
  end
  object Memo3: TMemo
    Left = 296
    Top = 61
    Width = 121
    Height = 180
    Lines.Strings = (
      '')
    TabOrder = 4
  end
  object Edit2: TEdit
    Left = 480
    Top = 50
    Width = 97
    Height = 21
    TabOrder = 5
  end
  object Edit3: TEdit
    Left = 480
    Top = 96
    Width = 97
    Height = 21
    TabOrder = 6
  end
  object Button2: TButton
    Left = 480
    Top = 123
    Width = 97
    Height = 25
    Caption = 'Mover'
    TabOrder = 7
    OnClick = Button2Click
  end
end
