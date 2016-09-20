object FormUceniciPredmeti: TFormUceniciPredmeti
  Left = 423
  Top = 143
  BorderStyle = bsSingle
  Caption = 'e-Dnevnik | U'#269'enici i predmeti'
  ClientHeight = 460
  ClientWidth = 650
  Color = clBtnFace
  Font.Charset = EASTEUROPE_CHARSET
  Font.Color = clWhite
  Font.Height = -16
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 21
  object DBsg_uceniciPredmeti: TDBGrid
    Left = 96
    Top = 48
    Width = 473
    Height = 289
    DataSource = DataModule1.ds_uceniciPredmeti
    TabOrder = 0
    TitleFont.Charset = EASTEUROPE_CHARSET
    TitleFont.Color = clWhite
    TitleFont.Height = -16
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
  end
  object DBNavigator1: TDBNavigator
    Left = 88
    Top = 360
    Width = 490
    Height = 49
    DataSource = DataModule1.ds_uceniciPredmeti
    TabOrder = 1
  end
end
