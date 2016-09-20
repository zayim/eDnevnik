//---------------------------------------------------------------------------

#ifndef dodaj_zadacuH
#define dodaj_zadacuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TFormDodajZadacu : public TForm
{
__published:	// IDE-managed Components
        TImage *im_pozadina;
        TLabel *l_imePredmeta;
        TMemo *me_tekstZadace;
        TLabel *l_tekstZadaceNaslov;
        TLabel *l_formatNaslov;
        TEdit *ed_format;
        TButton *bt_dodajZadacu;
        void __fastcall FormDodajZadacuOnClose(TObject *Sender,
          TCloseAction &Action);
        void __fastcall FormDodajZadacuOnShow(TObject *Sender);
        void __fastcall bt_dodajZadacuClick(TObject *Sender);
private:	// User declarations
        int id_predmeta;
        TColor tamnoSiva, svijetloSiva, svijetloPlava;
public:		// User declarations
        __fastcall TFormDodajZadacu(TComponent* Owner);
        void set_id_predmeta(int idp) { id_predmeta=idp; }
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDodajZadacu *FormDodajZadacu;
//---------------------------------------------------------------------------
#endif
