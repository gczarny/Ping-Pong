//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int xPos = -8, yPos = -8;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ballTimerTimer(TObject *Sender)
{
    ball->Left += xPos;
    ball->Top += yPos;

    //bounce from the bottom edge
    if(ball->Top + ball->Height + 5 >= background->Height)
        yPos = -yPos;

    //bounce from the top edge
    if(ball->Top - 5 <= background->Top)
        yPos = -yPos;

    //miss the paddle
    if(ball->Left < paddleP1->Left ||
       ball->Left + ball->Width > paddleP2->Left)
    {
        ballTimer->Enabled = false;
        ball->Visible = false;


    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::upP1Timer(TObject *Sender)
{
    paddleP1->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::downP1Timer(TObject *Sender)
{
    paddleP1->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::upP2Timer(TObject *Sender)
{
    paddleP2->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::downP2Timer(TObject *Sender)
{
    paddleP2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == 65) upP1->Enabled = true;
    if(Key == 90) downP1->Enabled = true;
    if(Key == VK_UP) upP2->Enabled = true;
    if(Key == VK_DOWN) downP2->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == 65) upP1->Enabled = false;
    if(Key == 90) downP1->Enabled = false;
    if(Key == VK_UP) upP2->Enabled = false;
    if(Key == VK_DOWN) downP2->Enabled = false;
}
//---------------------------------------------------------------------------

