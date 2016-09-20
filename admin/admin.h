//---------------------------------------------------------------------------

#ifndef adminH
#define adminH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormGlavna : public TForm
{
__published:	// IDE-managed Components
        TLabel *l_profesori;
        TLabel *l_ucenici;
        TLabel *l_admin;
        TLabel *l_uceniciPredmeti;
        void __fastcall l_profesoriClick(TObject *Sender);
        void __fastcall l_uceniciClick(TObject *Sender);
        void __fastcall l_uceniciPredmetiClick(TObject *Sender);
private:	// User declarations
        TColor tamnoSiva, svijetloSiva, svijetloPlava;
public:		// User declarations
        __fastcall TFormGlavna(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGlavna *FormGlavna;
//---------------------------------------------------------------------------
#endif
