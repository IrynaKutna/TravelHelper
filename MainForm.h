//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ExtDlgs.hpp>
#include <Menus.hpp>
#include <Grids.hpp>
#include "cspin.h"
#include "Class.h"
//---------------------------------------------------------------------------
extern vector<CPlace*> vArrayOfPlaces;
extern vector<CPlace*> vArrayToPrint;
extern bool check_for_group_by_purpose;
class TTrips : public TForm
{
__published:	// IDE-managed Components
	TOpenTextFileDialog *OpenTextFileDialog1;
	TSaveTextFileDialog *SaveTextFileDialog1;
	TMainMenu *MainMenu1;
	TMenuItem *N2;
	TMenuItem *Open1;
	TMenuItem *Save1;
	TMenuItem *Edit1;
	TMenuItem *Add1;
	TMenuItem *Remove1;
	TMenuItem *Removeall1;
	TMenuItem *Exit1;
	TMenuItem *N1;
	TMenuItem *N3;
	TStringGrid *StringGrid1;
	TCSpinButton *CSpinButton1;
	TCSpinButton *CSpinButton2;
	TCSpinButton *CSpinButton3;
	TCSpinButton *CSpinButton4;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TCSpinButton *CSpinButton5;
	TMenuItem *N4;
	TMenuItem *Gpoupbypurpose1;
	TMenuItem *Select1;
	TMenuItem *Lastmonth1;
	TMenuItem *Maxdaysoffbypurpose1;
	TMenuItem *Scheduled1;
	TMenuItem *op5mostexpensive1;
	TMenuItem *Print1;
	TMenuItem *Averagedaysoff1;
	TMenuItem *N5;
	void __fastcall Add1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall CSpinButton1DownClick(TObject *Sender);
	void __fastcall CSpinButton2DownClick(TObject *Sender);
	void __fastcall CSpinButton1UpClick(TObject *Sender);
	void __fastcall CSpinButton2UpClick(TObject *Sender);
	void __fastcall CSpinButton3DownClick(TObject *Sender);
	void __fastcall CSpinButton3UpClick(TObject *Sender);
	void __fastcall CSpinButton4DownClick(TObject *Sender);
	void __fastcall CSpinButton4UpClick(TObject *Sender);
	void __fastcall CSpinButton5DownClick(TObject *Sender);
	void __fastcall CSpinButton5UpClick(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall Remove1Click(TObject *Sender);
	void __fastcall Removeall1Click(TObject *Sender);
	void __fastcall Gpoupbypurpose1Click(TObject *Sender);
	void __fastcall Lastmonth1Click(TObject *Sender);
	void __fastcall Maxdaysoffbypurpose1Click(TObject *Sender);
	void __fastcall Scheduled1Click(TObject *Sender);
	void __fastcall op5mostexpensive1Click(TObject *Sender);
	void __fastcall Averagedaysoff1Click(TObject *Sender);
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall Print1Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TTrips(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTrips *Trips;
//---------------------------------------------------------------------------
#endif
