//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ucenici.h"
#include "dm_dataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormUcenici *FormUcenici;
//---------------------------------------------------------------------------
__fastcall TFormUcenici::TFormUcenici(TComponent* Owner)
        : TForm(Owner)
{
        tamnoSiva = TColor(RGB(15,15,30));
        svijetloSiva = TColor(RGB(49,49,64));
        svijetloPlava = TColor(RGB(0,163,217));

        Color = tamnoSiva;
        Font->Color = svijetloPlava;

        DBsg_ucenici->Color=svijetloSiva;
        DBsg_ucenici->FixedColor=svijetloPlava;

        l_ucenici->Font->Color = svijetloPlava;
}
//---------------------------------------------------------------------------
