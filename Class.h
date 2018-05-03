//---------------------------------------------------------------------------

#ifndef ClassH
#define ClassH

#include <string>
#include <vector>
#include <map>
#include "Grids.hpp"

using namespace std;

enum ePurpose { Work = 0, Study, Tourism, Rest };
enum eStatus { Scheduled = 25, InProgress = 50, Done = 100 };

struct Date{
	unsigned int uiDay;
	unsigned int uiMonth;
	unsigned int uiYear;
};

class CCity{
protected:
	string sCountry;                                            //Name of the country
	string sLocality;  											//Name of the city/town/village
public:
	//Default constructor
	CCity();
	//Constructor with parameters
	CCity(string country, string locality);
	virtual void SetCountry(string country) = 0;
	virtual void SetLocality(string locality) = 0;
	virtual string GetCountry() = 0;
	virtual string GetLocality() = 0;
};

class CPlace: public CCity{
protected:
	struct Date DDayOfDeparture;                   		         //Date of departure
	unsigned int cDaysOff;                                       //Number of days off
	unsigned int uiMoney;                   		             //Amount of money spent
	ePurpose uiPurpose;                             		     //Purpose of the trip
	eStatus uiStatus; 										     //Status of the trip
	map<string, bool> mStuff;						             //Things which person brings with herself
	map<string, bool> mActivities;						         //Activities

	static unsigned int scObjects;			 					 //Number of objects

public:
	//Default constructor
	CPlace();
	//Constructors with parameters
	CPlace(string country, string locality, struct Date date_of_departure, unsigned int days_off,
		   unsigned int money, ePurpose purpose, map<string, bool> stuff,
		   map<string, bool> activities);
	//Copy constructor
	CPlace(const CPlace &Obj);
	//operator=
	CPlace& operator=(const CPlace &Obj);
	//Destructor
	~CPlace();
	//--------------------------------------------------------------------------------------
	//Set class fields
	void SetPlace(string country, string locality, struct Date date_of_departure, unsigned int days_off,
				  unsigned int money, ePurpose purpose, map<string, bool> stuff,
				  map<string, bool> activities);
	//Set sCountry field of the class
	void SetCountry(string country);
	//Set sLocality field of the class
	void SetLocality(string locality);
	//Set date of departure
	void SetDate(struct Date date_of_departure);
	//Set ucDaysOff field of the class
	void SetDaysOff(unsigned int days_off);
	//Set uiMoney field of the class
	void SetMoney(unsigned int money);
	//Set uiPurpose field of the class
	void SetPurpose(ePurpose purpose);
	//Set uiStatus
	void SetStatus(eStatus status);
	//Set thing
	void SetThing(string thing, bool check);
	//Set mStuff field of the class
	void SetStuff(map<string, bool> stuff);
	//Set activity
	void SetActivity(string activity, bool check);
	//Set mActivities field of the class
	void SetActivities(map<string, bool> activities);
	//----------------------------------------------------------------------------------------
	//Get sCountry field of the class
	string GetCountry();
	//Get sLocality field of the class
	string GetLocality();
	//Get date of departure
	struct Date GetDayOfDeparture();
	//Get ucDaysOff field of the class
	unsigned int GetDaysOff();
	//Get uiMoney field of the class
	unsigned int GetMoney();
	//Get uiPurpose field of the class
	ePurpose GetPurpose();
	//Get uiStatus field of the class
	eStatus GetStatus();
	//Get sucObjects field of the class
	static unsigned int GetObjects();
	//-----------------------------------------------------------------------------------------
	//Sorting array of cities by country name in ascending order
	friend void SortByCountryAscending(vector<CPlace*> &vArrayOfCities);
	//Sorting array of cities by country name in descending order
	friend void SortByCountryDescending(vector<CPlace*> &vArrayOfCities);
	//Sorting array of cities by locality name in ascending order
	friend void SortByLocalityAscending(vector<CPlace*> &vArrayOfCities);
	//Sorting array of cities by locality name in descending order
	friend void SortByLocalityDescending(vector<CPlace*> &vArrayOfCities);
	//Sorting array of cities by date in ascending order
	friend void SortByDateAscending(vector<CPlace*> &vArrayOfCities);
	//Sorting array of cities by date in descending order
	friend void SortByDateDescending(vector<CPlace*> &vArrayOfCities);
	//Sorting array of cities by number of days off in ascending order
	friend void SortByDaysOffAscending(vector<CPlace*> &vArrayOfCities);
	//Sorting array of cities by number of days off in descending order
	friend void SortByDaysOffDescending(vector<CPlace*> &vArrayOfCities);
	//Sorting array of cities by amount of money spent in ascending order
	friend void SortByMoneyAscending(vector<CPlace*> &vArrayOfCities);
	//Sorting array of cities by amount of money spent in descending order
	friend void SortByMoneyDescending(vector<CPlace*> &vArrayOfCities);
	//Prints cities
	friend void MyPrint(TStringGrid *Grid, vector<CPlace*> &vArrayOfCities);
	//----------------------------------------------------------------------------------------
};

class Exceptions{
public:
	class Empty{};
	class FirstCharacterIsLowercase{};
	class InappropriateCharacter{};
	class UppercaseLetter{};
};

ePurpose UnicodeToPurpose(UnicodeString str);
UnicodeString PurposeToUnicode(ePurpose pur);
UnicodeString StatusToUnicode(eStatus stat);
unsigned int DateToDays(struct Date date);
void IsNotLetter(TEdit *Edit);
//---------------------------------------------------------------------------
#endif
