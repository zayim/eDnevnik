//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dodaj_ocjenu.h"
#include "data_module.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDodajOcjenu *FormDodajOcjenu;
//---------------------------------------------------------------------------
__fastcall TFormDodajOcjenu::TFormDodajOcjenu(TComponent* Owner)
        : TForm(Owner)
{
        tamnoSiva = TColor(RGB(15,15,30));
        svijetloSiva = TColor(RGB(49,49,64));
        svijetloPlava = TColor(RGB(0,163,217));

        Color=svijetloSiva;

        leftBlack = new TJPEGImage();
        leftBlue = new TJPEGImage();
        rightBlack = new TJPEGImage();
        rightBlue = new TJPEGImage();
        leftBlack->LoadFromFile("slike/arrow_left_black.jpg");
        leftBlue->LoadFromFile("slike/arrow_left_blue.jpg");
        rightBlack->LoadFromFile("slike/arrow_right_black.jpg");
        rightBlue->LoadFromFile("slike/arrow_right_blue.jpg");

        ocjena=1;
}
//---------------------------------------------------------------------------
void __fastcall TFormDodajOcjenu::im_rightClick(TObject *Sender)
{
        if (ocjena<5)
        {
                if (ocjena==1)
                        im_left->Picture->Assign(leftBlue);
                ocjena++;
                l_ocjena->Caption=ocjena;
                if (ocjena==5)
                        im_right->Picture->Assign(rightBlack);
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormDodajOcjenu::im_leftClick(TObject *Sender)
{
        if (ocjena>1)
        {
                if (ocjena==5)
                        im_right->Picture->Assign(rightBlue);
                ocjena--;
                l_ocjena->Caption=ocjena;
                if (ocjena==1)
                        im_left->Picture->Assign(leftBlack);
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormDodajOcjenu::l_unesiNaslovClick(TObject *Sender)
{
        dm_dataModule->qy_univerzalniUpit->Active=false;
        dm_dataModule->qy_univerzalniUpit->DataSource=dm_dataModule->ds_ocjene;
        AnsiString upit=AnsiString("INSERT INTO ocjene VALUES(") + id_ucenika + "," + id_predmeta + "," + ocjena + ");";
        dm_dataModule->izvrsiUpit(upit);

        ShowMessage("Uspješno uneseno!");
        this->Close();
}
//---------------------------------------------------------------------------
