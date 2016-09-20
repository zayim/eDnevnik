//---------------------------------------------------------------------------

#ifndef dodaj_ocjenuH
#define dodaj_ocjenuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <jpeg.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormDodajOcjenu : public TForm
{
__published:	// IDE-managed Components
        TImage *im_left;
        TImage *im_right;
        TLabel *l_ocjena;
        TLabel *l_unesiNaslov;
        void __fastcall im_rightClick(TObject *Sender);
        void __fastcall im_leftClick(TObject *Sender);
        void __fastcall l_unesiNaslovClick(TObject *Sender);
private:	// User declarations
        int id_predmeta;
        int id_ucenika;
        int ocjena;
        TColor tamnoSiva, svijetloSiva, svijetloPlava;
        TJPEGImage *leftBlack,*leftBlue,*rightBlack,*rightBlue;
public:		// User declarations
        __fastcall TFormDodajOcjenu(TComponent* Owner);
        void set_id_predmeta(int idp) { id_predmeta=idp; }
        void set_id_ucenika(int idu) { id_ucenika=idu; }
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDodajOcjenu *FormDodajOcjenu;
//---------------------------------------------------------------------------
#endif
