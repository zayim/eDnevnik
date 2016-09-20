object DataModule1: TDataModule1
  OldCreateOrder = False
  Left = 604
  Top = 58
  Height = 309
  Width = 436
  object ADO_konekcija: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=MSDASQL.1;Password="";Persist Security Info=True;User I' +
      'D=root;Data Source=e_dnevnik'
    LoginPrompt = False
    Left = 32
    Top = 24
  end
  object tab_predmeti: TADOTable
    Active = True
    Connection = ADO_konekcija
    CursorType = ctStatic
    IndexFieldNames = 'profesor_id'
    MasterFields = 'profesor_id'
    MasterSource = ds_profesori
    TableName = 'predmeti'
    Left = 120
    Top = 24
    object tab_predmetipredmet_id: TAutoIncField
      FieldName = 'predmet_id'
      ReadOnly = True
    end
    object tab_predmetiime: TStringField
      FieldName = 'ime'
    end
    object tab_predmetiprofesor_id: TIntegerField
      FieldName = 'profesor_id'
    end
    object tab_predmetirazred: TIntegerField
      FieldName = 'razred'
    end
    object tab_predmetizadaca_id: TIntegerField
      FieldName = 'zadaca_id'
    end
  end
  object ds_predmeti: TDataSource
    DataSet = tab_predmeti
    Left = 120
    Top = 80
  end
  object tab_profesori: TADOTable
    Active = True
    Connection = ADO_konekcija
    CursorType = ctStatic
    TableName = 'profesori'
    Left = 192
    Top = 24
    object tab_profesoriprofesor_id: TAutoIncField
      FieldName = 'profesor_id'
      ReadOnly = True
    end
    object tab_profesoriime: TStringField
      FieldName = 'ime'
    end
    object tab_profesoriprezime: TStringField
      FieldName = 'prezime'
    end
    object tab_profesoriusername: TStringField
      FieldName = 'username'
    end
    object tab_profesoripassword: TStringField
      FieldName = 'password'
      Size = 50
    end
    object tab_profesorislika: TBlobField
      FieldName = 'slika'
    end
  end
  object ds_profesori: TDataSource
    DataSet = tab_profesori
    Left = 192
    Top = 80
  end
  object tab_ucenici: TADOTable
    Active = True
    Connection = ADO_konekcija
    CursorType = ctStatic
    TableName = 'ucenici'
    Left = 264
    Top = 24
    object tab_uceniciucenik_id: TAutoIncField
      FieldName = 'ucenik_id'
      ReadOnly = True
    end
    object tab_uceniciime: TStringField
      FieldName = 'ime'
    end
    object tab_uceniciprezime: TStringField
      FieldName = 'prezime'
    end
    object tab_uceniciusername: TStringField
      FieldName = 'username'
    end
    object tab_ucenicipassword: TStringField
      FieldName = 'password'
      Size = 50
    end
    object tab_ucenicirazred: TIntegerField
      FieldName = 'razred'
    end
    object tab_uceniciodjeljenje: TIntegerField
      FieldName = 'odjeljenje'
    end
    object tab_ucenicislika: TBlobField
      FieldName = 'slika'
    end
  end
  object ds_ucenici: TDataSource
    DataSet = tab_ucenici
    Left = 264
    Top = 80
  end
  object tab_uceniciPredmeti: TADOTable
    Active = True
    Connection = ADO_konekcija
    CursorType = ctStatic
    TableName = 'ucenici_predmeti'
    Left = 352
    Top = 24
    object tab_uceniciPredmetiucenik_predmet_id: TAutoIncField
      FieldName = 'ucenik_predmet_id'
      ReadOnly = True
    end
    object tab_uceniciPredmetiucenik_id: TIntegerField
      FieldName = 'ucenik_id'
    end
    object tab_uceniciPredmetipredmet_id: TIntegerField
      FieldName = 'predmet_id'
    end
    object tab_uceniciPredmetizadaca_status: TIntegerField
      FieldName = 'zadaca_status'
    end
  end
  object ds_uceniciPredmeti: TDataSource
    DataSet = tab_uceniciPredmeti
    Left = 352
    Top = 80
  end
end
