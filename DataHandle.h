
#ifndef DATAHANDLE_H
#define DATAHANDLE_H

int DataAct(char inturrupt[3])
{
    int exitCondt = 0;

                //converting from character array to integer
    INPUT ip;                                           //Initialising INPUT a windows.h api to spoof keyboard hardware intturupts
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    if(inturrupt[0] == '1' && inturrupt[1] == '1')
    {
        ip.ki.wVk = 0xB3;
        ip.ki.dwFlags = 0;
    }

    else if(inturrupt[0] == '1' && inturrupt[1] == '2')
    {
        ip.ki.wVk = 0xB0;
        ip.ki.dwFlags = 0;
    }

    else if(inturrupt[0] == '1' && inturrupt[1] == '3')
    {
        ip.ki.wVk = 0xB2;
        ip.ki.dwFlags = 0;
    }

    else if(inturrupt[0] == '1' && inturrupt[1] == '4')
    {
        system("cls");
        ShowWindow( GetConsoleWindow(), SW_RESTORE );
        std::cout<<"\nWELCOME TO THE REMOTE CONTROL\n";
        std::cout<<"11 - Play/Pause\n";
        std::cout<<"12 - Next Track\n";
        std::cout<<"13 - Stop\n";
        std::cout<<"14 - Help\n";
        std::cout<<"22 - Previous Track\n";
        std::cout<<"24 - Open Zune\n";
        std::cout<<"34 - MUTE\n";
        std::cout<<"44 - Increase volume by 2\n";
        std::cout<<"54 - Decrease volume by 2\n";
        std::cout<<"65 - EXIT!!!!!\n";

       std::cout<<"\nTHIS PAGE WILL CLOSE IN 10 SECONDS TO REPEAT PRESS MENU AGAIN\n";
       Sleep(10000);
       ShowWindow( GetConsoleWindow(), SW_HIDE );
    }

    else if(inturrupt[0] == '2' && inturrupt[1] == '2')
    {
        ip.ki.wVk = 0xB1;
        ip.ki.dwFlags = 0;
    }

    else if(inturrupt[0] == '4' && inturrupt[1] == '4')
    {
        ip.ki.wVk = 0xAF;
        ip.ki.dwFlags = 0;
    }

    else if(inturrupt[0] == '5' && inturrupt[1] == '4')
    {
        ip.ki.wVk = 0xAE;
        ip.ki.dwFlags = 0;
    }

    else if(inturrupt[0] == '3' && inturrupt[1] == '4')
    {
        ip.ki.wVk = 0xAD;
        ip.ki.dwFlags = 0;
    }

    else if(inturrupt[0] == '6' && inturrupt[1] == '4')
    {
        ShowWindow( GetConsoleWindow(), SW_RESTORE );
        system("cls");
        std::cout<<"\nET TU BRUTE??\n";
        exitCondt = 1;                  //Exiting the programme
    }

     else if(inturrupt[0] == '2' && inturrupt[1] == '4')
    {
        ShellExecute( NULL, "open", "Zune.exe", NULL, NULL, SW_SHOWNORMAL );
    }



    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
return exitCondt;
}


#endif
