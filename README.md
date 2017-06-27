# robot_1
This project is developed for SHU to take in the RoboCup

## Develop Enviroment
Qt Creator 4.2.0 (4.2.0)  
Based on Qt 5.7.1 (MSVC 2015, 32 bit)  

## Running Test Enviroment
Windows 10 X64  

## Files Struct
robot_1.pro  
head files  
&ensp;&ensp;├mainwindow.h  
&ensp;&ensp;├robot.h  
&ensp;&ensp;└robotcontroller.h  
source files  
&ensp;&ensp;├main.cpp  
&ensp;&ensp;├mainwindow.cpp  
&ensp;&ensp;├robot.cpp  
&ensp;&ensp;└robotcontroller.cpp  
ui files  
&ensp;&ensp;└mainwindow.ui

## Protocal
### Serial Port
#### GENERAL
|START    |COMMAND|DATA    |CHECKSUM|
|:-------:|:-----:|:------:|:------:|
|0xA5 0x5A|(1 Byte)|(n Bytes)|(1 Byte) |
#### MOVE DATA
|START|COMMAND|DATA|CHECKSUM|
|:---:|:-----:|:--:|:------:|
|0-1|2|3 - 5|6|
|0xA5 0x5A|0x00|0x20 0x03 0xA4|0xC6|  

|Byte|Name|Description|
|:--:|:--:|:---------:|
|2|COMMAND|Move data command|
|3|DATA|The distance of x axis in 10 ms. (0.01m)|
|4|DATA|The distance of y axis in 10 ms. (0.01m)|
|5|DATA|The angle of Theta in 10 ms. (0.01deg)|

### UDP Socket
#### GENERAL
|ADDR|COMMAND|DATA|CHECKSUM|
|:--:|:-----:|:--:|:------:|
|(1 Byte)|(1 Byte)|(n Bytes)|(1 Byte)|
