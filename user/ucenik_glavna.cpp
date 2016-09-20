//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ucenik_glavna.h"
#include "glavna.h"
#include "data_module.h"
#include "includes/predmet.h"
#include "uploaduj_zadacu.h"
#include <vector>
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormUcenikGlavna *FormUcenikGlavna;
//---------------------------------------------------------------------------
__fastcall TFormUcenikGlavna::TFormUcenikGlavna(TComponent* Owner)
        : TForm(Owner)
{
        tamnoSiva = TColor(RGB(15,15,30));
        svijetloSiva = TColor(RGB(49,49,64));
        svijetloPlava = TColor(RGB(0,163,217));

        Color = tamnoSiva;
        sb_ocjene->Color = svijetloSiva;
        l_ocjeneNaslov->Font->Color = svijetloPlava;
}
//---------------------------------------------------------------------------
void __fastcall TFormUcenikGlavna::FormUcenikGlavnaOnClose(TObject *Sender,
      TCloseAction &Action)
{
        FormLogin->Show();

        for (int i=0; i<predmeti.size(); i++)
                delete predmeti[i];
        predmeti.resize(0);        
}
//---------------------------------------------------------------------------
void __fastcall TFormUcenikGlavna::FormUcenikGlavnaOnShow(TObject *Sender)
{
        id_ucenika=dm_dataModule->ds_loginUcenik->DataSet->FieldByName("ucenik_id")->Value;
        int id_zadace;

        dm_dataModule->qy_predmeti->Active=false;
        dm_dataModule->qy_predmeti->Parameters->ParamByName("id_ucenika")->Value =
                id_ucenika;
        dm_dataModule->qy_predmeti->Active=true;

        while (dm_dataModule->ds_QYpredmeti->DataSet->RecNo < dm_dataModule->ds_QYpredmeti->DataSet->RecordCount)
        {
                AnsiString ime=dm_dataModule->ds_QYpredmeti->DataSet->FieldByName("ime")->Value;
                int id=dm_dataModule->ds_QYpredmeti->DataSet->FieldByName("predmet_id")->Value;

                if(!dm_dataModule->ds_QYpredmeti->DataSet->FieldByName("zadaca_id")->IsNull)
                        id_zadace=dm_dataModule->ds_QYpredmeti->DataSet->FieldByName("zadaca_id")->Value;
                else
                        id_zadace=-1;

                predmeti.push_back(new Predmet(id,id_ucenika,id_zadace,ime,dm_dataModule->ds_QYpredmeti->DataSet->RecNo-1,sb_ocjene));

                dm_dataModule->ds_QYpredmeti->DataSet->RecNo++;
        }

        if (dm_dataModule->ds_QYpredmeti->DataSet->RecordCount)
        {
                AnsiString ime=dm_dataModule->ds_QYpredmeti->DataSet->FieldByName("ime")->Value;
                int id=dm_dataModule->ds_QYpredmeti->DataSet->FieldByName("predmet_id")->Value;

                if(!dm_dataModule->ds_QYpredmeti->DataSet->FieldByName("zadaca_id")->IsNull)
                        id_zadace=dm_dataModule->ds_QYpredmeti->DataSet->FieldByName("zadaca_id")->Value;
                else
                        id_zadace=-1;

                predmeti.push_back(new Predmet(id,id_ucenika,id_zadace,ime,dm_dataModule->ds_QYpredmeti->DataSet->RecNo-1,sb_ocjene));
        }
}
//---------------------------------------------------------------------------

