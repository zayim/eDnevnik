//---------------------------------------------------------------------------

#ifndef dm_dataModuleH
#define dm_dataModuleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
        TADOConnection *ADO_konekcija;
        TADOTable *tab_predmeti;
        TDataSource *ds_predmeti;
        TADOTable *tab_profesori;
        TDataSource *ds_profesori;
        TAutoIncField *tab_profesoriprofesor_id;
        TStringField *tab_profesoriime;
        TStringField *tab_profesoriprezime;
        TStringField *tab_profesoriusername;
        TStringField *tab_profesoripassword;
        TBlobField *tab_profesorislika;
        TADOTable *tab_ucenici;
        TDataSource *ds_ucenici;
        TAutoIncField *tab_uceniciucenik_id;
        TStringField *tab_uceniciime;
        TStringField *tab_uceniciprezime;
        TStringField *tab_uceniciusername;
        TStringField *tab_ucenicipassword;
        TIntegerField *tab_ucenicirazred;
        TIntegerField *tab_uceniciodjeljenje;
        TBlobField *tab_ucenicislika;
        TAutoIncField *tab_predmetipredmet_id;
        TStringField *tab_predmetiime;
        TIntegerField *tab_predmetiprofesor_id;
        TIntegerField *tab_predmetirazred;
        TIntegerField *tab_predmetizadaca_id;
        TADOTable *tab_uceniciPredmeti;
        TDataSource *ds_uceniciPredmeti;
        TAutoIncField *tab_uceniciPredmetiucenik_predmet_id;
        TIntegerField *tab_uceniciPredmetiucenik_id;
        TIntegerField *tab_uceniciPredmetipredmet_id;
        TIntegerField *tab_uceniciPredmetizadaca_status;
private:	// User declarations
public:		// User declarations
        __fastcall TDataModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
