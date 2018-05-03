//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("SP.cpp", MainPage);
USEFORM("Rem.cpp", MyRemove);
USEFORM("Adding.cpp", Add);
USEFORM("MainForm.cpp", Trips);
USEFORM("Unit1.cpp", Info);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TMainPage), &MainPage);
		Application->CreateForm(__classid(TTrips), &Trips);
		Application->CreateForm(__classid(TAdd), &Add);
		Application->CreateForm(__classid(TMyRemove), &MyRemove);
		Application->CreateForm(__classid(TInfo), &Info);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
