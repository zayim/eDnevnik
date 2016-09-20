object FormUcenici: TFormUcenici
  Left = 431
  Top = 114
  BorderStyle = bsSingle
  Caption = 'e-Dnevnik | U'#269'enici'
  ClientHeight = 524
  ClientWidth = 783
  Color = clBtnFace
  Font.Charset = EASTEUROPE_CHARSET
  Font.Color = clWhite
  Font.Height = -16
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 21
  object l_ucenici: TLabel
    Left = 264
    Top = 32
    Width = 233
    Height = 49
    Alignment = taCenter
    AutoSize = False
    Caption = 'U'#269'enici'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object DBsg_ucenici: TDBGrid
    Left = 88
    Top = 72
    Width = 593
    Height = 329
    DataSource = DataModule1.ds_ucenici
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    TitleFont.Charset = EASTEUROPE_CHARSET
    TitleFont.Color = clWhite
    TitleFont.Height = -16
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
  end
  object DBn_navigator: TDBNavigator
    Left = 87
    Top = 435
    Width = 590
    Height = 49
    DataSource = DataModule1.ds_ucenici
    TabOrder = 1
  end
end
