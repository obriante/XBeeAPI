/*
 *
 * The arduino XBeeAPI library facilitate the management, of XBee Devices configured in API Mode
 * Copyright (C) 2013-2014  Orazio Briante orazio.briante@unirc.it
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


XBeeAddress64	remoteAddress64_BRD = XBeeAddress64(0x00000000, 0x0000FFFF);
uint8_t			msg[]={'I','\'','m',' ','E', 'n', 'd', ' ', 'D','e','v','i','c','e'};

/*
void CoordinatorRX(int timeout){

		switch(recvAll(timeout)){

		case 0:
			printApiID();
			break;

		case 1:
			printZBRxResponse(getZBRxResponse());
			DSerial.println(" ");
			break;

		case 2:
			printZBTxStatusResponse(getZBTxStatusResponse());
			DSerial.println(" ");
			break;

		case 3:
			printModemStatusResponse(getModemStatusResponse());
			DSerial.println(" ");
			break;

		case 4:
			printRemoteAtCommandResponse(getRemoteAtCommandResponse());
			DSerial.println(" ");
			break;

		case 5:
			printZBRxIoSampleResponse(getZBRxIoSampleResponse());
			DSerial.println(" ");
			break;

		case 6:
			printAtCommandResponse(getAtCommandResponse());
			DSerial.println(" ");
			break;


		default:
			printApiID();
			break;

		}
}

void CoordinatorRX(){
  
		switch(recvAll()){

		case 0:
			printApiID();
			break;

		case 1:
			printZBRxResponse(getZBRxResponse());
  		        sendZBTxRequest(remoteAddress64_BRD, msg, sizeof(msg));
			DSerial.println(" ");
			break;

		case 2:
			printZBTxStatusResponse(getZBTxStatusResponse());
			DSerial.println(" ");
			break;

		case 3:
			printModemStatusResponse(getModemStatusResponse());
			DSerial.println(" ");
			break;

		case 4:
			printRemoteAtCommandResponse(getRemoteAtCommandResponse());
			DSerial.println(" ");
			break;

		case 5:
			printZBRxIoSampleResponse(getZBRxIoSampleResponse());
			DSerial.println(" ");
			break;

		case 6:
			printAtCommandResponse(getAtCommandResponse());
			DSerial.println(" ");
			break;


		default:
			printApiID();
			break;

		}
}
*/
// MAIN

//XBeeAddress64	remoteAddress64_BRD = XBeeAddress64(0x00000000, 0x0000FFFF);
//uint8_t			msg[]={'I','\'','m',' ','E', 'n', 'd', ' ', 'D','e','v','i','c','e'};

void setup(){

	DSerial.begin(9600);
	DSerial.println(" ");
	DSerial.println("Start");

	Serial.begin(9600)
	xbee.begin(Serial);
	DSerial.println("Waiting Message..");
}

void loop() {

if(recvZBRxResponse()){
        printZBRxResponse(getZBRxResponse());
	DSerial.println(" ");
	sendZBTxRequest(remoteAddress64_BRD, msg, sizeof(msg));
	DSerial.println("Response Sent.");
	DSerial.println(" ");
}
		
}
