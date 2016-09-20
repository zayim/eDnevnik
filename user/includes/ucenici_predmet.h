//---------------------------------------------------------------------------

#ifndef ucenici_predmetH
#define ucenici_predmetH
#include <vcl.h>
//---------------------------------------------------------------------------
class UcenikPredmet
{
        int id_predmeta;
        int id_ucenika;
        int id_zadace;
        int status_zadace;
        int rb;
        AnsiString ime_ucenika;
        AnsiString prezime_ucenika;

        TLabel *l_ime,*l_preuzmiZadacu, *l_dodajOcjenu;
        TColor tamnoSiva, svijetloSiva, svijetloPlava;

        static const int VISINA_PX=50;
        static const int SIRINA_IME_PX=365;
        static const int SIRINA_PREUZMI_ZADACU_PX=165;
        static const int SIRINA_DODAJ_OCJENU_PX=165;
        static const int POZICIJA_IME_PX=15;
        static const int POZICIJA_PREUZMI_ZADACU_PX=450;
        static const int POZICIJA_DODAJ_OCJENU_PX=580;

        void __fastcall PreuzmiZadacuOnClick(TObject *Sender);
        void __fastcall DodajOcjenuOnClick(TObject *Sender);

        public:
        UcenikPredmet(int idpr, int iduc, int idz, int sz, int rb, const AnsiString &im, const AnsiString &pr, TWinControl* roditelj);
        ~UcenikPredmet();
};
#endif
