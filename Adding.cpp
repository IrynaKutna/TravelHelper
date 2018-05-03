//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Adding.h"
#include "SP.h"
#include "MainForm.h"
#include "Class.h"
#include <cstring>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma link "ccalendr"
#pragma resource "*.dfm"
TAdd *Add;
vector<CPlace*> vArrayOfPlaces;
vector<CPlace*> vArrayToPrint;
map<string, bool> mThings;
map<string, bool> mActivities;
unsigned int CPlace::scObjects = 0;
int counter = 0, counter2 = 0;
//---------------------------------------------------------------------------
__fastcall TAdd::TAdd(TComponent* Owner)
	: TForm(Owner)
{
}
void __fastcall TAdd::BStuffClick(TObject *Sender)
{
	if(EThing->Text.IsEmpty() == false){
		TCheckBox* CBActivity = new TCheckBox(this);
		CBActivity->Height = 20;
		CBActivity->Width = 100;
		CBActivity->Left = 15;
		CBActivity->Top = 5 + counter * 20;
		CBActivity->Caption = EThing->Text;
		CBActivity->Visible = true;
		CBActivity->Enabled = true;
		CBActivity->Parent = ScrollBox1;
		ScrollBox1->InsertComponent(CBActivity);
		++counter;
		string temp = AnsiString(EThing->Text).c_str();
		mThings.insert(pair<string, bool>(temp, CBActivity->Checked));
	} else{
		EThing->TextHint = "Введіть текст!";
	}
	EThing->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TAdd::BActivitiesClick(TObject *Sender)
{
	if(EActivity->Text.IsEmpty() == false){
		TCheckBox* CBActivity = new TCheckBox(this);
		CBActivity->Height = 20;
		CBActivity->Width = 100;
		CBActivity->Left = 15;
		CBActivity->Top = 5 + counter2 * 20;
		CBActivity->Caption = EActivity->Text;
		CBActivity->Visible = true;
		CBActivity->Enabled = true;
		CBActivity->Parent = ScrollBox2;
		ScrollBox2->InsertComponent(CBActivity);
		++counter2;
		string temp = AnsiString(EActivity->Text).c_str();
		mActivities.insert(pair<string, bool>(temp, CBActivity->Checked));
	} else{
		EActivity->TextHint = "Введіть текст!";
	}
	EActivity->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TAdd::BAddClick(TObject *Sender)
{
	CPlace *Obj = new CPlace;
	//Country
	if(ECountry->Text.IsEmpty() == false){
		Obj->SetCountry(AnsiString(ECountry->Text).c_str());
	} else{
		ECountry->TextHint = "Введіть текст!";
		return;
	}
	//Locality
	if(ELocality->Text.IsEmpty() == false){
		Obj->SetLocality(AnsiString(ELocality->Text).c_str());
	} else{
		ELocality->TextHint = "Введіть текст!";
		return;
	}
	//Date
	struct Date date;
	string str = AnsiString(DateToStr(MonthCalendar1->Date)).c_str();
	string temp = "";
	temp[0] = str[0];
	temp[1] = str[1];
	date.uiDay = atoi(temp.c_str());
	temp[0] = str[3];
	temp[1] = str[4];
	date.uiMonth = atoi(temp.c_str());
	temp[0] = str[6];
	temp[1] = str[7];
	temp[2] = str[8];
	temp[3] = str[9];
	date.uiYear = atoi(temp.c_str());
	Obj->SetDate(date);
	//Days off
	Obj->SetDaysOff(CSpinEdit1->Value);
	//Money
	Obj->SetMoney(CSpinEdit2->Value);
	//Purpose
	Obj->SetPurpose(UnicodeToPurpose(ComboBox5->Text));
	//Status
	struct Date today;
	str = "";
	str = AnsiString(DateToStr(Now().DateString())).c_str();
	string temp2 = "";
	temp2[0] = str[0];
	temp2[1] = str[1];
	today.uiDay = atoi(temp2.c_str());
	temp2[0] = str[3];
	temp2[1] = str[4];
	today.uiMonth = atoi(temp2.c_str());
	temp2[0] = str[6];
	temp2[1] = str[7];
	temp2[2] = str[8];
	temp2[3] = str[9];
	today.uiYear = atoi(temp2.c_str());
	if(DateToDays(today) < DateToDays(date))
		Obj->SetStatus(Scheduled);
	else if(DateToDays(today) >= DateToDays(date) && DateToDays(today) <= (DateToDays(date) + Obj->GetDaysOff() - 1))
		Obj->SetStatus(InProgress);
	else
		Obj->SetStatus(Done);

	//stuff
	Obj->SetStuff(mThings);

	//activities
	Obj->SetActivities(mActivities);

	vArrayOfPlaces.push_back(Obj);

	//Exit form
	Trips->Show();
	Add->Close();
	vArrayToPrint.clear();
	for(int i = 0; i < vArrayOfPlaces.size(); ++i){
		vArrayToPrint.push_back(vArrayOfPlaces[i]);
	}
	MyPrint(Trips->StringGrid1, vArrayToPrint);

}
//---------------------------------------------------------------------------

void __fastcall TAdd::FormClose(TObject *Sender, TCloseAction &Action)
{
	Trips->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TAdd::ECountryExit(TObject *Sender)
{
	try{
		IsNotLetter(ECountry);
	} catch(Exceptions::FirstCharacterIsLowercase){
		ShowMessage("Назва має починатись із великої літери!");
		ECountry->Text = "";
		ECountry->Color = clRed;
	} catch(Exceptions::UppercaseLetter){
		ShowMessage("Лише перша літера має бути велика!");
		ECountry->Text = "";
		ECountry->Color = clRed;
	} catch(Exceptions::InappropriateCharacter){
		ShowMessage("Назва має складатись лише з літер!");
		ECountry->Text = "";
		ECountry->Color = clRed;
	}
}
//---------------------------------------------------------------------------
void __fastcall TAdd::ECountryClick(TObject *Sender)
{
	ECountry->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TAdd::ELocalityExit(TObject *Sender)
{
	try{
		IsNotLetter(ELocality);
	} catch(Exceptions::FirstCharacterIsLowercase){
		ShowMessage("Назва має починатись із великої літери!");
		ELocality->Text = "";
		ELocality->Color = clRed;
	} catch(Exceptions::UppercaseLetter){
		ShowMessage("Лише перша літера має бути велика!");
		ELocality->Text = "";
		ELocality->Color = clRed;
	} catch(Exceptions::InappropriateCharacter){
		ShowMessage("Назва має складатись лише з літер!");
		ELocality->Text = "";
		ELocality->Color = clRed;
	}
}
//---------------------------------------------------------------------------

void __fastcall TAdd::ELocalityClick(TObject *Sender)
{
	ELocality->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TAdd::EThingExit(TObject *Sender)
{
	try{
		IsNotLetter(EThing);
	} catch(Exceptions::FirstCharacterIsLowercase){
		ShowMessage("Назва має починатись із великої літери!");
		EThing->Text = "";
		EThing->Color = clRed;
	} catch(Exceptions::UppercaseLetter){
		ShowMessage("Лише перша літера має бути велика!");
		EThing->Text = "";
		EThing->Color = clRed;
	} catch(Exceptions::InappropriateCharacter){
		ShowMessage("Назва має складатись лише з літер!");
		EThing->Text = "";
		EThing->Color = clRed;
	}
}
//---------------------------------------------------------------------------

void __fastcall TAdd::EThingClick(TObject *Sender)
{
	EThing->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TAdd::EActivityClick(TObject *Sender)
{
	EActivity->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TAdd::EActivityExit(TObject *Sender)
{
	try{
		IsNotLetter(EActivity);
	} catch(Exceptions::FirstCharacterIsLowercase){
		ShowMessage("Назва має починатись із великої літери!");
		EActivity->Text = "";
		EActivity->Color = clRed;
	} catch(Exceptions::UppercaseLetter){
		ShowMessage("Лише перша літера має бути велика!");
		EActivity->Text = "";
		EActivity->Color = clRed;
	} catch(Exceptions::InappropriateCharacter){
		ShowMessage("Назва має складатись лише з літер!");
		EActivity->Text = "";
		EActivity->Color = clRed;
	}
}
//---------------------------------------------------------------------------


void __fastcall TAdd::FormShow(TObject *Sender)
{
	ECountry->Clear();
	ELocality->Clear();
	MonthCalendar1->Date = Now();
	CSpinEdit1->Value = 1;
	CSpinEdit2->Value = 100;
	ComboBox1->Text = "Робота";
	mThings.clear();
	mActivities.clear();
}
//---------------------------------------------------------------------------

