object FormGlavna: TFormGlavna
  Left = 474
  Top = 114
  BorderStyle = bsSingle
  Caption = 'e-Dnevnik | Admin'
  ClientHeight = 442
  ClientWidth = 786
  Color = clBtnFace
  Font.Charset = EASTEUROPE_CHARSET
  Font.Color = clWhite
  Font.Height = -24
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 32
  object l_profesori: TLabel
    Left = 272
    Top = 192
    Width = 233
    Height = 49
    Alignment = taCenter
    AutoSize = False
    Caption = 'Profesori i predmeti'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clNone
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    Transparent = True
    OnClick = l_profesoriClick
  end
  object l_ucenici: TLabel
    Left = 272
    Top = 248
    Width = 233
    Height = 49
    Alignment = taCenter
    AutoSize = False
    Caption = 'U'#269'enici'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clNone
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    Transparent = True
    OnClick = l_uceniciClick
  end
  object l_admin: TLabel
    Left = 184
    Top = 48
    Width = 417
    Height = 49
    Alignment = taCenter
    AutoSize = False
    Caption = 'Administrator'
    Color = clBlack
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clGray
    Font.Height = -37
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Transparent = True
  end
  object l_uceniciPredmeti: TLabel
    Left = 272
    Top = 296
    Width = 233
    Height = 32
    Alignment = taCenter
    AutoSize = False
    Caption = 'U'#269'enici i predmeti'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clBlack
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    Transparent = True
    OnClick = l_uceniciPredmetiClick
  end
end
