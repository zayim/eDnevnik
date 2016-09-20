//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "glavna.h"
#include "data_module.h"
#include "profesor_glavna.h"
#include "ucenik_glavna.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormLogin *FormLogin;
//---------------------------------------------------------------------------
__fastcall TFormLogin::TFormLogin(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormLogin::bt_prijaviUcenikClick(TObject *Sender)
{
        dm_dataModule->qy_loginUcenik->Active=false;
        dm_dataModule->qy_loginUcenik->Parameters->ParamByName("un")->Value =
                ed_username->Text;
        dm_dataModule->qy_loginUcenik->Parameters->ParamByName("pw")->Value =
                ed_password->Text;

        dm_dataModule->qy_loginUcenik->Active=true;
        dm_dataModule->qy_loginUcenik->ExecSQL();

        if (dm_dataModule->qy_loginUcenik->RecordCount!=1)

                ShowMessage("Pogešni podaci!");
        else
        {
                FormUcenikGlavna->Show();
                this->Hide();
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormLogin::bt_prijaviProfesorClick(TObject *Sender)
{
        dm_dataModule->qy_loginProfesor->Active=false;
        dm_dataModule->qy_loginProfesor->Parameters->ParamByName("un")->Value =
                ed_username->Text;
        dm_dataModule->qy_loginProfesor->Parameters->ParamByName("pw")->Value =
                ed_password->Text;

        dm_dataModule->qy_loginProfesor->Active=true;
        dm_dataModule->qy_loginProfesor->ExecSQL();

        if (dm_dataModule->qy_loginProfesor->RecordCount!=1)
                ShowMessage("Pogešni podaci!");
        else
        {
                FormProfesorGlavna->Show();
                this->Hide();
        }
}
//---------------------------------------------------------------------------
