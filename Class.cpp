//---------------------------------------------------------------------------


#pragma hdrstop

#include "Class.h"

ePurpose UnicodeToPurpose(UnicodeString str){
	ePurpose temp;
	if(str == "Work"){
		temp = Work;
	}else if(str == "Study"){
		temp = Study;
	}else if(str == "Tourism"){
		temp = Tourism;
	}else{
		temp = Rest;
	}
	return temp;
}

UnicodeString PurposeToUnicode(ePurpose pur){
	UnicodeString result = "";
	if(pur == Work){
		result = "Work";
	}else if(pur == Study){
		result = "Study";
	}else if(pur == Tourism){
		result = "Tourism";
	}else{
		result = "Rest";
	}
	return result;
}

UnicodeString StatusToUnicode(eStatus stat){
	UnicodeString result = "";
	if(stat == Scheduled){
		result = "Scheduled";
	}else if(stat == InProgress){
		result = "InProgress";
	}else {
		result = "Done";
	}
	return result;
}

unsigned int DateToDays(struct Date date){
	unsigned int temp = 0;
	//year
	if(date.uiYear % 4 == 0)
		temp = date.uiYear * 366;
	 else
		temp = date.uiYear * 365;
	 //month
	 int i = 1;
	 while(date.uiMonth - i > 0){
		 switch(date.uiMonth){
			case 1, 3, 5, 7, 8, 10, 11:
				temp += (date.uiMonth - i) * 31; break;
			case 2:{
				if(date.uiYear % 4 == 0)
					temp += (date.uiMonth - i) * 29;
				else
					temp += (date.uiMonth - i) * 28;
				break;
			}
			default:
				temp += (date.uiMonth - i) * 30; break;
		 }
		 ++i;
	 }
	 //day
	 temp += date.uiDay;
	 return temp;
}
void IsNotLetter(TEdit *Edit){
	if(islower(Edit->Text.c_str()[0])) {
		throw Exceptions::FirstCharacterIsLowercase();
	}

	for(int i = 0; i < Edit->GetTextLen(); ++i){
		if(isdigit(Edit->Text.c_str()[i] )){
			throw Exceptions::InappropriateCharacter();
		} else if(isspace(Edit->Text.c_str()[i] )){
			throw Exceptions::InappropriateCharacter();
		} else if(!isalpha(Edit->Text.c_str()[i] )){
			throw Exceptions::InappropriateCharacter();
		} else if(isupper(Edit->Text.c_str()[i]) && i != 0 ) {
			throw Exceptions::UppercaseLetter();
		}
	}
}

//Default constructor
CCity::CCity():
	sCountry(""),
	sLocality(""){}
//Constructors with parameters
CCity::CCity(string country, string locality):
	sCountry(country),
	sLocality(locality){}

//Default constructor
CPlace::CPlace():
	CCity(),
	cDaysOff(0),
	uiMoney(0),
	uiPurpose(0),
	uiStatus(25){++scObjects;}
//Constructors with parameters
CPlace::CPlace(string country, string locality, struct Date date_of_departure, unsigned int days_off,
	   unsigned int money, ePurpose purpose, map<string, bool> stuff,
	   map<string, bool> activities):
	CCity(country, locality),
	DDayOfDeparture(date_of_departure),
	cDaysOff(days_off),
	uiMoney(money),
	uiPurpose(purpose),
	mStuff(stuff),
	mActivities(activities){++scObjects;}
