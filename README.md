# soa_interface
Human operator interface for SOA simulator



Clone the soa_interface repository
	https://github.com/mhaque3/soa_interface.git
		
This document serves as a setup guide for the operator interface. Screenshots that accompany this guide can be found in ~/Downloads/screenshots. 



%=============

Components

%=============
	
	

~/Downloads/screenshots/00
 
01.  The interface code lives in ~/Downloads/soa_sample_app
02.  Qt Creator IDE (setup instruction are below) since the interface is built using the Qt framework.  
03.  The simulator lives in ~/Downloads/soa_sim. Additional information is provided below. 
03.  Google Protocol Buffers (the sim needs these for messaging). Instructions on how to install Google protobuf is provided in this document. 



%=============

System

%=============



01.  Ubuntu 14.04 LTS
02.  If autoreconf, boost, cmake, etc not installed:
	$  sudo apt-get install autoconf boost libboost cmake
03.  If cmake already installed, make sure version at least 3.8.0



%=============

Google protobuf

%=============



First, replace old protobuf-3.0.0-alpha-2 

01.  Delete directory ~/Downloads/soa_sample_app/protobuf-3.0.0-aplha-2 
02.  Do *NOT* delete Directory ~/Downloads/soa_sample_app/proto_buff 
03.  Go to
	https://github.com/google/protobuf
04.  Click on the "Branch: master" dropdown button 
05.  Select the "Tags" tab 
07.  Scroll through the list and select v3.0.0-alpha-2
08.  Click on the "Clone or download" button
09.  Click on the "Download ZIP" button
10.  Unzip /Downloads/protobuf-3.0.0-alpha-2.zip
11.  Move the unzipped directory "protobuf-3.0.0-alpha-2" into directory ~/Downloads/soa_sample_app

Next, install new protobuf-3.0.0-alpha-2

12.  Run:
	~/Downloads/protobuf-3.0.0-alpha-2$  ./autogen.sh
	~/Downloads/protobuf-3.0.0-alpha-2$  ./configure
	~/Downloads/protobuf-3.0.0-alpha-2$  make 
        ~/Downloads/protobuf-3.0.0-alpha-2$  make check 
        ~/Downloads/protobuf-3.0.0-alpha-2$  sudo make install



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

Simulator
~/Downloads/soa_sim/

%=============



~/Downloads/screenshots/01

01.  Right click "Soav1.7_Linux.x86_64.exe"
	Permissions tab >> enable "Allow executing file as program"
02.  Double click the "Soav1.7_Linux.x86_64.exe"
	Enable "Windowed"
	Select "Screen resolution" and the "Graphics quality"
  	Ignore the "Input" Tab
  	  	
~/Downloads/screenshots/02

03.  (Optional) Simulator parameters can be found in "SoaSimConfig.xml"
04.  (Optional) Request JHU/APL for access to "Sharepoint" in order to download future releases



%=============

Interface 

%=============



~/Downloads/screenshots/03

01.  Launch Qt Creator
02.  Click on "Open Project"
03.  Select "interface_20JUN16.pro" located here:
	~/Downloads/soa_sample_app/interface_20JUN16/interface_20Jun16.pro

~/Downloads/screenshots/04
~/Downloads/screenshots/05
~/Downloads/screenshots/06
~/Downloads/screenshots/07

04.  Build project 
	Build >> Build Project "interface20JUN16"
05.  Run project
	Build >> Run
	
~/Downloads/screenshots/08



%=============

Notes

%=============



01.  Entry point is main.cpp
	Instantiating an InterfaceWindow object
	Calling method show() since InterfaceWindow inherits QWidget
	http://doc.qt.io/qt-4.8/qwidget.html#show
	Rest of code here is standard Qt code to create a QApplication
02.  Lab convention is member pointers are "m_p" prefixed
03.  InterfaceWindow contains the three widgets -- LogicWidget, TabPanel2, and TaskPanel
04.  LogicWidget responsible for map area
05.  TaskPanelWidget responsible for tasking the simulator 
06.  TabPanel2 displays information regarding actors and tasks
07.  Comments often refer to "JS." JS code is in ~Downloads/soa_sample_app/blarg2/mapWidget/Scripts and LogicWidget via WebView and MapWidget talks to the JS code to place icons on the map. The JS code utilizes a Google Maps API. 

~/Downloads/screenshots/09

08.  interfacewindow and taskpanelwidget come with .ui files in addition to the .h and .cpp pair. You can directly interact with the taskpanelwidget.ui, but not the interfacewindow.ui. To make changes to the layout of the interfacewindow, edit the interfacewindow.cpp's layout pointer.

09.  HMT lab's class modules (can generally be ignored):
	borderlayout
	bytaskpanel
	bytasksidepanelcontainer
	qclicklabel
	qsidepanel
	qsidepanelcontainer
	qsidepanelcontainertabwidget
	
~/Downloads/screenshots/05
	
10.  JHU/APL files that allow the interface to talk to the sim, or API to the sim (do not edit): 
	Belief_Actor.h
	SoaAutonomy.h
	WorldDataManager.h
	WorldLocation.h
     List not exhaustive -- only included items that can be seen in the Active Project View



%=============

End Document

%=============



