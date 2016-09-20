//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dodaj_zadacu.h"
#include "predmet_profesor.h"
#include "data_module.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDodajZadacu *FormDodajZadacu;
//---------------------------------------------------------------------------
__fastcall TFormDodajZadacu::TFormDodajZadacu(TComponent* Owner)
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
void __fastcall TFormDodajZadacu::FormDodajZadacuOnClose(TObject *Sender,
      TCloseAction &Action)
{
        FormPredmetProfesor->Show();        
}
//---------------------------------------------------------------------------
void __fastcall TFormDodajZadacu::FormDodajZadacuOnShow(TObject *Sender)
{
        1+2;       
}
//---------------------------------------------------------------------------
void __fastcall TFormDodajZadacu::bt_dodajZadacuClick(TObject *Sender)
{
        dm_dataModule->qy_univerzalniUpit->DataSource = dm_dataModule->ds_zadace;
        AnsiString upit=AnsiString("INSERT INTO zadace(tekst_zadace,format_fajla,predmet_id) VALUES('") + me_tekstZadace->Text + "','" + ed_format->Text + "'," + id_predmeta + ");";
        dm_dataModule->izvrsiUpit(upit);

        int ubaceniID=dm_dataModule->uneseniIDZadace();

        dm_dataModule->qy_univerzalniUpit->DataSource = dm_dataModule->ds_predmeti;
        upit=AnsiString("UPDATE predmeti SET zadaca_id=") + ubaceniID + " WHERE predmet_id=" + id_predmeta + ";";
        dm_dataModule->izvrsiUpit(upit);

        upit=AnsiString("CREATE TABLE rjesenja_zadace_") + ubaceniID + " ( ucenik_id INT, FOREIGN KEY(ucenik_id) REFERENCES ucenici(ucenik_id), fajl LONGBLOB);";
        dm_dataModule->izvrsiUpit(upit);

        ShowMessage("Uspješno dodano!");
        this->Close();
}
//---------------------------------------------------------------------------
