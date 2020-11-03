//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *paddleP2;
        TImage *ball;
        TImage *paddleP1;
        TShape *background;
        TTimer *upP2;
        TTimer *downP1;
        TTimer *upP1;
        TTimer *downP2;
        TTimer *ballTimer;
        void __fastcall ballTimerTimer(TObject *Sender);
        void __fastcall upP1Timer(TObject *Sender);
        void __fastcall downP1Timer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall upP2Timer(TObject *Sender);
        void __fastcall downP2Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
