//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ucenici_predmeti.h"
#include "dm_dataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormUceniciPredmeti *FormUceniciPredmeti;
//---------------------------------------------------------------------------
__fastcall TFormUceniciPredmeti::TFormUceniciPredmeti(TComponent* Owner)
        : TForm(Owner)
{
        tamnoSiva = TColor(RGB(15,15,30));
        svijetloSiva = TColor(RGB(49,49,64));
        svijetloPlava = TColor(RGB(0,163,217));

        Color = tamnoSiva;
        DBsg_uceniciPredmeti->FixedColor = svijetloPlava;
        DBsg_uceniciPredmeti->Color = svijetloSiva;
}
//---------------------------------------------------------------------------