//Copy constructor
CPlace::CPlace(const CPlace &Obj){
	sCountry = Obj.sCountry;
	sLocality = Obj.sLocality;
	DDayOfDeparture = Obj.DDayOfDeparture;
	cDaysOff = Obj.cDaysOff;
	uiMoney = Obj.uiMoney;
	uiPurpose = Obj.uiPurpose;
	uiStatus = Obj.uiStatus;
	mStuff = Obj.mStuff;
	mActivities = Obj.mActivities;
	++scObjects;
}
//operator=
CPlace& CPlace::operator=(const CPlace &Obj){
	sCountry = Obj.sCountry;
	sLocality = Obj.sLocality;
	DDayOfDeparture = Obj.DDayOfDeparture;
	cDaysOff = Obj.cDaysOff;
	uiMoney = Obj.uiMoney;
	uiPurpose = Obj.uiPurpose;
	uiStatus = Obj.uiStatus;
	mStuff = Obj.mStuff;
	mActivities = Obj.mActivities;
	++scObjects;
	return *this;
}
//Destructor
CPlace::~CPlace(){
	--scObjects;
}
//--------------------------------------------------------------------------------------
//Set class fields
void CPlace::SetPlace(string country, string locality, struct Date date_of_departure, unsigned int days_off,
			  unsigned int money, ePurpose purpose, map<string, bool> stuff,
			  map<string, bool> activities){
	sCountry = sCountry;
	sLocality = sLocality;
	DDayOfDeparture = DDayOfDeparture;
	cDaysOff = cDaysOff;
	uiMoney = uiMoney;
	uiPurpose = uiPurpose;
	mStuff = mStuff;
	mActivities = mActivities;
}
//Set sCountry field of the class
void CPlace::SetCountry(string country){
	sCountry = country;
}
//Set sLocality field of the class
void CPlace::SetLocality(string locality){
	sLocality = locality;
}
//Set date of departure
void CPlace::SetDate(struct Date date_of_departure){
	DDayOfDeparture = date_of_departure;
}
//Set ucDaysOff field of the class
void CPlace::SetDaysOff(unsigned int days_off){
	cDaysOff = days_off;
}
//Set udMoney field of the class
void CPlace::SetMoney(unsigned int money){
	uiMoney = money;
}
//Set uiPurpose field of the class
void CPlace::SetPurpose(ePurpose purpose){
	uiPurpose = purpose;
}
//Set uiStatus
void CPlace::SetStatus(eStatus status){
	uiStatus = status;
}
//Set thing
void CPlace::SetThing(string thing, bool check){
	mStuff.insert(pair<string, bool>(thing, check));
}
//Set mStuff field of the class
void CPlace::SetStuff(map<string, bool> stuff){
	mStuff = stuff;
}
//Set activity
void CPlace::SetActivity(string activity, bool check){
	mActivities.insert(pair<string, bool>(activity, check));
}
//Set mActivities field of the class
void CPlace::SetActivities(map<string, bool> activities){
	mActivities = activities;
}
//----------------------------------------------------------------------------------------
//Get sCountry field of the class
string CPlace::GetCountry(){
	return sCountry;
}
//Get sLocality field of the class
string CPlace::GetLocality(){
	return sLocality;
}
//Get date of departure
struct Date CPlace::GetDayOfDeparture(){
	return DDayOfDeparture;
}
//Get ucDaysOff field of the class
unsigned int CPlace::GetDaysOff(){
	return cDaysOff;
}
//Get udMoney field of the class
unsigned int CPlace::GetMoney(){
	return uiMoney;
}
//Get uiPurpose field of the class
ePurpose CPlace::GetPurpose(){
	return uiPurpose;
}
//Get uiStatus field of the class
eStatus CPlace::GetStatus(){
	return uiStatus;
}
//Get sucObjects field of the class
unsigned int CPlace::GetObjects(){
	return scObjects;
}
//-----------------------------------------------------------------------------------------
//Sorting array of cities by name in ascending order
void SortByCountryAscending(vector<CPlace*> &vArrayOfCities){
	for(int h = vArrayOfCities.size() / 2; h > 0; h /= 2) {
		for(int j = h; j < vArrayOfCities.size(); j++) {
			for(int k = j - h; k >= 0; k = k - h) {
				if(vArrayOfCities[k + h]->sCountry >= vArrayOfCities[k]->sCountry) break;
				else {
					CPlace *temp = vArrayOfCities[k];
					vArrayOfCities[k] = vArrayOfCities[k + h];
					vArrayOfCities[k + h] = temp;
				}
			}
		}
	}
}
//Sorting array of cities by country name in descending order
void SortByCountryDescending(vector<CPlace*> &vArrayOfCities){
	for(int h = vArrayOfCities.size() / 2; h > 0; h /= 2) {
		for(int j = h; j < vArrayOfCities.size(); j++) {
			for(int k = j - h; k >= 0; k = k - h) {
				if(vArrayOfCities[k + h]->sCountry <= vArrayOfCities[k]->sCountry) break;
				else {
					CPlace *temp = vArrayOfCities[k];
					vArrayOfCities[k] = vArrayOfCities[k + h];
					vArrayOfCities[k + h] = temp;
				}
			}
		}
	}
}
//Sorting array of cities by locality name in ascending order
void SortByLocalityAscending(vector<CPlace*> &vArrayOfCities){
	for(int h = vArrayOfCities.size() / 2; h > 0; h /= 2) {
		for(int j = h; j < vArrayOfCities.size(); j++) {
			for(int k = j - h; k >= 0; k = k - h) {
				if(vArrayOfCities[k + h]->sLocality >= vArrayOfCities[k]->sLocality) break;
				else {
					CPlace *temp = vArrayOfCities[k];
					vArrayOfCities[k] = vArrayOfCities[k + h];
					vArrayOfCities[k + h] = temp;
				}
			}
		}
	}
}
//Sorting array of cities by locality name in de order
void SortByLocalityDescending(vector<CPlace*> &vArrayOfCities){
	for(int h = vArrayOfCities.size() / 2; h > 0; h /= 2) {
		for(int j = h; j < vArrayOfCities.size(); j++) {
			for(int k = j - h; k >= 0; k = k - h) {
				if(vArrayOfCities[k + h]->sLocality <= vArrayOfCities[k]->sLocality) break;
				else {
					CPlace *temp = vArrayOfCities[k];
					vArrayOfCities[k] = vArrayOfCities[k + h];
					vArrayOfCities[k + h] = temp;
				}
			}
		}
	}
}
//Sorting array of cities by date in ascending order
void SortByDateAscending(vector<CPlace*> &vArrayOfCities){
	vector<int> vDays;
	for(int i = 0; i < vArrayOfCities.size(); ++i){
		 vDays.push_back(DateToDays(vArrayOfCities[i]->DDayOfDeparture));
	}
	for(int h = vDays.size() / 2; h > 0; h /= 2) {
		for(int j = h; j < vArrayOfCities.size(); j++) {
			for(int k = j - h; k >= 0; k = k - h) {
				if(vDays[k + h] >= vDays[k]) break;
				else {
					int tmp = vDays[k];
					vDays[k] = vDays[k + h];
					vDays[k + h] = tmp;
					CPlace *temp = vArrayOfCities[k];
					vArrayOfCities[k] = vArrayOfCities[k + h];
					vArrayOfCities[k + h] = temp;
				}
			}
		}
	}
}
//Sorting array of cities by date in descending order
void SortByDateDescending(vector<CPlace*> &vArrayOfCities){
	vector<int> vDays;
	for(int i = 0; i < vArrayOfCities.size(); ++i){
		vDays.push_back(DateToDays(vArrayOfCities[i]->DDayOfDeparture));
	}
	for(int h = vDays.size() / 2; h > 0; h /= 2) {
		for(int j = h; j < vArrayOfCities.size(); j++) {
			for(int k = j - h; k >= 0; k = k - h) {
				if(vDays[k + h] <= vDays[k]) break;
				else {
					int tmp = vDays[k];
					vDays[k] = vDays[k + h];
					vDays[k + h] = tmp;
					CPlace *temp = vArrayOfCities[k];
					vArrayOfCities[k] = vArrayOfCities[k + h];
					vArrayOfCities[k + h] = temp;
				}
			}
		}
	}
}
//Sorting array of cities by number of days off in ascending order
void SortByDaysOffAscending(vector<CPlace*> &vArrayOfCities){
	for(int h = vArrayOfCities.size() / 2; h > 0; h /= 2) {
		for(int j = h; j < vArrayOfCities.size(); j++) {
			for(int k = j - h; k >= 0; k = k - h) {
				if(vArrayOfCities[k + h]->cDaysOff >= vArrayOfCities[k]->cDaysOff) break;
				else {
					CPlace *temp = vArrayOfCities[k];
					vArrayOfCities[k] = vArrayOfCities[k + h];
					vArrayOfCities[k + h] = temp;
				}
			}
		}
	}
}
//Sorting array of cities by number of days off in descending order
void SortByDaysOffDescending(vector<CPlace*> &vArrayOfCities){
	for(int h = vArrayOfCities.size() / 2; h > 0; h /= 2) {
		for(int j = h; j < vArrayOfCities.size(); j++) {
			for(int k = j - h; k >= 0; k = k - h) {
				if(vArrayOfCities[k + h]->cDaysOff <= vArrayOfCities[k]->cDaysOff) break;
				else {
					CPlace *temp = vArrayOfCities[k];
					vArrayOfCities[k] = vArrayOfCities[k + h];
					vArrayOfCities[k + h] = temp;
				}
			}
		}
	}
}
//Sorting array of cities by amount of money spent in ascending order
void SortByMoneyAscending(vector<CPlace*> &vArrayOfCities){
	for(int h = vArrayOfCities.size() / 2; h > 0; h /= 2) {
		for(int j = h; j < vArrayOfCities.size(); j++) {
			for(int k = j - h; k >= 0; k = k - h) {
				if(vArrayOfCities[k + h]->uiMoney >= vArrayOfCities[k]->uiMoney) break;
				else {
					CPlace *temp = vArrayOfCities[k];
					vArrayOfCities[k] = vArrayOfCities[k + h];
					vArrayOfCities[k + h] = temp;
				}
			}
		}
	}
}
//Sorting array of cities by amount of money spent in descending order
void SortByMoneyDescending(vector<CPlace*> &vArrayOfCities){
	for(int h = vArrayOfCities.size() / 2; h > 0; h /= 2) {
		for(int j = h; j < vArrayOfCities.size(); j++) {
			for(int k = j - h; k >= 0; k = k - h) {
				if(vArrayOfCities[k + h]->uiMoney <= vArrayOfCities[k]->uiMoney) break;
				else {
					CPlace *temp = vArrayOfCities[k];
					vArrayOfCities[k] = vArrayOfCities[k + h];
					vArrayOfCities[k + h] = temp;
				}
			}
		}
	}
}
//Prints cities
void MyPrint(TStringGrid *Grid, vector<CPlace*> &vArrayOfCities){
	for(int i = 1; i < Grid->RowCount; ++i){
		for(int j = 0; j < Grid->ColCount; ++j){
			Grid->Cells[j][i] = "";
		}
	}
	Grid->RowCount = vArrayOfCities.size() + 1;
	for(int i = 0; i < vArrayOfCities.size(); ++i){
		Grid->Cells[0][i + 1] = IntToStr(i + 1);
		Grid->Cells[1][i + 1] = AnsiString(vArrayOfCities[i]->sCountry.c_str());
		Grid->Cells[2][i + 1] = AnsiString(vArrayOfCities[i]->sLocality.c_str());
		UnicodeString str = "";
		if(vArrayOfCities[i]->DDayOfDeparture.uiDay / 10 == 0)
			str += "0";
		str += IntToStr((int)vArrayOfCities[i]->DDayOfDeparture.uiDay) + ".";
		if(vArrayOfCities[i]->DDayOfDeparture.uiMonth / 10 == 0)
			str += "0";
		str += IntToStr((int)vArrayOfCities[i]->DDayOfDeparture.uiMonth) + ".";
		str += IntToStr((int)vArrayOfCities[i]->DDayOfDeparture.uiYear);
		Grid->Cells[3][i + 1] = str;
		Grid->Cells[4][i + 1] = IntToStr((int)vArrayOfCities[i]->cDaysOff);
		Grid->Cells[5][i + 1] = FloatToStr(vArrayOfCities[i]->uiMoney);
		Grid->Cells[6][i + 1] = PurposeToUnicode(vArrayOfCities[i]->uiPurpose);
		Grid->Cells[7][i + 1] = StatusToUnicode(vArrayOfCities[i]->uiStatus);
	}
}
#pragma package(smart_init)
