//---------------------------------------------------------------------------

#ifndef uceniciH
#define uceniciH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormUcenici : public TForm
{
__published:	// IDE-managed Components
        TDBGrid *DBsg_ucenici;
        TLabel *l_ucenici;
        TDBNavigator *DBn_navigator;
private:	// User declarations
        TColor tamnoSiva, svijetloSiva, svijetloPlava;
public:		// User declarations
        __fastcall TFormUcenici(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormUcenici *FormUcenici;
//---------------------------------------------------------------------------
#endif
