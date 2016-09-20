//---------------------------------------------------------------------------

#ifndef ucenici_predmetiH
#define ucenici_predmetiH
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
class TFormUceniciPredmeti : public TForm
{
__published:	// IDE-managed Components
        TDBGrid *DBsg_uceniciPredmeti;
        TDBNavigator *DBNavigator1;
private:	// User declarations
        TColor tamnoSiva, svijetloSiva, svijetloPlava;
public:		// User declarations
        __fastcall TFormUceniciPredmeti(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormUceniciPredmeti *FormUceniciPredmeti;
//---------------------------------------------------------------------------
#endif
