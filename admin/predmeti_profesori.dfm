object FormPredmetiIProfesori: TFormPredmetiIProfesori
  Left = 507
  Top = 129
  BorderStyle = bsSingle
  Caption = 'e-dnevnik | Predmeti i profesori'
  ClientHeight = 639
  ClientWidth = 856
  Color = clBtnFace
  Font.Charset = EASTEUROPE_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 21
  object l_profesori: TLabel
    Left = 304
    Top = 32
    Width = 233
    Height = 49
    Alignment = taCenter
    AutoSize = False
    Caption = 'Profesori'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object l_predmeti: TLabel
    Left = 304
    Top = 296
    Width = 233
    Height = 49
    Alignment = taCenter
    AutoSize = False
    Caption = 'Predmeti'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object DBsg_profesori: TDBGrid
    Left = 24
    Top = 64
    Width = 817
    Height = 193
    DataSource = DataModule1.ds_profesori
    TabOrder = 0
    TitleFont.Charset = EASTEUROPE_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -16
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnEnter = ProfesoriOnEnter
  end
  object DBsg_predmeti: TDBGrid
    Left = 24
    Top = 336
    Width = 817
    Height = 193
    DataSource = DataModule1.ds_predmeti
    TabOrder = 1
    TitleFont.Charset = EASTEUROPE_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -16
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnEnter = PredmetiOnEnter
  end
  object DBn_navigator: TDBNavigator
    Left = 24
    Top = 568
    Width = 800
    Height = 49
    DataSource = DataModule1.ds_profesori
    TabOrder = 2
  end
end
