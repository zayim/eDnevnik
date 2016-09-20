//---------------------------------------------------------------------------


#pragma hdrstop

#include "ucenici_predmet.h"
#include "../dodaj_ocjenu.h"
#include "../predmet_profesor.h"

//---------------------------------------------------------------------------
UcenikPredmet::UcenikPredmet(int idpr, int iduc, int idz, int sz, int rb, const AnsiString &im, const AnsiString &pr, TWinControl* roditelj)
                                : l_ime(0), l_preuzmiZadacu(0), l_dodajOcjenu(0), rb(rb), status_zadace(sz),
                                  id_predmeta(idpr), id_ucenika(iduc), id_zadace(idz), ime_ucenika(im), prezime_ucenika(pr)
{
        tamnoSiva = TColor(RGB(15,15,30));
        svijetloSiva = TColor(RGB(49,49,64));
        svijetloPlava = TColor(RGB(0,163,217));

        l_ime = new TLabel(roditelj);
        l_ime->Parent = roditelj;
        l_ime->Top = rb * VISINA_PX;
        l_ime->Left = POZICIJA_IME_PX;
        l_ime->AutoSize = true;
        l_ime->Transparent = true;
        l_ime->Caption = ime_ucenika + " " + prezime_ucenika;

        if (status_zadace!=0)
        {
                l_preuzmiZadacu = new TLabel(roditelj);
                l_preuzmiZadacu->Parent = roditelj;
                l_preuzmiZadacu->Top = rb * VISINA_PX;
                l_preuzmiZadacu->Left = POZICIJA_PREUZMI_ZADACU_PX;
                l_preuzmiZadacu->AutoSize = true;
                l_preuzmiZadacu->Transparent = true;
                l_preuzmiZadacu->Caption = "Preuzmi zadaæu";
                l_preuzmiZadacu->OnClick = PreuzmiZadacuOnClick;
                l_preuzmiZadacu->Font->Color = svijetloPlava;
        }

        l_dodajOcjenu = new TLabel(roditelj);
        l_dodajOcjenu->Parent = roditelj;
        l_dodajOcjenu->Top = rb * VISINA_PX;
        l_dodajOcjenu->Left = POZICIJA_DODAJ_OCJENU_PX;
        l_dodajOcjenu->AutoSize = true;
        l_dodajOcjenu->Transparent = true;
        l_dodajOcjenu->Caption = "Dodaj ocjenu";
        l_dodajOcjenu->OnClick = DodajOcjenuOnClick;
        l_dodajOcjenu->Font->Color = svijetloPlava;
}
UcenikPredmet::~UcenikPredmet()
{
        delete l_ime;
        delete l_preuzmiZadacu;
        delete l_dodajOcjenu;
}
void __fastcall UcenikPredmet::PreuzmiZadacuOnClick(TObject *Sender)
{
        FormPredmetProfesor->preuzmiZadacu(id_zadace, id_ucenika);
}
void __fastcall UcenikPredmet::DodajOcjenuOnClick(TObject *Sender)
{
        FormDodajOcjenu->set_id_predmeta(id_predmeta);
        FormDodajOcjenu->set_id_ucenika(id_ucenika);
        FormDodajOcjenu->Show();
}
#pragma package(smart_init)
