//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#define BUILD_APP
#include "CrossAndNulls.h"

#include "coschd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCrossNullMain *CrossNullMain;
//---------------------------------------------------------------------------
__fastcall TCrossNullMain::TCrossNullMain(TComponent* Owner) : TForm(Owner)
{
     for (int i=0;i<5;i++)
          Manaburn[i] = new Graphics::TBitmap;
     Manaburn[0]->Assign(rdcorner->Picture);
     Manaburn[1]->Assign(lucorner->Picture);
     Manaburn[2]->Assign(upside->Picture);
     Manaburn[4]->Assign(leftside->Picture);
     Manaburn[3]->Assign(center->Picture);
     Field[0]=center;
     Field[1]=leftside;
     Field[2]=lucorner;
     Field[3]=upside;
     Field[4]=rucorner;
     Field[5]=rightside;
     Field[6]=rdcorner;
     Field[7]=downside;
     Field[8]=ldcorner;

     Corner[0]=lucorner;
     Corner[1]=rucorner;
     Corner[2]=rdcorner;
     Corner[3]=ldcorner;
     Side[0]=leftside;
     Side[1]=upside;
     Side[2]=rightside;
     Side[3]=downside;

     for (int i=0;i<9;i++)
     {
          Field[i]->Picture->Assign(Manaburn[0]);
          Pole[i]=0;
     }
     Aschmed[0][0]=&Pole[2];
     Aschmed[0][1]=&Pole[3];
     Aschmed[0][2]=&Pole[4];
     Aschmed[1][0]=&Pole[1];
     Aschmed[1][1]=&Pole[0];
     Aschmed[1][2]=&Pole[5];
     Aschmed[2][0]=&Pole[8];
     Aschmed[2][1]=&Pole[7];
     Aschmed[2][2]=&Pole[6];
     cource=0;
     Table();
     New();
     debug = true;
     if (debug == false)
     {
          CrossNullMain->Height=380;
          //Memo1->Visible=false;
          //StringGrid1->Visible=false;
     }     
     Panel1->Height=288;
     Normal=true;


}
//---------------------------------------------------------------------------

void __fastcall TCrossNullMain::N4Click(TObject *Sender)
{
     New();
}
//---------------------------------------------------------------------------


void __fastcall TCrossNullMain::lucornerClick(TObject *Sender)
{
     //Player((TImage*)Sender);
     if (Tactics == 1)
          Tactics = 2;
     Player(2);
}
//---------------------------------------------------------------------------

void __fastcall TCrossNullMain::upsideClick(TObject *Sender)
{
     Player(3);
}
//---------------------------------------------------------------------------

void __fastcall TCrossNullMain::rucornerClick(TObject *Sender)
{
     if (Tactics == 1)
          Tactics = 2;
     Player(4);
}
//---------------------------------------------------------------------------

void __fastcall TCrossNullMain::leftsideClick(TObject *Sender)
{
     Player(1);
}
//---------------------------------------------------------------------------

void __fastcall TCrossNullMain::centerClick(TObject *Sender)
{
     Player(0);
}
//---------------------------------------------------------------------------

void __fastcall TCrossNullMain::rightsideClick(TObject *Sender)
{
     Player(5);
}
//---------------------------------------------------------------------------

void __fastcall TCrossNullMain::ldcornerClick(TObject *Sender)
{
     if (Tactics == 1)
          Tactics = 2;
     Player(8);
}
//---------------------------------------------------------------------------

void __fastcall TCrossNullMain::downsideClick(TObject *Sender)
{
     Player(7);
}
//---------------------------------------------------------------------------

void __fastcall TCrossNullMain::rdcornerClick(TObject *Sender)
{
     if (Tactics == 1)
          Tactics = 2;
     Player(6);     
}
//---------------------------------------------------------------------------


