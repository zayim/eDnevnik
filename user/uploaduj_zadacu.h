//---------------------------------------------------------------------------

#ifndef uploaduj_zadacuH
#define uploaduj_zadacuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormUploadujZadacu : public TForm
{
__published:	// IDE-managed Components
        TImage *im_pozadina;
        TLabel *l_imePredmeta;
        TLabel *l_tekstZadaceNaslov;
        TMemo *me_tekstZadace;
        TLabel *l_formatNaslov;
        TEdit *ed_format;
        TButton *bt_dodajZadacu;
        TButton *bt_izaberiFajl;
        TOpenDialog *od_openDialog;
        void __fastcall FormUploadujZadacuOnShow(TObject *Sender);
        void __fastcall bt_izaberiFajlClick(TObject *Sender);
        void __fastcall bt_dodajZadacuClick(TObject *Sender);
private:	// User declarations
        TColor tamnoSiva, svijetloSiva, svijetloPlava;
        int id_zadace;
        int id_ucenika;
        int id_predmeta;
        char sadrzaj[1280000];
public:		// User declarations
        __fastcall TFormUploadujZadacu(TComponent* Owner);
        void set_id_zadace(int id) { id_zadace=id; }
        void set_id_ucenika(int id) { id_ucenika=id; }
        void set_id_predmeta(int id) { id_predmeta=id; }
};
//---------------------------------------------------------------------------
extern PACKAGE TFormUploadujZadacu *FormUploadujZadacu;
//---------------------------------------------------------------------------
#endif
