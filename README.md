# IR-Windows-Remote

Code to control your computers multimedia interface using a TV remote via arduino and a IR sensor.
The interface code is written specifically for windows using the windows.h library.

RemoteRefineSend.ino - the arduino/processing file. it is just used to collect the data and convert it in to easily passable form.You can change the values based on the remote and IR reciever.

Scan_Read.h - contains the class which deals with creation of a virtual sSerial port along the usb and passes data to and from the arduino and the programme

Datahandle.h - recieved data is converted in to action using the INPUT class built into windows.h

Remote.cpp - puts both the header files and their functionalities together
