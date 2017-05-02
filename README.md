# soa_interface
Human operator interface for SOA simulator




%=============

INTERFACE DOCUMENTATION

%=============


 
This document serves as a guide on how to run the operator interface. The interface is built using the Qt framework, so this guide describes how to download the Qt Creator IDE. The interface provides a map-based representation of the state of the simulator using the Google Maps API and military standard icons. Instructions on how to download and run the simulator is also presented. 



%=============

Cmake, autoreconf, boost...

%=============



01.  If autoreconf, boost, cmake, etc not installed:
	$  sudo apt-get install autoconf boost libboost cmake
02.  If cmake already installed, make sure version at least 3.8.0



%=============

Simulator

%=============



01.  Download and unzip "interface.zip" into the "Downloads" directory  
02.  Right click "Soav1.7_Linux.x86_64.exe"
	Permissions tab >> enable "Allow executing file as program"
03.  Request JHU/APL for access to "Sharepoint" in order to download future releases



%=============

Google protobuf

%=============



01.  Go to
	https://github.com/google/protobuf
02.  Click on the "Branch: master" dropdown button 
03.  Select the "Tags" tab 
04.  Scroll through the list and select v3.0.0-alpha-2
05.  Click on the "Clone or download" button
06.  Click on the "Download ZIP" button
07.  Unzip /Downloads/protobuf-3.0.0-alpha-2.zip
08.  Move the unzipped directory "protobuf-3.0.0-alpha-2" into the "soa_sample_app" directory
09.  Open the file autogen.sh file, it lives here:
	~/Downloads/soa_sample_app/protobuf-3.0.0-beta-2/autogen.sh
10.  Delete all the lines and replace with the 51 lines found here: 
	https://github.com/google/protobuf/blob/master/autogen.sh   
11.  On the terminal, cd into the unzipped directory and run:
	~/Downloads/protobuf-3.0.0-beta-2$  ./autogen.sh
	~/Downloads/protobuf-3.0.0-beta-2$  ./configure
	~/Downloads/protobuf-3.0.0-beta-2$  make 
        ~/Downloads/protobuf-3.0.0-beta-2$  make check 
        ~/Downloads/protobuf-3.0.0-beta-2$  sudo make install
12.  (Optional) More details about the previous step, if interested:
	https://github.com/google/protobuf/tree/v3.0.0-beta-2



%=============

Qt creator

%=============



01.  Download Qt Creator here:
	https://www.qt.io/ide/
02.  Click on the "Start for Free" button on the image banner
03.  The next window asks about deployment
	Select the radio button "In-house deployment, private use, or student use"
04.  The next window asks about distribution
	Select the "No" radio button 
05.  The next window asks about compliance
	Select the "Yes" radio button
06.  Click on the "Get Started" button
07.  The next window detects the OS
	Click on the "Download Now" button



%=============

Running the simulator

%=============



01.  Double click the "Soav1.7_Linux.x86_64.exe"
	Enable "Windowed"
	Select "Screen resolution" and the "Graphics quality"
  	Ignore the "Input" Tab
02.  (Optional) Simulator parameters can be found in "SoaSimConfig.xml"



%=============

Running the interface

%=============



01.  Launch Qt Creator
02.  Click on "Open Project"
03.  Select "interface_20JUN16.pro" located here:
	~/Downloads/soa_sample_app/interface_20JUN16/interface_20Jun16.pro
04.  Build project 
	Build >> Build Project "interface20JUN16"
05.  Run project
	Build >> Run



%=============

Interface details

%=============



01.  Entry point is main.cpp
	Instantiating an InterfaceWindow object
	Calling method show() since InterfaceWindow inherits QWidget
	http://doc.qt.io/qt-4.8/qwidget.html#show
	Rest of code attributed to creating standard QApplication

02.  InterfaceWindow
	Lab convention of member pointers being m_p prefixed
	Holds three widgets -- LogicWidget, TabPanel, and TaskPanel
	LogicWidget responsible for logic and placement of military standard icons on Google Maps display
	TaskPanelWidget responsible for tasking the simulator 
	TabPanel displays information regarding actors and tasks

03.  interfacewindow and taskpanelwidget come with .ui files in addition to the .h and .cpp pair. 
	You
	  



%=============

End Document

%=============


