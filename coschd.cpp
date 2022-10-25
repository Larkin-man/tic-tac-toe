//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "coschd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Field.LU = X;
	Field.U = X;
	Field.RU = X;
	Field.RD = O;
	Field.LD = O;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			Memo1->Lines->Add(IntToStr(i)+":"+IntToStr(j)+"="+IntToStr(Field.Cell[i][j]));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	for (int i = 0; i < 10; ++i)
	{
		R.OR = i;
		
		Memo1->Lines->Add(IntToStr(i)+":"+IntToStr(int((R.OR+R.NRU))));
	
	}
	
}
//---------------------------------------------------------------------------
