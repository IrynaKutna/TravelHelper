//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "SP.h"
#include "Adding.h"
#include "Class.h"
#include "Rem.h"
#include "Unit1.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TTrips *Trips;
bool check_for_group_by_purpose = true;
vector< vector<CPlace*> > vArrays;
//---------------------------------------------------------------------------
__fastcall TTrips::TTrips(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTrips::Add1Click(TObject *Sender)
{
	Trips->Enabled = false;
	Add->Show();
	Add->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TTrips::FormCreate(TObject *Sender)
{
	StringGrid1->Cells[0][0] = "№";
	StringGrid1->Cells[1][0] = "Країна";
	StringGrid1->Cells[2][0] = "Місто";
	StringGrid1->Cells[3][0] = "Дата";
	StringGrid1->Cells[4][0] = "Тривалість";
	StringGrid1->Cells[5][0] = "Бюджет";
	StringGrid1->Cells[6][0] = "Ціль";
	StringGrid1->Cells[7][0] = "Статус";
}
//---------------------------------------------------------------------------
void __fastcall TTrips::FormClose(TObject *Sender, TCloseAction &Action)
{
	MainPage->Close();
}
//---------------------------------------------------------------------------
void __fastcall TTrips::CSpinButton1DownClick(TObject *Sender)
{
	if(check_for_group_by_purpose == false){
	   for(int i = 0; i < 4; ++i){
		SortByCountryDescending(vArrays[i]);
	   }
	   for(int i = 0, k = 0; i < 4; ++i){
			for(int j = 0; j < vArrays[i].size(); ++j){
				vArrayToPrint[k++] = vArrays[i][j];
			}
	   }
	}else{
		SortByCountryDescending(vArrayToPrint);
	}
	MyPrint(StringGrid1, vArrayToPrint);
}
//---------------------------------------------------------------------------

void __fastcall TTrips::CSpinButton2DownClick(TObject *Sender)
{
	if(check_for_group_by_purpose == false){
	   for(int i = 0; i < 4; ++i){
		SortByLocalityDescending(vArrays[i]);
	   }
	   for(int i = 0, k = 0; i < 4; ++i){
			for(int j = 0; j < vArrays[i].size(); ++j){
				vArrayToPrint[k++] = vArrays[i][j];
			}
	   }
	}else{
		SortByLocalityDescending(vArrayToPrint);
	}
	MyPrint(StringGrid1, vArrayToPrint);
}
//---------------------------------------------------------------------------

void __fastcall TTrips::CSpinButton1UpClick(TObject *Sender)
{
	if(check_for_group_by_purpose == false){
	   for(int i = 0; i < 4; ++i){
		SortByCountryAscending(vArrays[i]);
	   }
	   for(int i = 0, k = 0; i < 4; ++i){
			for(int j = 0; j < vArrays[i].size(); ++j){
				vArrayToPrint[k++] = vArrays[i][j];
			}
	   }
	}else{
		SortByCountryAscending(vArrayToPrint);
	}
	MyPrint(StringGrid1, vArrayToPrint);
}
//---------------------------------------------------------------------------

void __fastcall TTrips::CSpinButton2UpClick(TObject *Sender)
{
	if(check_for_group_by_purpose == false){
	   for(int i = 0; i < 4; ++i){
		SortByLocalityAscending(vArrays[i]);
	   }
	   for(int i = 0, k = 0; i < 4; ++i){
			for(int j = 0; j < vArrays[i].size(); ++j){
				vArrayToPrint[k++] = vArrays[i][j];
			}
	   }
	}else{
		SortByLocalityAscending(vArrayToPrint);
	}
	MyPrint(StringGrid1, vArrayToPrint);
}
//---------------------------------------------------------------------------

void __fastcall TTrips::CSpinButton3DownClick(TObject *Sender)
{
	if(check_for_group_by_purpose == false){
	   for(int i = 0; i < 4; ++i){
		SortByDateDescending(vArrays[i]);
	   }
	   for(int i = 0, k = 0; i < 4; ++i){
			for(int j = 0; j < vArrays[i].size(); ++j){
				vArrayToPrint[k++] = vArrays[i][j];
			}
	   }
	}else{
		SortByDateDescending(vArrayToPrint);
	}
	MyPrint(StringGrid1, vArrayToPrint);
}
//---------------------------------------------------------------------------

void __fastcall TTrips::CSpinButton3UpClick(TObject *Sender)
{
	if(check_for_group_by_purpose == false){
	   for(int i = 0; i < 4; ++i){
		SortByDateAscending(vArrays[i]);
	   }
	   for(int i = 0, k = 0; i < 4; ++i){
			for(int j = 0; j < vArrays[i].size(); ++j){
				vArrayToPrint[k++] = vArrays[i][j];
			}
	   }
	}else{
		SortByDateAscending(vArrayToPrint);
	}
	MyPrint(StringGrid1, vArrayToPrint);
}
//---------------------------------------------------------------------------

void __fastcall TTrips::CSpinButton4DownClick(TObject *Sender)
{
	if(check_for_group_by_purpose == false){
	   for(int i = 0; i < 4; ++i){
		SortByDaysOffDescending(vArrays[i]);
	   }
	   for(int i = 0, k = 0; i < 4; ++i){
			for(int j = 0; j < vArrays[i].size(); ++j){
				vArrayToPrint[k++] = vArrays[i][j];
			}
	   }
	}else{
		SortByDaysOffDescending(vArrayToPrint);
	}
	MyPrint(StringGrid1, vArrayToPrint);
}
//---------------------------------------------------------------------------

void __fastcall TTrips::CSpinButton4UpClick(TObject *Sender)
{
	if(check_for_group_by_purpose == false){
	   for(int i = 0; i < 4; ++i){
		SortByDaysOffAscending(vArrays[i]);
	   }
	   for(int i = 0, k = 0; i < 4; ++i){
			for(int j = 0; j < vArrays[i].size(); ++j){
				vArrayToPrint[k++] = vArrays[i][j];
			}
	   }
	}else{
		SortByDaysOffAscending(vArrayToPrint);
	}
	MyPrint(StringGrid1, vArrayToPrint);
}
//---------------------------------------------------------------------------

void __fastcall TTrips::CSpinButton5DownClick(TObject *Sender)
{
	if(check_for_group_by_purpose == false){
	   for(int i = 0; i < 4; ++i){
		SortByMoneyDescending(vArrays[i]);
	   }
	   for(int i = 0, k = 0; i < 4; ++i){
			for(int j = 0; j < vArrays[i].size(); ++j){
				vArrayToPrint[k++] = vArrays[i][j];
			}
	   }
	}else{
		SortByMoneyDescending(vArrayToPrint);
	}
	MyPrint(StringGrid1, vArrayToPrint);
}
//---------------------------------------------------------------------------

void __fastcall TTrips::CSpinButton5UpClick(TObject *Sender)
{
	if(check_for_group_by_purpose == false){
	   for(int i = 0; i < 4; ++i){
		SortByMoneyAscending(vArrays[i]);
	   }
	   for(int i = 0, k = 0; i < 4; ++i){
			for(int j = 0; j < vArrays[i].size(); ++j){
				vArrayToPrint[k++] = vArrays[i][j];
			}
	   }
	}else{
		SortByMoneyAscending(vArrayToPrint);
	}
	MyPrint(StringGrid1, vArrayToPrint);
}
//---------------------------------------------------------------------------

void __fastcall TTrips::ComboBox1Change(TObject *Sender)
{
	vArrayToPrint.clear();
	if(ComboBox1->Text == "All"){
		for(int i = 0; i < vArrayOfPlaces.size(); ++i){
			vArrayToPrint.push_back(vArrayOfPlaces[i]);
		}
	}else if(ComboBox1->Text == "Work"){
		for(int i = 0; i < vArrayOfPlaces.size(); ++i){
			if(vArrayOfPlaces[i]->GetPurpose() == Work)
				vArrayToPrint.push_back(vArrayOfPlaces[i]);
		}
	}else if(ComboBox1->Text == "Study"){
		for(int i = 0; i < vArrayOfPlaces.size(); ++i){
			if(vArrayOfPlaces[i]->GetPurpose() == Study)
				vArrayToPrint.push_back(vArrayOfPlaces[i]);
		}
	}else if(ComboBox1->Text == "Tourism"){
		for(int i = 0; i < vArrayOfPlaces.size(); ++i){
			if(vArrayOfPlaces[i]->GetPurpose() == Tourism)
				vArrayToPrint.push_back(vArrayOfPlaces[i]);
		}
	}else{
		for(int i = 0; i < vArrayOfPlaces.size(); ++i){
			if(vArrayOfPlaces[i]->GetPurpose() == Rest)
				vArrayToPrint.push_back(vArrayOfPlaces[i]);
		}
	}
	MyPrint(StringGrid1, vArrayToPrint);
	MainMenu1->Items[0][1]->Items[2]->Caption = "Розгрупувати";
}
//---------------------------------------------------------------------------
void __fastcall TTrips::ComboBox2Change(TObject *Sender)
{
	vArrayToPrint.clear();
	if(ComboBox2->Text == "All"){
		for(int i = 0; i < vArrayOfPlaces.size(); ++i){
			vArrayToPrint.push_back(vArrayOfPlaces[i]);
		}
	}else if(ComboBox2->Text == "Scheduled"){
		for(int i = 0; i < vArrayOfPlaces.size(); ++i){
			if(vArrayOfPlaces[i]->GetStatus() == Scheduled)
				vArrayToPrint.push_back(vArrayOfPlaces[i]);
		}
	}else if(ComboBox2->Text == "InProgress"){
		for(int i = 0; i < vArrayOfPlaces.size(); ++i){
			if(vArrayOfPlaces[i]->GetStatus() == InProgress)
				vArrayToPrint.push_back(vArrayOfPlaces[i]);
		}
	}else if(ComboBox2->Text == "Done"){
		for(int i = 0; i < vArrayOfPlaces.size(); ++i){
			if(vArrayOfPlaces[i]->GetStatus() == Done)
				vArrayToPrint.push_back(vArrayOfPlaces[i]);
		}
	}
	MyPrint(StringGrid1, vArrayToPrint);
	MainMenu1->Items[0][1]->Items[2]->Caption = "Розгрупувати";
}
//---------------------------------------------------------------------------

void __fastcall TTrips::Remove1Click(TObject *Sender)
{
	if(vArrayOfPlaces.size() > 0){
		MyPrint(StringGrid1, vArrayOfPlaces);
		MyRemove->Show();
	}else
		ShowMessage("Немає подорожей!");
}
//---------------------------------------------------------------------------

void __fastcall TTrips::Removeall1Click(TObject *Sender)
{
	if(vArrayOfPlaces.size() <= 0){
		ShowMessage("Немає подорожей!");
	}
	for(int i = 0; i < vArrayOfPlaces.size() + i; ++i){
		vArrayOfPlaces.erase(vArrayOfPlaces.begin());
	}
	MyPrint(StringGrid1, vArrayOfPlaces);
}
//---------------------------------------------------------------------------

void __fastcall TTrips::Gpoupbypurpose1Click(TObject *Sender)
{
	vArrays.clear();
	vArrayToPrint.clear();
	if(check_for_group_by_purpose == true){
		for(int i = 0; i < 4; ++i){
			vArrays.push_back(vector<CPlace*> ());
		}
		//Grouping by purpose
		for(int i = 0; i < vArrayOfPlaces.size(); ++i){
			if(vArrayOfPlaces[i]->GetPurpose() == Work){
				vArrays[0].push_back(vArrayOfPlaces[i]);
			}else if(vArrayOfPlaces[i]->GetPurpose() == Study){
				vArrays[1].push_back(vArrayOfPlaces[i]);
			}else if(vArrayOfPlaces[i]->GetPurpose() == Tourism){
				vArrays[2].push_back(vArrayOfPlaces[i]);
			}else if(vArrayOfPlaces[i]->GetPurpose() == Rest){
				vArrays[3].push_back(vArrayOfPlaces[i]);
			}
		}
		for(int i = 0, k = 0; i < 4; ++i){
			for(int j = 0; j < vArrays[i].size(); ++j){
				vArrayToPrint.push_back(vArrays[i][j]);
			}
	   }
	   MyPrint(StringGrid1, vArrayToPrint);
	   check_for_group_by_purpose = false;
	   MainMenu1->Items[0][1]->Items[2]->Caption = "Розгрупувати";
	}else{
		check_for_group_by_purpose = true;
		MainMenu1->Items[0][1]->Items[2]->Caption = "Згрупувати за ціллю";
		MyPrint(StringGrid1, vArrayOfPlaces);
	}
}
//---------------------------------------------------------------------------


void __fastcall TTrips::Lastmonth1Click(TObject *Sender)
{
	vArrayToPrint.clear();
	for(int i = 0; i < vArrayOfPlaces.size(); ++i){
		if(vArrayOfPlaces[i]->GetDayOfDeparture().uiMonth == 11){
			vArrayToPrint.push_back(vArrayOfPlaces[i]);
		}
	}
	SortByMoneyDescending(vArrayToPrint);
	MyPrint(StringGrid1, vArrayToPrint);
}
//---------------------------------------------------------------------------

void __fastcall TTrips::Maxdaysoffbypurpose1Click(TObject *Sender)
{
	vArrayToPrint.clear();
	if(vArrayOfPlaces.size() > 0){
		vArrays.clear();
		int iMax[4];
		for(int i = 0; i < 4; ++i){
			vArrays.push_back(vector<CPlace*> ());
		}
		//Grouping by purpose
		for(int i = 0; i < vArrayOfPlaces.size(); ++i){
			if(vArrayOfPlaces[i]->GetPurpose() == Work){
				vArrays[0].push_back(vArrayOfPlaces[i]);
			}else if(vArrayOfPlaces[i]->GetPurpose() == Study){
				vArrays[1].push_back(vArrayOfPlaces[i]);
			}else if(vArrayOfPlaces[i]->GetPurpose() == Tourism){
				vArrays[2].push_back(vArrayOfPlaces[i]);
			}else if(vArrayOfPlaces[i]->GetPurpose() == Rest){
				vArrays[3].push_back(vArrayOfPlaces[i]);
			}
		}
		//Finding max elements in every group
		for(int i = 0; i < vArrays.size(); ++i){
			int max;
			if(vArrays[i].size() > 0){
				max = vArrays[i][0]->GetDaysOff();}
			for(int j = 0; j < vArrays[i].size(); ++j){
				if(max < vArrays[i][j]->GetDaysOff())
					max = vArrays[i][j]->GetDaysOff();
			}
			iMax[i] = max;
		}
		for(int i = 0, k = 0; i < vArrays.size(); ++i){
			for(int j = 0; j < vArrays[i].size(); ++j){
				if(vArrays[i][j]->GetDaysOff() == iMax[i])
					vArrayToPrint.push_back(vArrays[i][j]);
			}
	   }
	   SortByCountryAscending(vArrayToPrint);
	   MyPrint(StringGrid1, vArrayToPrint);
   }
}
//---------------------------------------------------------------------------

void __fastcall TTrips::Scheduled1Click(TObject *Sender)
{
	vArrayToPrint.clear();
	for(int i = 0; i < vArrayOfPlaces.size(); ++i){
		if(vArrayOfPlaces[i]->GetStatus() == Scheduled)
			vArrayToPrint.push_back(vArrayOfPlaces[i]);
	}
	MyPrint(StringGrid1, vArrayToPrint);
	++StringGrid1->RowCount;
	//Calculate % of scheduled trips
	StringGrid1->Cells[7][StringGrid1->RowCount - 1] = FloatToStrF(((double)vArrayToPrint.size() / vArrayOfPlaces.size()) * 100, ffGeneral, 4, 2) + "%";
}
//---------------------------------------------------------------------------

void __fastcall TTrips::op5mostexpensive1Click(TObject *Sender)
{
	vArrayToPrint.clear();
	float *fSpentMoneyPerDay = new float[vArrayOfPlaces.size()];
	//Calculating money per day for every trip
	for(int i = 0; i < vArrayOfPlaces.size(); ++i){
		fSpentMoneyPerDay[i] = (float)vArrayOfPlaces[i]->GetMoney() / vArrayOfPlaces[i]->GetDaysOff();
	}
	//Finding 5 max elements
	int index;
	for(int j = 0; j < 5; ++j){
		float fMax = fSpentMoneyPerDay[0];
		index = 0;
		for(int i = 0; i < vArrayOfPlaces.size(); ++i){
			if(fMax < fSpentMoneyPerDay[i]){
				fMax = fSpentMoneyPerDay[i];
				index = i;
			}
		}
		vArrayToPrint.push_back(vArrayOfPlaces[index]);
		fSpentMoneyPerDay[index] = -1;
	}
	 MyPrint(StringGrid1, vArrayToPrint);
}
//---------------------------------------------------------------------------

void __fastcall TTrips::Averagedaysoff1Click(TObject *Sender)
{
	int iSumOfDaysOff = 0;
	for(int i = 0; i < vArrayOfPlaces.size(); ++i){
		iSumOfDaysOff += vArrayOfPlaces[i]->GetDaysOff();
	}
	MyPrint(StringGrid1, vArrayOfPlaces);
	++StringGrid1->RowCount;
	StringGrid1->Cells[2][StringGrid1->RowCount - 1] = "Середня";
	StringGrid1->Cells[3][StringGrid1->RowCount - 1] = "тривалість:";
	StringGrid1->Cells[4][StringGrid1->RowCount - 1] = IntToStr(iSumOfDaysOff / (int)vArrayOfPlaces.size());
}
//---------------------------------------------------------------------------

void __fastcall TTrips::Open1Click(TObject *Sender)
{
	vArrayToPrint.clear();
	FILE *fp;
	ifstream myfile;
	if(OpenTextFileDialog1->Execute()) {
		  myfile.open(AnsiString(OpenTextFileDialog1->FileName).c_str(), ios::in);
	}
	string chWholeLine, temp;
	while (myfile.good()) {
		//Reading one line from file
		std::getline(myfile, chWholeLine);
		if(chWholeLine == "") break;
		temp.clear();
		CPlace *Obj = new CPlace;
		int cSpaces = 0;
		for (int i = 0; i < chWholeLine.size(); ++i) {
			if (chWholeLine[i] == ' ')
				++cSpaces;
		}
		if (cSpaces != 6) {
			ShowMessage("Некоректні дані у файлі! Виправте та спробуйте ще раз.");
			myfile.close();
			break;
		}
		else {
			int cSpace = 0;
			int i = 0;
			for (; i < chWholeLine.size(); i++) {
				if (chWholeLine[i] == ' ') {
					++cSpace;
					temp.clear();
					continue;
				}//Checking country
				if (cSpace == 0)
				{
					if (!isalpha(chWholeLine[i])) {
						ShowMessage("Некоректні дані у файлі!(Назва країни повинна містити лише літери!)");
						myfile.close();
						break;
					}
					else {
						temp.push_back(chWholeLine[i]);
						Obj->SetCountry(temp);
					}
				}//Checking locality
				else if (cSpace == 1) {
					if (!isalpha(chWholeLine[i])) {
						ShowMessage("Некоректні дані у файлі!(Назва міста повинна містити лише літери!)");
						myfile.close();
						break;
					}
					else {
						temp.push_back(chWholeLine[i]);
						Obj->SetLocality(temp);
					}
				}//Checking date
				else if (cSpace == 3 && chWholeLine[i - 1] == ' ') {
					if (!isdigit(chWholeLine[i - 11]) || !isdigit(chWholeLine[i - 10]) || !isdigit(chWholeLine[i - 8]) ||
						!isdigit(chWholeLine[i - 7]) || !isdigit(chWholeLine[i - 5]) || !isdigit(chWholeLine[i - 4]) ||
						!isdigit(chWholeLine[i - 3]) || !isdigit(chWholeLine[i - 2]) || chWholeLine[i - 9] != '.' || chWholeLine[i - 6] != '.') {
						ShowMessage("Некоректні дані у файлі!(Неправильно вказана дата!)");
						myfile.close();
						break;
					}
					struct Date date;
					temp.clear();
					temp.push_back(chWholeLine[i - 11]);
					temp.push_back(chWholeLine[i - 10]);
					if (atoi(temp.c_str()) > 31 || atoi(temp.c_str()) < 1) {
						ShowMessage("Некоректні дані у файлі!(Неправильно вказана дата!)");
						myfile.close();
						break;
					}
					else{
						date.uiDay = atoi(temp.c_str());
					}
					temp.clear();
					temp.push_back(chWholeLine[i - 8]);
					temp.push_back(chWholeLine[i - 7]);
					if (atoi(temp.c_str()) > 12 || atoi(temp.c_str()) < 1) {
						ShowMessage("Некоректні дані у файлі!(Неправильно вказана дата!)");
						myfile.close();
						break;
					}
					else{
						date.uiMonth = atoi(temp.c_str());
					}
					temp.clear();
					temp.push_back(chWholeLine[i - 5]);
					temp.push_back(chWholeLine[i - 4]);
					temp.push_back(chWholeLine[i - 3]);
					temp.push_back(chWholeLine[i - 2]);
					if (atoi(temp.c_str()) > 2050 || atoi(temp.c_str()) < 1970) {
						ShowMessage("Некоректні дані у файлі!(Неправильно вказана дата!)");
						myfile.close();
						break;
					}
					else{
						date.uiYear = atoi(temp.c_str());
						Obj->SetDate(date);
					}
				}//Checking days off
				else if (cSpace == 4 && chWholeLine[i - 1] == ' ') {
					if(chWholeLine[i - 3] != ' ' && !isdigit(chWholeLine[i - 3])){
						ShowMessage("Некоректні дані(тривалість)!");
						myfile.close();
						break;
					}
					if (!isdigit(chWholeLine[i - 2])){
						ShowMessage("Некоректні дані(тривалість)!");
						myfile.close();
						break;
					}else {
						temp.clear();
						if(chWholeLine[i - 4] == ' '){
							temp.push_back(chWholeLine[i - 3]);
							temp.push_back(chWholeLine[i - 2]);
						}else
							temp.push_back(chWholeLine[i - 2]);
						if(atoi(temp.c_str()) > 0 && atoi(temp.c_str()) < 15)
							Obj->SetDaysOff(atoi(temp.c_str()));
					}
				}//Checking money
				else if (cSpace == 5 && chWholeLine[i - 1] == ' ') {
					int j = 2;
					while(chWholeLine[i - j] != ' '){
						if(!isdigit(chWholeLine[i - j++])){
							ShowMessage("Некоректні дані(бюджет)!");
							myfile.close();
							break;
						}
					}
					if(chWholeLine[i - j] != ' ')
						break;
					else{
						temp.clear();
						for(int k = j - 1; k >= 2; --k){
							temp.push_back(chWholeLine[i - k]);
						}
						if(atoi(temp.c_str()) >= 0 && atoi(temp.c_str()) <= 100000)
							Obj->SetMoney(atoi(temp.c_str()));
						else{
							ShowMessage("Некоректні дані(бюджет)!");
							myfile.close();
							break;
						}
					}
				}//Checking purpose
				else if(cSpace == 5 && chWholeLine[i - 2] == ' '){
					int j = -1;
					while(chWholeLine[i + j] != ' '){
						j++;
						if(!isalpha(chWholeLine[i + j - 1])){
							ShowMessage("Некоректні дані(ціль)!");
							myfile.close();
							break;
						}
					}
					if(chWholeLine[i + j] != ' ')
						break;
					else{
						temp.clear();
						for(int k = -1; k < j; ++k){
							temp.push_back(chWholeLine[i + k]);
						}
						if(temp == "Work")
							Obj->SetPurpose(Work);
						else if(temp == "Study")
							Obj->SetPurpose(Study);
						else if(temp == "Tourism")
							Obj->SetPurpose(Tourism);
						else if(temp == "Rest")
							Obj->SetPurpose(Rest);
						else{
							ShowMessage("Некоректні дані(ціль)!");
							myfile.close();
							break;
						}
					}
					struct Date today;
					string str = AnsiString(DateToStr(Now().DateString())).c_str();
					temp.clear();
					temp.push_back(str[0]);
					temp.push_back(str[1]);
					today.uiDay = atoi(temp.c_str());
					temp.clear();
					temp.push_back(str[3]);
					temp.push_back(str[4]);
					today.uiMonth = atoi(temp.c_str());
					temp.clear();
					temp.push_back(str[6]);
					temp.push_back(str[7]);
					temp.push_back(str[8]);
					temp.push_back(str[9]);
					today.uiYear = atoi(temp.c_str());
					if(DateToDays(today) < DateToDays(Obj->GetDayOfDeparture()))
						Obj->SetStatus(Scheduled);
					else if(DateToDays(today) >= DateToDays(Obj->GetDayOfDeparture()) && DateToDays(today) <= (DateToDays(Obj->GetDayOfDeparture()) + Obj->GetDaysOff() - 1))
						Obj->SetStatus(InProgress);
					else
						Obj->SetStatus(Done);
				}
			}
			if(i == chWholeLine.size())
				vArrayOfPlaces.push_back(Obj);
		}
	}
	for(int i = 0; i < vArrayOfPlaces.size(); ++i){
		vArrayToPrint.push_back(vArrayOfPlaces[i]);
	}
	MyPrint(StringGrid1, vArrayToPrint);
	myfile.close();
}
//---------------------------------------------------------------------------

void __fastcall TTrips::Save1Click(TObject *Sender)
{
	if(vArrayOfPlaces.size() == 0){
		ShowMessage("Спочатку потрібно додати подорож!");
		return;
	}
	std::ofstream myfile;
	if(SaveTextFileDialog1->Execute()) {
		 myfile.open(AnsiString(SaveTextFileDialog1->FileName).c_str(), ios::out);
	}
	int i = 0;
	while (i < vArrayOfPlaces.size()) {
		//Writing to file
		myfile << vArrayOfPlaces[i]->GetCountry() << " "
			   << vArrayOfPlaces[i]->GetLocality() << " ";
		if(vArrayOfPlaces[i]->GetDayOfDeparture().uiDay > 0 && vArrayOfPlaces[i]->GetDayOfDeparture().uiDay < 10) {
			myfile << "0" << vArrayOfPlaces[i]->GetDayOfDeparture().uiDay << ".";
		}
		else{
			myfile << vArrayOfPlaces[i]->GetDayOfDeparture().uiDay << ".";
		}
		if(vArrayOfPlaces[i]->GetDayOfDeparture().uiMonth > 0 && vArrayOfPlaces[i]->GetDayOfDeparture().uiMonth < 10) {
			myfile << "0" << vArrayOfPlaces[i]->GetDayOfDeparture().uiMonth << ".";
		}
		else {
			myfile << vArrayOfPlaces[i]->GetDayOfDeparture().uiMonth << ".";
		}
		myfile << vArrayOfPlaces[i]->GetDayOfDeparture().uiYear  << " "
			   << vArrayOfPlaces[i]->GetDaysOff() << " "
			   << vArrayOfPlaces[i]->GetMoney() << " "
			   << AnsiString(PurposeToUnicode(vArrayOfPlaces[i]->GetPurpose())).c_str() << " "
			   << AnsiString(StatusToUnicode(vArrayOfPlaces[i]->GetStatus())).c_str() << endl;
		++i;
	}
	myfile.close();
}
//---------------------------------------------------------------------------

void __fastcall TTrips::Exit1Click(TObject *Sender)
{
	MainPage->Close();
}
//---------------------------------------------------------------------------

void __fastcall TTrips::N5Click(TObject *Sender)
{
	Info->Show();
}
//---------------------------------------------------------------------------

void __fastcall TTrips::Print1Click(TObject *Sender)
{
	MyPrint(StringGrid1, vArrayOfPlaces);
}
//---------------------------------------------------------------------------

