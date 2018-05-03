//---------------------------------------------------------------------------

#ifndef AddingH
#define AddingH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "cspin.h"
#include <ComCtrls.hpp>
#include "ccalendr.h"
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TAdd : public TForm
{
__published:	// IDE-managed Components
	TScrollBox *ScrollBox1;
	TLabel *Label1;
	TButton *BStuff;
	TButton *BActivities;
	TLabel *Label2;
	TComboBox *ComboBox1;
	TCSpinEdit *CSpinEdit1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TComboBox *ComboBox5;
	TButton *BAdd;
	TScrollBox *ScrollBox2;
	TLabel *Label6;
	TComboBox *ComboBox6;
	TMonthCalendar *MonthCalendar1;
	TLabel *Label7;
	TEdit *ECountry;
	TLabel *Label8;
	TEdit *ELocality;
	TLabel *Label9;
	TEdit *EThing;
	TLabel *Label10;
	TEdit *EActivity;
	TLabel *Label11;
	TCSpinEdit *CSpinEdit2;
	void __fastcall BStuffClick(TObject *Sender);
	void __fastcall BActivitiesClick(TObject *Sender);
	void __fastcall BAddClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ECountryExit(TObject *Sender);
	void __fastcall ECountryClick(TObject *Sender);
	void __fastcall ELocalityExit(TObject *Sender);
	void __fastcall ELocalityClick(TObject *Sender);
	void __fastcall EThingExit(TObject *Sender);
	void __fastcall EThingClick(TObject *Sender);
	void __fastcall EActivityClick(TObject *Sender);
	void __fastcall EActivityExit(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAdd(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAdd *Add;
//---------------------------------------------------------------------------
#endif
