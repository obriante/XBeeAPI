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

	xbee.begin(9600);
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
