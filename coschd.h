//---------------------------------------------------------------------------

#ifndef coschdH
#define coschdH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <time.h>
#include <stdlib.h>
//---------------------------------------------------------------------------
class TCrossNullMain : public TForm
{
__published:	// IDE-managed Components
     TPanel *Panel1;
     TImage *Image1;
     TImage *lucorner;
     TImage *Image3;
     TImage *Image4;
     TImage *rucorner;
     TImage *upside;
     TImage *Image8;
     TImage *leftside;
     TImage *Image10;
     TImage *Image11;
     TImage *Image12;
     TImage *center;
     TImage *rightside;
     TImage *ldcorner;
     TImage *downside;
     TImage *rdcorner;
     TMainMenu *MainMenu1;
     TMenuItem *N1;
     TMenuItem *N2;
     TMenuItem *N3;
     TImageList *CR;
     TMenuItem *N4;
   TImage *Image2;
     void __fastcall N4Click(TObject *Sender);
     void __fastcall lucornerClick(TObject *Sender);
     void __fastcall upsideClick(TObject *Sender);
     void __fastcall rucornerClick(TObject *Sender);
     void __fastcall leftsideClick(TObject *Sender);
     void __fastcall centerClick(TObject *Sender);
     void __fastcall rightsideClick(TObject *Sender);
     void __fastcall ldcornerClick(TObject *Sender);
     void __fastcall downsideClick(TObject *Sender);
     void __fastcall rdcornerClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
     __fastcall TCrossNullMain(TComponent* Owner);
     Graphics::TBitmap *Manaburn[5];
     TImage *Field[9];
     TImage *Corner[4];
     TImage *Side[4];
     int Pole[9];
     int *Aschmed[3][3];
     int cource;
     bool compfirst;
     int xo;
     bool debug;
     int Tactics;
     bool Normal;
     int *board[9];

int Random(const int &min,const int &max)
{
     srand(time(NULL));
          TPoint mouse;
          GetCursorPos(&mouse);
          double randomize = rand()+mouse.x+mouse.y;
          return (int(randomize) % (max-min+1)) +min;   
}

int Event(int n, int *chance)
{
          int Max=0;
          for (int i=0;i<n;i++)
               Max+=chance[i];
          int ev = Random(1,Max);

          Max=0;
          int j;
          for (j=0;j<n;j++)
          {
               Max+=chance[j];
               if (ev <= Max)
               {
                    break;
               }
          }
          //StatusBar1->Panels->Items[0]->Text=IntToStr(ev)+IntToStr(j);
          return j;
}


void CompX()
{
     int P[3];
     P[0]=2;
     P[1]=2;
     P[2]=1;
     int xod = Event(3,P);
             //  xod=0;
     switch (xod)
     {
          case 0:
          {
               //StatusBar1->Panels->Items[0]->Text="center";
               Field[0]->Picture->Assign(Manaburn[xo+1]);
               Pole[0]=-1;
               Tactics=1;
               break;
          }
          case 1:
          {
               //StatusBar1->Panels->Items[0]->Text="corner";
               CompCorner();
               break;
          }
          case 2:
          {
               //StatusBar1->Panels->Items[0]->Text="side";
               CompSide();
               break;
          }
     }
     cource++;
     Table();
}

void CompCorner()
{
     int Xod = Random(0,3);
     Corner[Xod]->Picture->Assign(Manaburn[xo+1]);
     Pole[(Xod+1)*2]=-1;
}

void CompSide()
{
     int Xod = Random(0,3);
     Side[Xod]->Picture->Assign(Manaburn[xo+1]);
     Pole[Xod*2+1]=-1;
}

void Player(int num)
{
     if (cource >= 9)
     {
          New();
          return;
     }
     if(Pole[num] != 0 )  //Comp
     {           
          return;
     }
     Pole[num]=1;
     Field[num]->Picture->Assign(Manaburn[xo]);
     //Memo1->Lines->Add("Player->"+IntToStr(num));
     Table();
     cource++;
     for(int row=0;row<3;row++)
          if ((*Aschmed[row][0]+*Aschmed[row][1]+*Aschmed[row][2]) == 3)
          {
               ShowMessage("Победа!");
               cource=9;
               return;
          }
     for(int col=0;col<3;col++)
          if ((*Aschmed[0][col]+*Aschmed[1][col]+*Aschmed[2][col]) == 3)
          {
               ShowMessage("Победа!");
               cource=9;
               return;
          }

     if (*Aschmed[0][0]+*Aschmed[1][1]+*Aschmed[2][2] == 3)
     {
               ShowMessage("Победа!");
               cource=9;
               return;
          }
     if (*Aschmed[0][2]+*Aschmed[1][1]+*Aschmed[2][0] == 3)
     {
               ShowMessage("Победа!");
               cource=9;
               return;
          }
     if (Normal)
          TacticsRun();
     CompRun();
}

void New()
{
     for (int i=0;i<9;i++)
     {
          Field[i]->Picture->Assign(Manaburn[0]);
          Pole[i]=0;
     }
     Table();
     cource=0;
     compfirst=!compfirst;
     for(int i=0;i<9;i++)
          board[i]=&Pole[i];
     Tactics=0;

     if (compfirst)
     {
          xo=1;
          CompX();
     }
     else
          xo=3;}

void CompRun()
{                
     if (cource >= 9)
          return;
     //SEARCH COMP X
      cource++;
     for(int row=0;row<3;row++)
     {
          if ((*Aschmed[row][0]+*Aschmed[row][1]+*Aschmed[row][2]) == (-2))
          {
               for(int i=0;i<3;i++)
               {
                    if (*Aschmed[row][i] == 0)
                    {
                         *Aschmed[row][i]=-10;
                         //Memo1->Lines->Add("row="+IntToStr(row));
                         Defeat(true);
                         return;
                    }
               }
          }
     }

     for(int col=0;col<3;col++) //SEARCH COMP IN COLUMN
          if ((*Aschmed[0][col]+*Aschmed[1][col]+*Aschmed[2][col]) == (-2))
               for(int i=0;i<3;i++)
                    if (*Aschmed[i][col] == 0)
                    {
                         *Aschmed[i][col]=-10;
                         //Memo1->Lines->Add("col="+IntToStr(col));
                         Defeat(true);
                         return;
                    }

     //SEARCH COMP IN DIAGONAL \\
     //ShowMessage("Diagonal \="+IntToStr(*Aschmed[0][0]+*Aschmed[1][1]+*Aschmed[2][2]));
     if (*Aschmed[0][0]+*Aschmed[1][1]+*Aschmed[2][2] == -2)
          for(int i=0;i<3;i++)
               if (*Aschmed[i][i] == 0)
                    {
                         *Aschmed[i][i]=-10;
                         //Memo1->Lines->Add("diag\\");
                         Defeat(true);
                         return;
                    }

      //SEARCH COMP IN DIAGONAL /
     //ShowMessage("Diagonal /="+IntToStr(*Aschmed[0][2]+*Aschmed[1][1]+*Aschmed[2][0]));
     if (*Aschmed[0][2]+*Aschmed[1][1]+*Aschmed[2][0] == -2)
          for(int i=0;i<3;i++)
               if (*Aschmed[i][2-i] == 0)
                    {
                         *Aschmed[i][2-i]=-10;
                         //Memo1->Lines->Add("diag /");
                         Defeat(true);
                         return;
                    }


     //SEARCH PLAYER IN ROWS
     for(int row=0;row<3;row++)
          if ((*Aschmed[row][0]+*Aschmed[row][1]+*Aschmed[row][2]) == 2)
               for(int i=0;i<3;i++)
                    if (*Aschmed[row][i] == 0)
                    {
                         *Aschmed[row][i]=-10;
                         Defeat(false);
                         return;
                    }
     //SEARCH PLAYER IN COLUMNS
     for(int col=0;col<3;col++)
          if ((*Aschmed[0][col]+*Aschmed[1][col]+*Aschmed[2][col]) == 2)
               for(int i=0;i<3;i++)
                    if (*Aschmed[i][col] == 0)
                    {
                         *Aschmed[i][col]=-10;
                         Defeat(false);
                         return;
                    }


//SEARCH PLAYER IN DIAGONAL \\
     if (*Aschmed[0][0]+*Aschmed[1][1]+*Aschmed[2][2] == 2)
          for(int i=0;i<3;i++)
               if (*Aschmed[i][i] == 0)
                    {
                         *Aschmed[i][i]=-10;
                         Defeat(false);
                         return;
                    }

      //SEARCH PLAYER IN DIAGONAL /
     if (*Aschmed[0][2]+*Aschmed[1][1]+*Aschmed[2][0] == 2)
          for(int i=0;i<3;i++)
               if (*Aschmed[i][2-i] == 0)
                    {
                         *Aschmed[i][2-i]=-10;
                         Defeat(false);
                         return;
                    }




     if (Pole[0] == 0) //TO CENTER
          {
               Pole[0]=-1;
               Field[0]->Picture->Assign(Manaburn[xo+1]);
               //Memo1->Lines->Add("COMP->CENTER");
               Table();
               return;
          }

     int free[9];
     free[0]=0;
     for (int i=1;i<9;i++)
          if (Pole[i]==0)
          {
               free[0]++;
               free[free[0]]=i;
          }

     int rnd=Random(1,free[0]);
     //Memo1->Lines->Add("Free0="+IntToStr(free[0])+" rand="+IntToStr(rnd));
     Pole[free[rnd]]=-1;
     Field[free[rnd]]->Picture->Assign(Manaburn[xo+1]);
     Table();
     return;   
     
}

void Table()
{
     for(int i=0;i<3;i++)
          for(int j=0;j<3;j++)
          {
               //StringGrid1->Cells[j][i]=IntToStr(*Aschmed[i][j]);
          }
}

void Defeat(bool arm=false)
{
     for (int j=0;j<9;j++)
          if (Pole[j]==-10)
               {
                    Pole[j]=-1;
                    Field[j]->Picture->Assign(Manaburn[xo+1]);
                    if (arm)
                    {
                         ShowMessage("Поражение!");
                         cource=9;
                    }
                    return;
               }
}

void TacticsRun()
{
     //Memo1->Lines->Add("Tactics="+IntToStr(Tactics));
     if (Tactics == 2)
     {
          //Memo1->Lines->Add("*board8="+IntToStr(*board[8]));
          //while(*board[8]!=1)
          //{
          //     Rotate();

          //}
          
     }
}

void Rotate()
{
     TImage *temp;
     temp=Corner[0];
     Corner[0]=Corner[1];
     Corner[1]=Corner[2];
     Corner[2]=Corner[3];
     Corner[3]=temp;
     temp=Side[0];
     Side[0]=Side[1];
     Side[1]=Side[2];
     Side[2]=Side[3];
     Side[3]=temp;
     
     int *itemp[2];
     itemp[0]=board[1];
     itemp[1]=board[2];
     for (int i=1;i<7;i++)
          board[i]=board[i+2];
     board[7]=itemp[0];
     board[8]=itemp[1];
     //Memo1->Lines->Add("Rotate");
}
};
//---------------------------------------------------------------------------
extern PACKAGE TCrossNullMain *CrossNullMain;
//---------------------------------------------------------------------------
#endif
