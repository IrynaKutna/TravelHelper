//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rem.h"
#include "MainForm.h"
#include "Class.h"
#include "Adding.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TMyRemove *MyRemove;
bool check_for_remove;
bool check_for_edit;
//---------------------------------------------------------------------------
__fastcall TMyRemove::TMyRemove(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMyRemove::Button1Click(TObject *Sender)
{
	vArrayOfPlaces.erase(vArrayOfPlaces.begin() + CSpinEdit1->Value - 1);
	MyPrint(Trips->StringGrid1, vArrayOfPlaces);
	MyRemove->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMyRemove::CSpinEdit1Change(TObject *Sender)
{
	CSpinEdit1->MaxValue = vArrayOfPlaces.size();
	CSpinEdit1->MinValue = 1;
}
//---------------------------------------------------------------------------
