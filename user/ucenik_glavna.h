//---------------------------------------------------------------------------

#ifndef ucenik_glavnaH
#define ucenik_glavnaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Dialogs.hpp>
#include <vector>
#include "includes/predmet.h"
//---------------------------------------------------------------------------
class TFormUcenikGlavna : public TForm
{
__published:	// IDE-managed Components
        TImage *im_pozadina;
        TDBImage *DMim_slikaProfila;
        TDBText *DBl_ime;
        TDBText *DBl_prezime;
        TDBText *DBl_razred;
        TLabel *l_razredNaslov;
        TScrollBox *sb_ocjene;
        TLabel *l_ocjeneNaslov;
        void __fastcall FormUcenikGlavnaOnClose(TObject *Sender,
          TCloseAction &Action);
        void __fastcall FormUcenikGlavnaOnShow(TObject *Sender);
private:	// User declarations
        int id_ucenika;
        TColor tamnoSiva, svijetloSiva, svijetloPlava;
        std::vector<Predmet*> predmeti;
public:		// User declarations
        __fastcall TFormUcenikGlavna(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormUcenikGlavna *FormUcenikGlavna;
//---------------------------------------------------------------------------
#endif
