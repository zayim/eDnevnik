//---------------------------------------------------------------------------

#ifndef data_moduleH
#define data_moduleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class Tdm_dataModule : public TDataModule
{
__published:	// IDE-managed Components
        TADOConnection *ADO_konekcija;
        TADOTable *tab_ucenici;
        TAutoIncField *tab_uceniciucenik_id;
        TStringField *tab_uceniciime;
        TStringField *tab_uceniciprezime;
        TStringField *tab_uceniciusername;
        TStringField *tab_ucenicipassword;
        TIntegerField *tab_ucenicirazred;
        TIntegerField *tab_uceniciodjeljenje;
        TBlobField *tab_ucenicislika;
        TADOTable *tab_profesori;
        TAutoIncField *tab_profesoriprofesor_id;
        TStringField *tab_profesoriime;
        TStringField *tab_profesoriprezime;
        TStringField *tab_profesoriusername;
        TStringField *tab_profesoripassword;
        TBlobField *tab_profesorislika;
        TADOTable *tab_predmeti;
        TADOTable *tab_ucenici_predmeti;
        TAutoIncField *tab_ucenici_predmetiucenik_predmet_id;
        TIntegerField *tab_ucenici_predmetiucenik_id;
        TIntegerField *tab_ucenici_predmetipredmet_id;
        TAutoIncField *tab_predmetipredmet_id;
        TIntegerField *tab_predmetiprofesor_id;
        TIntegerField *tab_predmetirazred;
        TStringField *tab_predmetiime;
        TADOTable *tab_ocjene;
        TIntegerField *tab_ocjeneucenik_id;
        TIntegerField *tab_ocjenepredmet_id;
        TIntegerField *tab_ocjeneocjena;
        TDataSource *ds_ucenici;
        TDataSource *ds_profesori;
        TDataSource *ds_predmeti;
        TDataSource *ds_ucenici_predmeti;
        TDataSource *ds_ocjene;
        TADOQuery *qy_loginUcenik;
        TADOQuery *qy_loginProfesor;
        TDataSource *ds_loginUcenik;
        TDataSource *ds_loginProfesor;
        TADOQuery *qy_predmeti;
        TDataSource *ds_QYpredmeti;
        TADOQuery *qy_ocjene;
        TDataSource *ds_QYocjene;
        TADOQuery *qy_predmetiProfesor;
        TDataSource *ds_QYpredmetiProfesor;
        TADOQuery *qy_uceniciPredmet;
        TDataSource *ds_QYuceniciPredmet;
        TADOQuery *qy_univerzalniUpit;
        TDataSource *ds_QYuniverzalniUpit;
        TADOTable *tab_zadace;
        TDataSource *ds_zadace;
        TAutoIncField *tab_zadacezadaca_id;
        TMemoField *tab_zadacetekst_zadace;
        TStringField *tab_zadaceformat_fajla;
        TIntegerField *tab_zadacepredmet_id;
        TIntegerField *tab_zadacestatus;
        TIntegerField *tab_zadacemax_bodova;
        TADOQuery *qy_uneseniID;
        TDataSource *ds_QYuneseniID;
        TADOQuery *qy_statusIDZadace;
        TDataSource *ds_QYstatusIDZadace;
        TADOQuery *qy_zadaca;
        TDataSource *ds_QYzadaca;
        TADOQuery *q_rjesenjeZadace;
        TDataSource *ds_QYrjesenjeZadace;
private:	// User declarations
public:		// User declarations
        __fastcall Tdm_dataModule(TComponent* Owner);
        void izvrsiUpit(const AnsiString &upit);
        int uneseniIDZadace();
        void statusIDZadace(int predmeta, int &status, int &id);
};
//---------------------------------------------------------------------------
extern PACKAGE Tdm_dataModule *dm_dataModule;
//---------------------------------------------------------------------------
#endif
