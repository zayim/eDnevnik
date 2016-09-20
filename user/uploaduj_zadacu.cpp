//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uploaduj_zadacu.h"
#include "data_module.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormUploadujZadacu *FormUploadujZadacu;
//---------------------------------------------------------------------------
__fastcall TFormUploadujZadacu::TFormUploadujZadacu(TComponent* Owner)
        : TForm(Owner)
{
        tamnoSiva = TColor(RGB(15,15,30));
        svijetloSiva = TColor(RGB(49,49,64));
        svijetloPlava = TColor(RGB(0,163,217));

        Color = tamnoSiva;
        me_tekstZadace->Color = svijetloSiva;
        l_tekstZadaceNaslov->Font->Color = svijetloPlava;
        ed_format->Color=svijetloSiva;
        l_formatNaslov->Font->Color = svijetloPlava;
}
//---------------------------------------------------------------------------
void __fastcall TFormUploadujZadacu::FormUploadujZadacuOnShow(
      TObject *Sender)
{
        dm_dataModule->qy_zadaca->Active=false;
        dm_dataModule->qy_zadaca->Parameters->ParamByName("id_zadace")->Value=id_zadace;
        dm_dataModule->qy_zadaca->Active=true;

        me_tekstZadace -> Text = dm_dataModule->ds_QYzadaca->DataSet->FieldByName("tekst_zadace")->AsString;
        ed_format->Text = dm_dataModule->ds_QYzadaca->DataSet->FieldByName("format_fajla")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TFormUploadujZadacu::bt_izaberiFajlClick(TObject *Sender)
{
        od_openDialog->Execute();
        std::fstream zayim(od_openDialog->FileName.c_str(),std::ios::in | std::ios::binary);
        zayim.read(sadrzaj,1280000);
        zayim.close();
}
//---------------------------------------------------------------------------

void __fastcall TFormUploadujZadacu::bt_dodajZadacuClick(TObject *Sender)
{
        AnsiString upit = AnsiString("INSERT INTO rjesenja_zadace_") + id_zadace + "(ucenik_id,fajl) VALUES(" + id_ucenika + ",'" + sadrzaj + "');";
        dm_dataModule->izvrsiUpit(upit);

        upit = AnsiString("UPDATE ucenici_predmeti SET zadaca_status=1 WHERE predmet_id=") + id_predmeta + " AND ucenik_id=" + id_ucenika + ";";
        dm_dataModule->izvrsiUpit(upit);

        ShowMessage("Uspješno dodano!");
        this->Close();        
}
//---------------------------------------------------------------------------

