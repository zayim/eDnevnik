//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("admin.cpp", FormGlavna);
USEFORM("dm_dataModule.cpp", DataModule1); /* TDataModule: File Type */
USEFORM("predmeti_profesori.cpp", FormPredmetiIProfesori);
USEFORM("ucenici.cpp", FormUcenici);
USEFORM("ucenici_predmeti.cpp", FormUceniciPredmeti);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "e-Dnevnik | Administrator";
                 Application->CreateForm(__classid(TFormGlavna), &FormGlavna);
                 Application->CreateForm(__classid(TDataModule1), &DataModule1);
                 Application->CreateForm(__classid(TFormPredmetiIProfesori), &FormPredmetiIProfesori);
                 Application->CreateForm(__classid(TFormUcenici), &FormUcenici);
                 Application->CreateForm(__classid(TFormUceniciPredmeti), &FormUceniciPredmeti);
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
