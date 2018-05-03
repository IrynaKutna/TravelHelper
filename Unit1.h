//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TInfo : public TForm
{
__published:	// IDE-managed Components
	TTreeView *TreeView1;
	TMemo *Memo1;
	void __fastcall TreeView1Change(TObject *Sender, TTreeNode *Node);
private:	// User declarations
public:		// User declarations
	__fastcall TInfo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInfo *Info;
//---------------------------------------------------------------------------
#endif
