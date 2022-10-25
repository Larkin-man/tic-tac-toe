//---------------------------------------------------------------------------
#include <windows.h>     //надо
#pragma hdrstop
#define BUILD_DLL
#include "CrossAndNulls.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------

//#pragma argsused   //надо
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
   return 1;
}
//---------------------------------------------------------------------------

int Field[10];
int Xo[3][3];
double Koryto;
int step;
bool CompFirst;

enum XOCell2 {Xd, Od, Nonde};

CrossAndNulls::CrossAndNulls()
{
   step = 0;
   for (int i=0; i<XORow; i++)
      for (int j=0; j<XOCol; j++)
         Field[i][j] = Empty;
   //GameOver();
}

void CrossAndNulls::GameOver()
{
   for (int i=0; i<XORow; i++)
      for (int j=0; j<XOCol; j++)
         Field[i][j] = Empty;
}

int CrossAndNulls::Play(unsigned int Now)
{
   if (step == 0)
   {
      if (Now == 0)
         CompFirst == true;
      else
         CompFirst == false;
   }
   return 0;
}

int Random(const int &min,const int &max)
{
     srand(time(NULL));
     //double randomize = rand()+mouse.x+mouse.y;
     return (int(randomize) % (max-min+1)) +min;
}

int random(const int& min, const int& max)
{    //От мин до макс включительно
     srand(time(NULL));   //рандомизация называется. Типа зерно задаем
     return (min + rand() % (max+1-min));
}

int randomArround(const int& center, const int& size)
{    //Около центра в обласи сайз
     srand(time(NULL));
     return (center - size + rand() % (size*2+1));
}

int Event(const int &n, int *chance)
{
   int Max=0;
   for (int i=0;i<n;i++)
      Max+=chance[i];
   int ev = Random(1,Max);
   Max=0;
   int j;
   for (j=0; j<n; j++)
   {
      Max+=chance[j];
      if (ev <= Max)
      {
           break;
      }
   }
   return j;
}
