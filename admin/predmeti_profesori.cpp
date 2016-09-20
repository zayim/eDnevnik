//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "predmeti_profesori.h"
#include "dm_dataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPredmetiIProfesori *FormPredmetiIProfesori;
//---------------------------------------------------------------------------
__fastcall TFormPredmetiIProfesori::TFormPredmetiIProfesori(TComponent* Owner)
        : TForm(Owner)
{
        tamnoSiva = TColor(RGB(15,15,30));
        svijetloSiva = TColor(RGB(49,49,64));
        svijetloPlava = TColor(RGB(0,163,217));

        Color = tamnoSiva;
        Font->Color = clWhite;
        DBsg_profesori->Color=svijetloSiva;
        DBsg_profesori->FixedColor=svijetloPlava;

        DBsg_predmeti->Color=svijetloSiva;
        DBsg_predmeti->FixedColor=svijetloPlava;

        l_profesori->Font->Color=svijetloPlava;
        l_predmeti->Font->Color=svijetloPlava;
}
//---------------------------------------------------------------------------
void __fastcall TFormPredmetiIProfesori::ProfesoriOnEnter(TObject *Sender)
{
        DBn_navigator->DataSource = DataModule1->ds_profesori;
}
//---------------------------------------------------------------------------
void __fastcall TFormPredmetiIProfesori::PredmetiOnEnter(TObject *Sender)
{
        DBn_navigator->DataSource = DataModule1->ds_predmeti;
}
//---------------------------------------------------------------------------
