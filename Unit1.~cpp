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
    if(ball->Left + ball->Width < paddleP1->Left ||
       ball->Left > paddleP2->Left + paddleP2->Width)
    {
        ballTimer->Enabled = false;
        ball->Visible = false;
    }
    //hit the paddle 1
    else if(ball->Top + ball->Height/2 >= paddleP1->Top - ball->Height/2 &&
            ball->Top <= paddleP1->Top + paddleP1->Height - ball->Height/2 &&
            ball->Left == paddleP1->Left + paddleP1->Width)
    {
         xPos = -xPos;
    }

    //hit the paddle 2
    else if(ball->Top + ball->Height/2 >= paddleP2->Top - ball->Height/2 &&
            ball->Top <= paddleP2->Top + paddleP2->Height - ball->Height/2 &&
            ball->Left + ball->Width > paddleP2->Left)
    {
         xPos = -xPos;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::upP1Timer(TObject *Sender)
{
    if(paddleP1->Top > 10)
        paddleP1->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::downP1Timer(TObject *Sender)
{
    if(paddleP1->Top + paddleP1->Height < background->Height - 10)
        paddleP1->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::upP2Timer(TObject *Sender)
{
    if(paddleP2->Top > 10)
        paddleP2->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::downP2Timer(TObject *Sender)
{
    if(paddleP2->Top + paddleP2->Height < background->Height - 10)
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

