//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "predmet_profesor.h"
#include "profesor_glavna.h"
#include "data_module.h"
#include "dodaj_zadacu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <fstream>
TFormPredmetProfesor *FormPredmetProfesor;
//---------------------------------------------------------------------------
__fastcall TFormPredmetProfesor::TFormPredmetProfesor(TComponent* Owner)
        : TForm(Owner)
{
        tamnoSiva = TColor(RGB(15,15,30));
        svijetloSiva = TColor(RGB(49,49,64));
        svijetloPlava = TColor(RGB(0,163,217));

        Color = tamnoSiva;
        sb_ucenici->Color = svijetloSiva;
        bt_zadaca->Font->Color = svijetloPlava;
}
//---------------------------------------------------------------------------
void __fastcall TFormPredmetProfesor::FormPredmeProfesorOnShow(
      TObject *Sender)
{
        int idzad;
        dm_dataModule->statusIDZadace(id_predmeta,statusZadace,idzad);

        if (statusZadace==-1)
        {
                bt_zadaca->Caption = "Dodaj zadacu";
        }
        else if (statusZadace==0)
        {
                bt_zadaca->Caption = "Ukloni zadacu";
        }

        l_imePredmeta->Caption = ime_predmeta;

        dm_dataModule->qy_uceniciPredmet->Active=false;
        dm_dataModule->qy_uceniciPredmet->Parameters->ParamByName("id_predmeta")->Value = id_predmeta;
        dm_dataModule->qy_uceniciPredmet->Active=true;

        if (!dm_dataModule->ds_QYuceniciPredmet->DataSet->RecordCount) return;

        while (dm_dataModule->ds_QYuceniciPredmet->DataSet->RecNo < dm_dataModule->ds_QYuceniciPredmet->DataSet->RecordCount)
        {
                int iduc,idz,rb,sz;

                rb=dm_dataModule->ds_QYuceniciPredmet->DataSet->RecNo-1;
                iduc=dm_dataModule->ds_QYuceniciPredmet->DataSet->FieldByName("ucenik_id")->Value;

                if (!dm_dataModule->ds_QYuceniciPredmet->DataSet->FieldByName("zadaca_id")->IsNull)
                        idz=dm_dataModule->ds_QYuceniciPredmet->DataSet->FieldByName("zadaca_id")->Value;
                else
                        idz=-1;

                sz=dm_dataModule->ds_QYuceniciPredmet->DataSet->FieldByName("zadaca_status")->Value;

                AnsiString ime,prezime;
                ime=dm_dataModule->ds_QYuceniciPredmet->DataSet->FieldByName("ime")->Value;
                prezime=dm_dataModule->ds_QYuceniciPredmet->DataSet->FieldByName("prezime")->Value;

                ucenici.push_back(new UcenikPredmet(id_predmeta,iduc,idz,sz,rb,ime,prezime,sb_ucenici));
                dm_dataModule->ds_QYuceniciPredmet->DataSet->RecNo++;
        }
        if(dm_dataModule->ds_QYuceniciPredmet->DataSet->RecordCount)
        {
                int iduc,idz,rb,sz;

                rb=dm_dataModule->ds_QYuceniciPredmet->DataSet->RecNo-1;
                iduc=dm_dataModule->ds_QYuceniciPredmet->DataSet->FieldByName("ucenik_id")->Value;
                if (!dm_dataModule->ds_QYuceniciPredmet->DataSet->FieldByName("zadaca_id")->IsNull)
                        idz=dm_dataModule->ds_QYuceniciPredmet->DataSet->FieldByName("zadaca_id")->Value;
                else
                        idz=-1;

                sz=dm_dataModule->ds_QYuceniciPredmet->DataSet->FieldByName("zadaca_status")->Value;

                AnsiString ime,prezime;
                ime=dm_dataModule->ds_QYuceniciPredmet->DataSet->FieldByName("ime")->Value;
                prezime=dm_dataModule->ds_QYuceniciPredmet->DataSet->FieldByName("prezime")->Value;

                ucenici.push_back(new UcenikPredmet(id_predmeta,iduc,idz,sz,rb,ime,prezime,sb_ucenici));
                dm_dataModule->ds_QYuceniciPredmet->DataSet->RecNo++;
        }

}
//---------------------------------------------------------------------------

void __fastcall TFormPredmetProfesor::FormPredmetProfesorOnClose(
      TObject *Sender, TCloseAction &Action)
{
        for (int i=0; i<ucenici.size(); i++)
                delete ucenici[i];
        ucenici.resize(0);

        FormProfesorGlavna->Show();        
}
//---------------------------------------------------------------------------

void __fastcall TFormPredmetProfesor::bt_zadacaClick(TObject *Sender)
{
        if (statusZadace==-1)
        {
                FormDodajZadacu->set_id_predmeta(id_predmeta);
                FormDodajZadacu->Show();
                this->Hide();
                bt_zadaca->Caption = "Ukloni zadaæu";
                statusZadace=0;
        }
        else
        {
                dm_dataModule->qy_univerzalniUpit->DataSource = dm_dataModule->ds_predmeti;
                AnsiString upit=AnsiString("UPDATE predmeti SET zadaca_id=NULL WHERE predmet_id=") + id_predmeta + ";";
                dm_dataModule->izvrsiUpit(upit);

                upit=AnsiString("UPDATE ucenici_predmeti SET zadaca_status=0 WHERE predmet_id=") + id_predmeta + ";";
                dm_dataModule->izvrsiUpit(upit);

                ShowMessage("Uspješno uklonjeno!");
                this->Show();

                bt_zadaca->Caption = "Dodaj zadaæu";
                statusZadace=-1;
        }
}
//---------------------------------------------------------------------------
void TFormPredmetProfesor::preuzmiZadacu(int idz, int idu)
{
        dm_dataModule->q_rjesenjeZadace->Active=false;
        dm_dataModule->q_rjesenjeZadace->SQL->Clear();
        AnsiString upit = AnsiString("SELECT * FROM rjesenja_zadace_") + idz + " WHERE ucenik_id=" + idu + ";";
        dm_dataModule->q_rjesenjeZadace->SQL->Add(upit);
        dm_dataModule->q_rjesenjeZadace->Open();

        AnsiString sadrzaj = dm_dataModule->ds_QYrjesenjeZadace->DataSet->FieldByName("fajl")->AsString;

        sd_saveDialog->Execute();
        std::fstream zayim(sd_saveDialog->FileName.c_str(),std::ios::out | std::ios::binary);
        zayim.write(sadrzaj.c_str(), sadrzaj.Length());
        zayim.close();
}

