//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "profesor_glavna.h"
#include "glavna.h"
#include "predmet_profesor.h"
#include "data_module.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormProfesorGlavna *FormProfesorGlavna;
//---------------------------------------------------------------------------
__fastcall TFormProfesorGlavna::TFormProfesorGlavna(TComponent* Owner)
        : TForm(Owner)
{
        tamnoSiva = TColor(RGB(15,15,30));
        svijetloSiva = TColor(RGB(49,49,64));
        svijetloPlava = TColor(RGB(0,163,217));

        Color = tamnoSiva;
        sb_predmeti->Color = svijetloSiva;
        l_predmetiNaslov->Font->Color = svijetloPlava;
        l_razredNaslov->Font->Color = svijetloPlava;
}
//---------------------------------------------------------------------------
void __fastcall TFormProfesorGlavna::FormProfesorGlavnaOnClose(
      TObject *Sender, TCloseAction &Action)
{
        FormLogin->Show();
        for (int i=0; i<predmeti.size(); i++)
                delete predmeti[i];
        predmeti.resize(0);
}
//---------------------------------------------------------------------------
void __fastcall TFormProfesorGlavna::FormProfesorGlavnaOnShow(
      TObject *Sender)
{
        id_profesora=dm_dataModule->ds_loginProfesor->DataSet->FieldByName("profesor_id")->Value;

        dm_dataModule->qy_predmetiProfesor->Active=false;
        dm_dataModule->qy_predmetiProfesor->Parameters->ParamByName("id_profesora")->Value =
                id_profesora;
        dm_dataModule->qy_predmetiProfesor->Active=true;

        dm_dataModule->qy_predmetiProfesor->ExecSQL();

        while (dm_dataModule->ds_QYpredmetiProfesor->DataSet->RecNo != dm_dataModule->ds_QYpredmetiProfesor->DataSet->RecordCount)
        {
                AnsiString ime=dm_dataModule->ds_QYpredmetiProfesor->DataSet->FieldByName("ime")->Value;
                int id=dm_dataModule->ds_QYpredmetiProfesor->DataSet->FieldByName("predmet_id")->Value;
                int raz=dm_dataModule->ds_QYpredmetiProfesor->DataSet->FieldByName("razred")->Value;

                predmeti.push_back(new PredmetProfesor(id,id_profesora,ime,dm_dataModule->ds_QYpredmetiProfesor->DataSet->RecNo-1,raz,(TWinControl*)sb_predmeti));

                dm_dataModule->ds_QYpredmetiProfesor->DataSet->RecNo++;
        }

        if (dm_dataModule->ds_QYpredmetiProfesor->DataSet->RecordCount !=0)
        {
                AnsiString ime=dm_dataModule->ds_QYpredmetiProfesor->DataSet->FieldByName("ime")->Value;
                int id=dm_dataModule->ds_QYpredmetiProfesor->DataSet->FieldByName("predmet_id")->Value;
                int raz=dm_dataModule->ds_QYpredmetiProfesor->DataSet->FieldByName("razred")->Value;

                predmeti.push_back(new PredmetProfesor(id,id_profesora,ime,dm_dataModule->ds_QYpredmetiProfesor->DataSet->RecNo-1,raz,(TWinControl*)sb_predmeti));

                dm_dataModule->ds_QYpredmetiProfesor->DataSet->RecNo++;
        }

}
//---------------------------------------------------------------------------

