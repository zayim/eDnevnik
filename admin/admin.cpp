//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "admin.h"
#include "dm_dataModule.h"
#include "predmeti_profesori.h"
#include "ucenici.h"
#include "ucenici_predmeti.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormGlavna *FormGlavna;
//---------------------------------------------------------------------------
__fastcall TFormGlavna::TFormGlavna(TComponent* Owner)
        : TForm(Owner)
{
        tamnoSiva = TColor(RGB(15,15,30));
        svijetloSiva = TColor(RGB(49,49,64));
        svijetloPlava = TColor(RGB(0,163,217));

        Color = tamnoSiva;
        l_profesori->Font->Color = svijetloPlava;
        l_ucenici->Font->Color = svijetloPlava;
        l_uceniciPredmeti->Font->Color = svijetloPlava;
        l_admin->Font->Color=svijetloSiva;
}
//---------------------------------------------------------------------------
void __fastcall TFormGlavna::l_profesoriClick(TObject *Sender)
{
        FormPredmetiIProfesori->Show();        
}
//---------------------------------------------------------------------------
void __fastcall TFormGlavna::l_uceniciClick(TObject *Sender)
{
        FormUcenici->Show();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TFormGlavna::l_uceniciPredmetiClick(TObject *Sender)
{
        FormUceniciPredmeti->Show();        
}
//---------------------------------------------------------------------------

