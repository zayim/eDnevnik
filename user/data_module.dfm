object dm_dataModule: Tdm_dataModule
  OldCreateOrder = False
  Left = 472
  Top = 136
  Height = 644
  Width = 1027
  object ADO_konekcija: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=MSDASQL.1;Password="";Persist Security Info=True;User I' +
      'D=root;Data Source=e_dnevnik'
    LoginPrompt = False
    Left = 48
    Top = 32
  end
  object tab_ucenici: TADOTable
    Connection = ADO_konekcija
    CursorType = ctStatic
    TableName = 'ucenici'
    Left = 40
    Top = 104
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
  object tab_profesori: TADOTable
    Active = True
    Connection = ADO_konekcija
    CursorType = ctStatic
    TableName = 'profesori'
    Left = 128
    Top = 104
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
  object tab_predmeti: TADOTable
    Active = True
    Connection = ADO_konekcija
    CursorType = ctStatic
    TableName = 'predmeti'
    Left = 208
    Top = 104
    object tab_predmetipredmet_id: TAutoIncField
      FieldName = 'predmet_id'
      ReadOnly = True
    end
    object tab_predmetiprofesor_id: TIntegerField
      FieldName = 'profesor_id'
    end
    object tab_predmetirazred: TIntegerField
      FieldName = 'razred'
    end
    object tab_predmetiime: TStringField
      FieldName = 'ime'
    end
  end
  object tab_ucenici_predmeti: TADOTable
    Active = True
    Connection = ADO_konekcija
    CursorType = ctStatic
    TableName = 'ucenici_predmeti'
    Left = 296
    Top = 104
    object tab_ucenici_predmetiucenik_predmet_id: TAutoIncField
      FieldName = 'ucenik_predmet_id'
      ReadOnly = True
    end
    object tab_ucenici_predmetiucenik_id: TIntegerField
      FieldName = 'ucenik_id'
    end
    object tab_ucenici_predmetipredmet_id: TIntegerField
      FieldName = 'predmet_id'
    end
  end
  object tab_ocjene: TADOTable
    Active = True
    Connection = ADO_konekcija
    CursorType = ctStatic
    TableName = 'ocjene'
    Left = 384
    Top = 104
    object tab_ocjeneucenik_id: TIntegerField
      FieldName = 'ucenik_id'
    end
    object tab_ocjenepredmet_id: TIntegerField
      FieldName = 'predmet_id'
    end
    object tab_ocjeneocjena: TIntegerField
      FieldName = 'ocjena'
    end
  end
  object ds_ucenici: TDataSource
    DataSet = tab_ucenici
    Left = 40
    Top = 168
  end
  object ds_profesori: TDataSource
    DataSet = tab_profesori
    Left = 128
    Top = 168
  end
  object ds_predmeti: TDataSource
    DataSet = tab_predmeti
    Left = 208
    Top = 168
  end
  object ds_ucenici_predmeti: TDataSource
    DataSet = tab_ucenici_predmeti
    Left = 296
    Top = 168
  end
  object ds_ocjene: TDataSource
    DataSet = tab_ocjene
    Left = 384
    Top = 168
  end
  object qy_loginUcenik: TADOQuery
    Active = True
    Connection = ADO_konekcija
    CursorType = ctStatic
    DataSource = ds_ucenici
    Parameters = <
      item
        Name = 'un'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 255
        Size = 255
        Value = Null
      end
      item
        Name = 'pw'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 255
        Size = 255
        Value = Null
      end>
    SQL.Strings = (
      'SELECT * FROM ucenici WHERE username=:un AND password =:pw;')
    Left = 40
    Top = 264
  end
  object qy_loginProfesor: TADOQuery
    Connection = ADO_konekcija
    DataSource = ds_ucenici
    Parameters = <
      item
        Name = 'un'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 255
        Size = 255
        Value = Null
      end
      item
        Name = 'pw'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 255
        Size = 255
        Value = Null
      end>
    SQL.Strings = (
      'SELECT * FROM profesori WHERE username=:un AND password =:pw;')
    Left = 120
    Top = 264
  end
  object ds_loginUcenik: TDataSource
    DataSet = qy_loginUcenik
    Left = 40
    Top = 320
  end
  object ds_loginProfesor: TDataSource
    DataSet = qy_loginProfesor
    Left = 120
    Top = 320
  end
  object qy_predmeti: TADOQuery
    Connection = ADO_konekcija
    DataSource = ds_predmeti
    Parameters = <
      item
        Name = 'id_ucenika'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 255
        Size = 255
        Value = Null
      end>
    SQL.Strings = (
      
        'SELECT * FROM ucenici_predmeti JOIN predmeti ON ucenici_predmeti' +
        '.predmet_id = predmeti.predmet_id WHERE ucenici_predmeti.ucenik_' +
        'id = :id_ucenika;')
    Left = 208
    Top = 264
  end
  object ds_QYpredmeti: TDataSource
    DataSet = qy_predmeti
    Left = 208
    Top = 320
  end
  object qy_ocjene: TADOQuery
    Connection = ADO_konekcija
    DataSource = ds_ocjene
    Parameters = <
      item
        Name = 'id_ucenika'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 255
        Size = 255
        Value = Null
      end
      item
        Name = 'id_predmeta'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 255
        Size = 255
        Value = Null
      end>
    SQL.Strings = (
      
        'SELECT * FROM ocjene WHERE ucenik_id = :id_ucenika AND predmet_i' +
        'd = :id_predmeta;')
    Left = 288
    Top = 264
  end
  object ds_QYocjene: TDataSource
    DataSet = qy_ocjene
    Left = 288
    Top = 320
  end
  object qy_predmetiProfesor: TADOQuery
    Connection = ADO_konekcija
    DataSource = ds_profesori
    Parameters = <
      item
        Name = 'id_profesora'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 255
        Size = 255
        Value = Null
      end>
    SQL.Strings = (
      'SELECT * FROM predmeti WHERE profesor_id= :id_profesora;')
    Left = 392
    Top = 264
  end
  object ds_QYpredmetiProfesor: TDataSource
    DataSet = qy_predmetiProfesor
    Left = 392
    Top = 320
  end
  object qy_uceniciPredmet: TADOQuery
    Connection = ADO_konekcija
    DataSource = ds_ucenici_predmeti
    Parameters = <
      item
        Name = 'id_predmeta'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 255
        Size = 255
        Value = Null
      end>
    SQL.Strings = (
      
        'SELECT * FROM ucenici JOIN ucenici_predmeti ON ucenici.ucenik_id' +
        ' = ucenici_predmeti.ucenik_id JOIN predmeti ON predmeti.predmet_' +
        'id = ucenici_predmeti.predmet_id WHERE ucenici_predmeti.predmet_' +
        'id = :id_predmeta;;')
    Left = 512
    Top = 264
  end
  object ds_QYuceniciPredmet: TDataSource
    DataSet = qy_uceniciPredmet
    Left = 512
    Top = 320
  end
  object qy_univerzalniUpit: TADOQuery
    Connection = ADO_konekcija
    Parameters = <>
    Left = 680
    Top = 264
  end
  object ds_QYuniverzalniUpit: TDataSource
    DataSet = qy_univerzalniUpit
    Left = 680
    Top = 320
  end
  object tab_zadace: TADOTable
    Connection = ADO_konekcija
    CursorType = ctStatic
    TableName = 'zadace'
    Left = 448
    Top = 104
    object tab_zadacezadaca_id: TAutoIncField
      FieldName = 'zadaca_id'
      ReadOnly = True
    end
    object tab_zadacetekst_zadace: TMemoField
      FieldName = 'tekst_zadace'
      BlobType = ftMemo
    end
    object tab_zadaceformat_fajla: TStringField
      FieldName = 'format_fajla'
      Size = 10
    end
    object tab_zadacepredmet_id: TIntegerField
      FieldName = 'predmet_id'
    end
    object tab_zadacestatus: TIntegerField
      FieldName = 'status'
    end
    object tab_zadacemax_bodova: TIntegerField
      FieldName = 'max_bodova'
    end
  end
  object ds_zadace: TDataSource
    DataSet = tab_zadace
    Left = 448
    Top = 168
  end
  object qy_uneseniID: TADOQuery
    Connection = ADO_konekcija
    DataSource = ds_zadace
    Parameters = <>
    SQL.Strings = (
      'SELECT max(zadaca_id) FROM zadace;')
    Left = 808
    Top = 264
  end
  object ds_QYuneseniID: TDataSource
    DataSet = qy_uneseniID
    Left = 808
    Top = 328
  end
  object qy_statusIDZadace: TADOQuery
    Connection = ADO_konekcija
    DataSource = ds_zadace
    Parameters = <
      item
        Name = 'id_predmeta'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 255
        Size = 255
        Value = Null
      end>
    SQL.Strings = (
      
        'SELECT * FROM predmeti JOIN zadace ON zadace.zadaca_id = predmet' +
        'i.zadaca_id WHERE predmeti.predmet_id=:id_predmeta;')
    Left = 48
    Top = 408
  end
  object ds_QYstatusIDZadace: TDataSource
    DataSet = qy_statusIDZadace
    Left = 48
    Top = 472
  end
  object qy_zadaca: TADOQuery
    Connection = ADO_konekcija
    DataSource = ds_zadace
    Parameters = <
      item
        Name = 'id_zadace'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 255
        Size = 255
        Value = Null
      end>
    SQL.Strings = (
      'SELECT * FROM zadace WHERE zadaca_id=:id_zadace;')
    Left = 208
    Top = 408
  end
  object ds_QYzadaca: TDataSource
    DataSet = qy_zadaca
    Left = 208
    Top = 472
  end
  object q_rjesenjeZadace: TADOQuery
    Connection = ADO_konekcija
    DataSource = ds_zadace
    Parameters = <>
    Left = 304
    Top = 416
  end
  object ds_QYrjesenjeZadace: TDataSource
    DataSet = q_rjesenjeZadace
    Left = 304
    Top = 480
  end
end
