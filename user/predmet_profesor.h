//---------------------------------------------------------------------------

#ifndef predmet_profesorH
#define predmet_profesorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Dialogs.hpp>
#include <vector>
#include "includes/ucenici_predmet.h"
//---------------------------------------------------------------------------
class TFormPredmetProfesor : public TForm
{
__published:	// IDE-managed Components
        TImage *im_pozadina;
        TLabel *l_imePredmeta;
        TScrollBox *sb_ucenici;
        TButton *bt_zadaca;
        TSaveDialog *sd_saveDialog;
        void __fastcall FormPredmeProfesorOnShow(TObject *Sender);
        void __fastcall FormPredmetProfesorOnClose(TObject *Sender,
          TCloseAction &Action);
        void __fastcall bt_zadacaClick(TObject *Sender);

private:	// User declarations
        int id_predmeta;
        int id_profesora;
        AnsiString ime_predmeta;
        TColor tamnoSiva, svijetloSiva, svijetloPlava;
        int statusZadace;

        std::vector<UcenikPredmet*> ucenici;
public:		// User declarations
        __fastcall TFormPredmetProfesor(TComponent* Owner);
        void set_id_predmeta(int id) { id_predmeta=id; }
        void set_id_profesora(int id) { id_profesora=id; }
        void set_ime_predmeta(const AnsiString& ime) { ime_predmeta=ime; }
        void preuzmiZadacu(int idz, int idu);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPredmetProfesor *FormPredmetProfesor;
//---------------------------------------------------------------------------
#endif
