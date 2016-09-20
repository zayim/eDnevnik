//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("glavna.cpp", FormLogin);
USEFORM("data_module.cpp", dm_dataModule); /* TDataModule: File Type */
USEFORM("ucenik_glavna.cpp", FormUcenikGlavna);
USEFORM("profesor_glavna.cpp", FormProfesorGlavna);
USEFORM("predmet_profesor.cpp", FormPredmetProfesor);
USEFORM("dodaj_ocjenu.cpp", FormDodajOcjenu);
USEFORM("dodaj_zadacu.cpp", FormDodajZadacu);
USEFORM("uploaduj_zadacu.cpp", FormUploadujZadacu);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "e-Dnevnik";
                 Application->CreateForm(__classid(TFormLogin), &FormLogin);
                 Application->CreateForm(__classid(Tdm_dataModule), &dm_dataModule);
                 Application->CreateForm(__classid(TFormUcenikGlavna), &FormUcenikGlavna);
                 Application->CreateForm(__classid(TFormProfesorGlavna), &FormProfesorGlavna);
                 Application->CreateForm(__classid(TFormPredmetProfesor), &FormPredmetProfesor);
                 Application->CreateForm(__classid(TFormDodajOcjenu), &FormDodajOcjenu);
                 Application->CreateForm(__classid(TFormDodajZadacu), &FormDodajZadacu);
                 Application->CreateForm(__classid(TFormUploadujZadacu), &FormUploadujZadacu);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
