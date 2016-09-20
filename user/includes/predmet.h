//---------------------------------------------------------------------------

#ifndef predmetH
#define predmetH
#include <vcl.h>

#include "../data_module.h"
#include "../predmet_profesor.h"
#include "../uploaduj_zadacu.h"

class Predmet
{
        int id_predmeta;
        int id_ucenika;
        int id_zadace;
        AnsiString ime_predmeta;
        int rb;
        int zakljucna;
        static const int VISINA_PX=50;
        static const int SIRINA_IME_PX=365;
        static const int SIRINA_OCJENE_PX=165;
        static const int SIRINA_ZAKLJUCNA_PX=115;
        static const int POZICIJA_IME_PX=20;
        static const int POZICIJA_OCJENE_PX=385;
        static const int POZICIJA_ZAKLJUCNA_PX=550;

        TLabel* l_ime, *l_ocjene, *l_zakljucna;

        void __fastcall PredmetOnClick(TObject *Sender)
{
        FormUploadujZadacu->set_id_zadace(id_zadace);
        FormUploadujZadacu->set_id_ucenika(id_ucenika);
        FormUploadujZadacu->set_id_predmeta(id_predmeta);
        FormUploadujZadacu->Show();
}

        public:
        Predmet::Predmet(int idp, int idu, int idzad, const AnsiString &ime, int rb, TWinControl* roditelj)
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

        if (id_zadace!=-1)
        {
                l_ime->Font->Color=TColor(RGB(0,163,217));
                l_ime->OnClick = PredmetOnClick;
        }

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
        dm_dataModule->qy_ocjene->Open();

        prosjecna=0;
        if(dm_dataModule->ds_QYocjene->DataSet->RecordCount==0) return "";

        AnsiString strOcjene="";
        int zbir=0, broj=1;

        dm_dataModule->ds_QYocjene->DataSet->RecNo=1;
        if (!dm_dataModule->ds_QYocjene->DataSet->FieldByName("ocjena")->IsNull)
        {
                strOcjene+= dm_dataModule->ds_QYocjene->DataSet->FieldByName("ocjena")->AsString;
                zbir+=dm_dataModule->ds_QYocjene->DataSet->FieldByName("ocjena")->AsInteger;
                dm_dataModule->ds_QYocjene->DataSet->RecNo++;
        }

        while (dm_dataModule->ds_QYocjene->DataSet->RecNo < dm_dataModule->ds_QYocjene->DataSet->RecordCount)
        {
                if (!dm_dataModule->ds_QYocjene->DataSet->FieldByName("ocjena")->IsNull)
                {
                        strOcjene+= AnsiString(", ") + dm_dataModule->ds_QYocjene->DataSet->FieldByName("ocjena")->AsInteger;
                        zbir+=dm_dataModule->ds_QYocjene->DataSet->FieldByName("ocjena")->AsInteger;
                        broj++;
                }
                dm_dataModule->ds_QYocjene->DataSet->RecNo++;
        }
        if(dm_dataModule->ds_QYocjene->DataSet->RecordCount>1 && !dm_dataModule->ds_QYocjene->DataSet->FieldByName("ocjena")->IsNull)
        {
                strOcjene+= AnsiString(", ") + dm_dataModule->ds_QYocjene->DataSet->FieldByName("ocjena")->AsInteger;
                zbir+=dm_dataModule->ds_QYocjene->DataSet->FieldByName("ocjena")->AsInteger;
                broj++;
        }

        prosjecna = double(zbir)/broj;

        return strOcjene;
}
};
typedef void __fastcall (__closure *funkcija) (TObject *Sender);
class PredmetProfesor
{
        int id_predmeta;
        int id_profesora;
        AnsiString ime_predmeta;
        int rb;
        int razred;
        static const int VISINA_PX=50;
        static const int SIRINA_IME_PX=365;
        static const int SIRINA_RAZRED_PX=165;
        static const int POZICIJA_IME_PX=38;
        static const int POZICIJA_RAZRED_PX=480;
        funkcija OnClick;
        void __fastcall PredmetProfesor::PredmetOnClick(TObject *Sender)
{
        FormPredmetProfesor->set_id_predmeta(id_predmeta);
        FormPredmetProfesor->set_id_profesora(id_profesora);
        FormPredmetProfesor->set_ime_predmeta(ime_predmeta);
        FormPredmetProfesor->Show();
}

        TLabel* l_ime, *l_razred;

        public:
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
        int get_id_predmeta() { return id_predmeta; }
};

//---------------------------------------------------------------------------
#endif

