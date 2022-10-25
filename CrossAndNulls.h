//---------------------------------------------------------------------------

#ifndef CrossAndNullsH
#define CrossAndNullsH
//---------------------------------------------------------------------------
#if defined(BUILD_DLL)
#  define DLL_EXP __declspec(dllexport)
#else
#  if defined(BUILD_APP)
#     define DLL_EXP __declspec(dllimport)
#  else
#     define DLL_EXP
#  endif
#endif

enum XOCell {X, O, Empty};
const int XORow = 3;
const int XOCol = 3;

class DLL_EXP CrossAndNulls
{
private:
   union
   {
      XOCell Field[XORow][XOCol];
      struct
      {
         XOCell LU, U, RU;
         XOCell L, C, R;
         XOCell LD, D, RD;
      };
   };

public:
   int Play(unsigned int Now);
   void GameOver();
   void Seed(int &seed);
   CrossAndNulls();
};

#endif
