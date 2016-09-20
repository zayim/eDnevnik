//---------------------------------------------------------------------------

#ifndef predmeti_profesoriH
#define predmeti_profesoriH
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
class TFormPredmetiIProfesori : public TForm
{
__published:	// IDE-managed Components
        TDBGrid *DBsg_profesori;
        TDBGrid *DBsg_predmeti;
        TDBNavigator *DBn_navigator;
        TLabel *l_profesori;
        TLabel *l_predmeti;
        void __fastcall ProfesoriOnEnter(TObject *Sender);
        void __fastcall PredmetiOnEnter(TObject *Sender);
private:	// User declarations
        TColor tamnoSiva, svijetloSiva, svijetloPlava;
public:		// User declarations
        __fastcall TFormPredmetiIProfesori(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPredmetiIProfesori *FormPredmetiIProfesori;
//---------------------------------------------------------------------------
#endif
