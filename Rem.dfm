object MyRemove: TMyRemove
  Left = 0
  Top = 0
  Caption = 'MyRemove'
  ClientHeight = 110
  ClientWidth = 182
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
    Left = 24
    Top = 15
    Width = 134
    Height = 19
    Caption = #1042#1080#1073#1077#1088#1110#1090#1100' '#1087#1086#1079#1080#1094#1110#1102':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 56
    Top = 68
    Width = 75
    Height = 25
    Caption = #1042#1080#1076#1072#1083#1080#1090#1080
    TabOrder = 0
    OnClick = Button1Click
  end
  object CSpinEdit1: TCSpinEdit
    Left = 32
    Top = 40
    Width = 121
    Height = 22
    MaxValue = 100
    MinValue = 1
    TabOrder = 1
    Value = 1
    OnChange = CSpinEdit1Change
  end
end
