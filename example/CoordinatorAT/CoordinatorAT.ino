/*
 *
 * The arduino XBeeAPI library facilitate the management, of XBee Devices configured in API Mode
 * Copyright (C) 2013  Orazio Briante orazio.briante@unirc.it
 * Laboratory A.R.T.S. - University Mediterranea of Reggio Calabria - Faculty of Engineering
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <XBee.h>
#include <SoftwareSerial.h>

#include <XBeeAPI.h>
#include <XBeeAPIDebug.h>

XBee	xbee = XBee();
SoftwareSerial	DSerial(9,10);

// MAIN

XBeeAddress64	remoteAddress64_BRD = XBeeAddress64(0x00000000, 0x0000FFFF);
uint16_t        remoteAddress16_BRD = 0x0000FFFF;
uint8_t         msg[]={0x00};

void setup(){

	DSerial.begin(9600);
	DSerial.println("");
	DSerial.println("Start..");

	xbee.begin(9600);

}

void loop() {
  
sendAtCommandRequest((uint8_t*)"NI");
if(recvAtCommandResponse(3000)){
 printAtCommandResponse(getAtCommandResponse());
 DSerial.println(" "); 
}
 delay(1000);

sendAtCommandRequest((uint8_t*)"ND");
if(recvAtCommandResponse(3000)){
 printAtCommandResponse(getAtCommandResponse());
 DSerial.println(" "); 
}
 delay(1000);

sendAtCommandRequest((uint8_t*)"ID");
if(recvAtCommandResponse(3000)){
 printAtCommandResponse(getAtCommandResponse());
 DSerial.println(" "); 
}
 delay(1000);

sendRemoteAtCommandRequest(remoteAddress16_BRD, (uint8_t*)"NI");
if(recvRemoteAtCommandResponse(3000)){
 printRemoteAtCommandResponse(getRemoteAtCommandResponse());
 DSerial.println(" "); 
}
 delay(1000);

sendRemoteAtCommandRequest(remoteAddress16_BRD, (uint8_t*)"ND");
if(recvRemoteAtCommandResponse(3000)){
 printRemoteAtCommandResponse(getRemoteAtCommandResponse());
 DSerial.println(" "); 
}
 delay(1000);

sendRemoteAtCommandRequest(remoteAddress16_BRD, (uint8_t*)"ID");
if(recvRemoteAtCommandResponse(3000)){
 printRemoteAtCommandResponse(getRemoteAtCommandResponse());
 DSerial.println(" "); 
}

delay(1000);
}
