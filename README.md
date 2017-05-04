# soa_interface
Human operator interface for SOA simulator



Clone the soa_interface repository <br />
	https://github.com/mhaque3/soa_interface.git<br />
		
This document serves as a setup guide for the operator interface. Screenshots that accompany this guide can be found in ~/Downloads/screenshots.<br /> 



%=============

Components

%=============
	
	

~/Downloads/screenshots/00<br />
 
01.  The interface code lives in ~/Downloads/soa_sample_app<br />
02.  Qt Creator IDE (setup instruction are below) since the interface is built using the Qt framework.<br />  
03.  The simulator lives in ~/Downloads/soa_sim. Additional information is provided below.<br /> 
03.  Google Protocol Buffers (the sim needs these for messaging). Instructions on how to install Google protobuf is provided in this document.<br />



%=============

System

%=============



01.  Ubuntu 14.04 LTS<br />
02.  If autoreconf, boost, cmake, etc not installed:<br />
	$  sudo apt-get install autoconf boost libboost cmake<br />
03.  If cmake already installed, make sure version at least 3.8.0<br />



%=============

Google protobuf

%=============



First, replace old protobuf-3.0.0-alpha-2<br /> 

01.  Delete directory ~/Downloads/soa_sample_app/protobuf-3.0.0-aplha-2<br /> 
02.  Do *NOT* delete Directory ~/Downloads/soa_sample_app/proto_buff<br /> 
03.  Go to<br />
	https://github.com/google/protobuf<br />
04.  Click on the "Branch: master" dropdown button, select the "Tags" tab, and scroll through the list and select v3.0.0-alpha-2<br />
08.  Click on the "Clone or download" and "Download ZIP"<br />
10.  Unzip /Downloads/protobuf-3.0.0-alpha-2.zip<br />
11.  Move the unzipped directory "protobuf-3.0.0-alpha-2" into directory ~/Downloads/soa_sample_app<br />

Next, install new protobuf-3.0.0-alpha-2<br />

12.  Run:<br />
~/Downloads/protobuf-3.0.0-alpha-2$  ./autogen.sh<br />
~/Downloads/protobuf-3.0.0-alpha-2$  ./configure<br />
~/Downloads/protobuf-3.0.0-alpha-2$  make<br />
~/Downloads/protobuf-3.0.0-alpha-2$  make check<br />
~/Downloads/protobuf-3.0.0-alpha-2$  sudo make install<br />



%=============

Qt creator

%=============



01.  Download Qt Creator here:<br />
	https://www.qt.io/ide/<br />
02.  Click on the "Start for Free" button on the image banner<br />
03.  The next window asks about deployment<br />
	Select the radio button "In-house deployment, private use, or student use"<br />
04.  The next window asks about distribution<br />
	Select the "No" radio button<br /> 
05.  The next window asks about compliance<br />
	Select the "Yes" radio button<br />
06.  Click on the "Get Started" button<br />
07.  The next window detects the OS<br />
	Click on the "Download Now" button<br />



%=============

Simulator<br />
~/Downloads/soa_sim/

%=============



~/Downloads/screenshots/01<br />

01.  Right click "Soav1.7_Linux.x86_64.exe"<br />
	Permissions tab >> enable "Allow executing file as program"<br />
02.  Double click the "Soav1.7_Linux.x86_64.exe"<br />
	Enable "Windowed"<br />
	Select "Screen resolution" and the "Graphics quality"<br />
  	Ignore the "Input" Tab<br />
  	  	
~/Downloads/screenshots/02<br />

03.  (Optional) Simulator parameters can be found in "SoaSimConfig.xml"<br />
04.  (Optional) Request JHU/APL for access to "Sharepoint" in order to download future releases<br />



%=============

Interface<br /> 
~/Downloads/soa_sample_app

%=============



~/Downloads/screenshots/03<br />

01.  Launch Qt Creator<br />
02.  Click on "Open Project"<br />
03.  Select "interface_20JUN16.pro" located here:<br />
	~/Downloads/soa_sample_app/interface_20JUN16/interface_20Jun16.pro<br />

~/Downloads/screenshots/04<br />
~/Downloads/screenshots/05<br />
~/Downloads/screenshots/06<br />
~/Downloads/screenshots/07<br />

04.  Build project<br />
	Build >> Build Project "interface20JUN16"<br />
05.  Run project<br />
	Build >> Run<br />
	
~/Downloads/screenshots/08<br />



%=============

Notes

%=============



01.  Entry point is main.cpp<br />
	Instantiating an InterfaceWindow object<br />
	Calling method show() since InterfaceWindow inherits QWidget<br />
	http://doc.qt.io/qt-4.8/qwidget.html#show<br />
	Rest of code here is standard Qt code to create a QApplication<br />
02.  Lab convention is member pointers are "m_p" prefixed<br />
03.  InterfaceWindow contains the three widgets -- LogicWidget, TabPanel2, and TaskPanel<br />
04.  LogicWidget responsible for map area<br />
05.  TaskPanelWidget responsible for tasking the simulator<br />
06.  TabPanel2 displays information regarding actors and tasks<br />
07.  Comments often refer to "JS." JS code is in ~Downloads/soa_sample_app/blarg2/mapWidget/Scripts and LogicWidget via WebView and MapWidget talks to the JS code to place icons on the map. The JS code utilizes a Google Maps API.<br /> 

~/Downloads/screenshots/09<br />

08.  interfacewindow and taskpanelwidget come with .ui files in addition to the .h and .cpp pair. You can directly interact with the taskpanelwidget.ui, but not the interfacewindow.ui. To make changes to the layout of the interfacewindow, edit the interfacewindow.cpp's layout pointer.<br />

09.  HMT lab's class modules (can generally be ignored):<br />
	borderlayout<br />
	bytaskpanel<br />
	bytasksidepanelcontainer<br />
	qclicklabel<br />
	qsidepanel<br />
	qsidepanelcontainer<br />
	qsidepanelcontainertabwidget<br />
	
~/Downloads/screenshots/05<br />
	
10.  JHU/APL files that allow the interface to talk to the sim, or API to the sim (do *NOT* edit):<br /> 
	Belief_Actor.h<br />
	SoaAutonomy.h<br />
	WorldDataManager.h<br />
	WorldLocation.h<br />
     List not exhaustive -- only included items that can be seen in the Active Project View<br />



%=============

End Document

%=============



