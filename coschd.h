//---------------------------------------------------------------------------

#ifndef XOMainH
#define XOMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------

enum XOCell {X=-1, E=0, O=1};
const int ROW = 3;
const int COL = 3;

union
{
	XOCell Cell[ROW][COL];
	struct
	{
		XOCell LU; 	XOCell U; 	XOCell RU;
		XOCell L; 	XOCell C; 	XOCell R;
		XOCell LD; 	XOCell D; 	XOCell RD;
   };
} Field;

struct Orientation
{
	const unsigned int NLU : 2;
	const unsigned int NRU : 2;
	const unsigned int NRD : 2;
	const unsigned int NLD : 2;
	unsigned int OR : 2;
	Orientation() : NLU(0), NRU(1), NRD(2), NLD(3)
	{
		OR = 0;
		Corner[0] = &Field.LU;
		Corner[1] = &Field.RU;
		Corner[2] = &Field.RD;
		Corner[3] = &Field.LD;
	}
	XOCell& Corner[4];
	//XOCell& Side[2];
	XOCell* GetLU()
	{
		return Corner[OR+NLU];
   }
	__property XOCell* cLU = {read=GetLU};


} R;



int ToXOCEll(XOCell cell)
{
	if (cell == X) return -1;
	if (cell == O) return 1;
	return 0;
}


class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TButton *Button1;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
