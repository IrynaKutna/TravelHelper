//---------------------------------------------------------------------------

#ifndef RemH
#define RemH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cspin.h"
//---------------------------------------------------------------------------
class TMyRemove : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *Button1;
	TCSpinEdit *CSpinEdit1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall CSpinEdit1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMyRemove(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyRemove *MyRemove;
//---------------------------------------------------------------------------
#endif
