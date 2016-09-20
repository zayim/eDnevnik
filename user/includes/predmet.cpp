//---------------------------------------------------------------------------


#pragma hdrstop

#include "predmet.h"
#include "../data_module.h"
#include "../predmet_profesor.h"

/*Predmet::Predmet(int idp, int idu, int idzad, const AnsiString &ime, int rb, TWinControl* roditelj)
        : id_predmeta(idp), id_ucenika(idu), ime_predmeta(ime), rb(rb), id_zadace(idzad)
{
        l_ime = new TLabel(roditelj);
        l_ime->Parent = roditelj;
        l_ime->Top = rb * VISINA_PX;
        l_ime->Left = POZICIJA_IME_PX;
        l_ime->Height = VISINA_PX;
        l_ime->Width = SIRINA_IME_PX;
        l_ime->Transparent = true;
        l_ime->Caption = ime;

        double prosjecna;
        AnsiString ocjene=vratiOcjene(prosjecna);

        l_ocjene = new TLabel(roditelj);
        l_ocjene->Parent = roditelj;
        l_ocjene->Top = rb * VISINA_PX;
        l_ocjene->Left = POZICIJA_OCJENE_PX;
        l_ocjene->Height = VISINA_PX;
        l_ocjene->Width = SIRINA_OCJENE_PX;
        l_ocjene->Transparent = true;
        l_ocjene->Caption = ocjene;
        l_ocjene->Alignment=taCenter;

        l_zakljucna = new TLabel(roditelj);
        l_zakljucna->Parent = roditelj;
        l_zakljucna->Top = rb * VISINA_PX;
        l_zakljucna->Left = POZICIJA_ZAKLJUCNA_PX;
        l_zakljucna->Height = VISINA_PX;
        l_zakljucna->Width = SIRINA_ZAKLJUCNA_PX;
        l_zakljucna->Transparent = true;
        zakljucna = ( prosjecna < (int)prosjecna + 0.5 ? (int)prosjecna : (int)prosjecna + 1 );
        l_zakljucna->Caption = AnsiString(prosjecna) + " (" + ( zakljucna ) + ")";
        l_zakljucna->Font->Color = TColor(RGB(0,163,217));
        l_zakljucna->Alignment=taRightJustify;
}
Predmet::~Predmet()
{
        delete l_ime;
        delete l_ocjene;
        delete l_zakljucna;
}
AnsiString Predmet::vratiOcjene(double &prosjecna)
{
        dm_dataModule->qy_ocjene->Active=false;
        dm_dataModule->qy_ocjene->Parameters->ParamByName("id_ucenika")->Value = id_ucenika;
        dm_dataModule->qy_ocjene->Parameters->ParamByName("id_predmeta")->Value = id_predmeta;
        dm_dataModule->qy_ocjene->Active=true;

        dm_dataModule->qy_ocjene->ExecSQL();

        prosjecna=0;
        if(dm_dataModule->ds_QYocjene->DataSet->RecordCount==0) return "";

        AnsiString strOcjene="";
        int zbir=0, broj=1;

        if (!dm_dataModule->ds_QYocjene->DataSet->FieldByName("ocjena")->IsNull)
        {
                strOcjene+= dm_dataModule->ds_QYocjene->DataSet->FieldByName("ocjena")->Value;
                zbir+=dm_dataModule->ds_QYocjene->DataSet->FieldByName("ocjena")->AsInteger;
        }

        while (dm_dataModule->ds_QYocjene->DataSet->RecNo != dm_dataModule->ds_QYocjene->DataSet->RecordCount)
        {
                dm_dataModule->ds_QYocjene->DataSet->RecNo++;
                if (!dm_dataModule->ds_QYocjene->DataSet->FieldByName("ocjena")->IsNull)
                {
                        strOcjene+= AnsiString(", ") + dm_dataModule->ds_QYocjene->DataSet->FieldByName("ocjena")->Value;
                        zbir+=dm_dataModule->ds_QYocjene->DataSet->FieldByName("ocjena")->AsInteger;
                        broj++;
                }
        }

        prosjecna = double(zbir)/broj;

        return strOcjene;
}

PredmetProfesor::PredmetProfesor(int idpred, int idprof, const AnsiString &ime, int rb, int razr, TWinControl* roditelj)
                : id_predmeta(idpred), id_profesora(idprof), ime_predmeta(ime), rb(rb), razred(razr)
{
        l_ime = new TLabel(roditelj);
        l_ime->Parent = roditelj;
        l_ime->Top = rb * VISINA_PX;
        l_ime->Left = POZICIJA_IME_PX;
        l_ime->Height = VISINA_PX;
        l_ime->Width = SIRINA_IME_PX;
        l_ime->Transparent = true;
        l_ime->Caption = ime;
        l_ime->OnClick=PredmetOnClick;

        l_razred = new TLabel(roditelj);
        l_razred->Parent = roditelj;
        l_razred->Top = rb * VISINA_PX;
        l_razred->Left = POZICIJA_RAZRED_PX;
        l_razred->Height = VISINA_PX;
        l_razred->Width = SIRINA_RAZRED_PX;
        l_razred->Transparent = true;
        l_razred->Caption = razred;
}
PredmetProfesor::~PredmetProfesor()
{
        delete l_ime;
        delete l_razred;
}
void __fastcall PredmetProfesor::PredmetOnClick(TObject *Sender)
{
        FormPredmetProfesor->set_id_predmeta(id_predmeta);
        FormPredmetProfesor->set_id_profesora(id_profesora);
        FormPredmetProfesor->set_ime_predmeta(ime_predmeta);
        FormPredmetProfesor->Show();
} */
//---------------------------------------------------------------------------

#pragma package(smart_init)
