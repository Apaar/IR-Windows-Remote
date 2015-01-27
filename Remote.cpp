#define WINVER 0x0500

#if       _WIN32_WINNT < 0x0500                          //the predefined windows api fuctions check the version of windows
  #undef  _WIN32_WINNT
  #define _WIN32_WINNT   0x0500
#endif


#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
//#include <tchar.h>
#include <string>
#include <iostream>
#include "Scan_Read.h"
#include "DataHandle.h"

int main()
{
    ShowWindow( GetConsoleWindow(), SW_HIDE );
    int exitCond=0;         //allowing for exit of the programme

	Serial* SP = new Serial("COM7");
	    // adjust as needed
    system("cls");                                      //error checking built into the constructor

	if (!SP->IsConnected())
    {
             //decided to do i in both cases at a later date
        while(!SP->IsConnected())                       //We are constantly checking for a COM port till one is found
        {
            delete SP;
            Serial* SP = new Serial("COM3");
            Sleep(500);
        }
    }

    ShowWindow( GetConsoleWindow(), SW_RESTORE );
    std::cout<<"\nWELCOME TO THE REMOTE CONTROL\n";
    std::cout<<"\nCONNECTED TO RECIEVER!!!!\n";
    std::cout<<"You may start using the remote.This message will close in 5 seconds\n";
    Sleep(5000);
    system("cls");
    ShowWindow( GetConsoleWindow(), SW_HIDE );
                                        //Hiding the console window(can be opened with button 14


	int dataLength = 2;
	int readResult = 0;

	while(SP->IsConnected() && exitCond != 1)
	{
	    char incomingData[3] = "";
		readResult = SP->ReadData(incomingData,dataLength);         //passing the length and the file to contain data

		std::string test(incomingData);

        if(readResult != -1)
        {
            exitCond = DataAct(incomingData);          //if bytes read passing for processing(check DataHandle)
        }

		test = "";
		Sleep(50);                         //checking ever 500ms
	}
    delete SP;
	return 0;
}

