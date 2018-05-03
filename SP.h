//---------------------------------------------------------------------------

#ifndef SPH
#define SPH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TMainPage : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TImage *Image1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainPage *MainPage;
//---------------------------------------------------------------------------
#endif
