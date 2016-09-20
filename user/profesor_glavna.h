//---------------------------------------------------------------------------

#ifndef profesor_glavnaH
#define profesor_glavnaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <vector>
#include "includes/predmet.h"
//---------------------------------------------------------------------------+
typedef void __fastcall (__closure *funkcija) (TObject *Sender);
class TFormProfesorGlavna : public TForm
{
__published:	// IDE-managed Components
        TImage *im_pozadina;
        TDBImage *DMim_slikaProfila;
        TDBText *DBl_ime;
        TDBText *DBl_prezime;
        TScrollBox *sb_predmeti;
        TLabel *l_predmetiNaslov;
        TLabel *l_razredNaslov;
        void __fastcall FormProfesorGlavnaOnClose(TObject *Sender,
          TCloseAction &Action);
        void __fastcall FormProfesorGlavnaOnShow(TObject *Sender);
private:	// User declarations
        int id_profesora;
        TColor tamnoSiva, svijetloSiva, svijetloPlava;
        std::vector<PredmetProfesor*> predmeti;
public:		// User declarations
        __fastcall TFormProfesorGlavna(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormProfesorGlavna *FormProfesorGlavna;
//---------------------------------------------------------------------------
#endif
