//---------------------------------------------------------------------------

#ifndef glavnaH
#define glavnaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TFormLogin : public TForm
{
__published:	// IDE-managed Components
        TImage *im_pozadina;
        TEdit *ed_username;
        TEdit *ed_password;
        TButton *bt_prijaviUcenik;
        TButton *bt_prijaviProfesor;
        void __fastcall bt_prijaviUcenikClick(TObject *Sender);
        void __fastcall bt_prijaviProfesorClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLogin *FormLogin;
//---------------------------------------------------------------------------
#endif
