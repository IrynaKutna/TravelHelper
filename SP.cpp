//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SP.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainPage *MainPage;
//---------------------------------------------------------------------------
__fastcall TMainPage::TMainPage(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainPage::Button1Click(TObject *Sender)
{
	Application->MainFormOnTaskBar = false;
	Trips->Show();
	MainPage->Hide();
}
//---------------------------------------------------------------------------

