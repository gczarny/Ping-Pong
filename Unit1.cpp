//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int xPos = 6, yPos = 6;
int victoriesP1 = 0, victoriesP2 = 0;
int ballBounces = 0;
const int speedInkr = 2;
char player = '1';
bool gameStarted = false;
int turn = 0;
int score = 0;

void incrementSpeed(int bBounces)
{
    if(bBounces > 0 && bBounces % 6 == 0)
    {
        xPos += speedInkr;
        yPos += speedInkr;
    }
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    if(gameStarted == false)
    {
        ShowMessage("Witaj w grze Ping-Pong!\n"
                "Lewy gracz steruje wciskaj�c klawisze A i Z\n"
                "Prawy gracz steruje wciskaj�c strza�ki g�ra/d� \n\n"
                "Mo�esz dowolnie zmienia� pole gry.\n"
                "Im d�u�ej odbijasz pi�k�, tym szybciej zacznie si� przemieszcza�.\n\n"
                "Mi�ej zabawy!");
    }
    else
    {
        ball->Left = 468;
        ball->Top = 124;
        paddleP1->Top = 160;
        paddleP2->Top = 160;
        ballTimer->Enabled = true;
        ball->Visible = true;
        newGameButton->Visible = false;
        bouncesNumberLabel->Visible = false;
        nextTurnButton->Visible = false;
        scoreLabel->Visible = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ballTimerTimer(TObject *Sender)
{
    if(gameStarted == true)
    {
        ball->Left += xPos;
        ball->Top += yPos;

        //bounce from the bottom edge
        if(ball->Top + ball->Height + 5 >= background->Height)
                yPos = -yPos;

        //bounce from the top edge
        if(ball->Top - 5 <= background->Top)
                yPos = -yPos;

        //hit the paddle 1
        if(ball->Top + ball->Height/2 >= paddleP1->Top                    &&
           ball->Top - ball->Height/2 <= paddleP1->Top + paddleP1->Height &&
           ball->Left < paddleP1->Left + paddleP1->Width)
        {
            player = '1';
            xPos = -xPos;
            ballBounces++;
            incrementSpeed(ballBounces);
        }

        //hit the paddle 2
        if(ball->Top + ball->Height/2 >= paddleP2->Top   &&
           ball->Top - ball->Height/2 <= paddleP2->Top + paddleP2->Height &&
           ball->Left + ball->Width > paddleP2->Left)
        {
            player = '2';
            xPos = -xPos;
            ballBounces++;
            incrementSpeed(ballBounces);
        }

        //miss the paddle
        if(ball->Left + ball->Width < paddleP1->Left ||
                ball->Left > paddleP2->Left + paddleP2->Width)
        {
            ballTimer->Enabled = false;
            ball->Visible = false;
            if(player == '2')
                 victoriesP2++;
            else if(player == '1')
                 victoriesP1++;
            newGameButton->Visible = true;
            nextTurnButton->Visible = true;
            bouncesNumberLabel->Visible = true;
            bouncesNumberLabel->Caption = "Ilo�� odbi�: " + IntToStr(ballBounces);
            scoreLabel->Visible = true;
            scoreLabel->Caption = IntToStr(victoriesP1) + " : " + IntToStr(victoriesP2);
        }
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
void __fastcall TForm1::newGameButtonClick(TObject *Sender)
{
    if(gameStarted == false)
    {
        newGameButton->Visible = false;
        letsPlayLabel->Visible = false;
    }
    else
    {
        if( Application->MessageBox("Jeste� pewien, �e chcesz rozpocz� now� gr�? "
                                    "utracisz zapisany stan gry.", "Potwierd�",
                                    MB_YESNO) == IDYES)
        {
            victoriesP1 = 0;
            victoriesP2 = 0;
            ballBounces = 0;
            xPos = -6;
            yPos = -6;
            turn = 0;
            FormCreate(Sender);
        }
    }
    gameStarted = true;
}
//---------------------------------------------------------------------------

