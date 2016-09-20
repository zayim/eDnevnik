//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "data_module.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tdm_dataModule *dm_dataModule;
//---------------------------------------------------------------------------
__fastcall Tdm_dataModule::Tdm_dataModule(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void Tdm_dataModule::izvrsiUpit(const AnsiString &upit)
{
        qy_univerzalniUpit->Active=false;
        qy_univerzalniUpit->SQL->Clear();
        qy_univerzalniUpit->SQL->Add(upit);
        qy_univerzalniUpit->ExecSQL();
}
int Tdm_dataModule::uneseniIDZadace()
{
        qy_uneseniID->Active=false;
        qy_uneseniID->Active=true;

        return ds_QYuneseniID->DataSet->Fields->Fields[0]->AsInteger;
}
void Tdm_dataModule::statusIDZadace(int predmeta, int &status, int &id)
{
        qy_statusIDZadace->Active=false;
        qy_statusIDZadace->Parameters->ParamByName("id_predmeta")->Value=predmeta;
        qy_statusIDZadace->Open();

        if (ds_QYstatusIDZadace->DataSet->RecordCount==0)
        {
                status=-1;
                id=-1;
                return;
        }

        status = ds_QYstatusIDZadace->DataSet->FieldByName("status")->AsInteger;
        id =  ds_QYstatusIDZadace->DataSet->FieldByName("zadaca_id")->AsInteger;
}
