#include <XBee.h>
#include <SoftwareSerial.h>

#include <XBeeAPI.h>
#include <XBeeAPIDebug.h>

XBee	xbee = XBee();
SoftwareSerial	DSerial(9,10);

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

// MAIN

XBeeAddress64	remoteAddress64_BRD = XBeeAddress64(0x00000000, 0x0000FFFF);
uint16_t        remoteAddress16_BRD = 0x0000FFFF;
uint8_t         msg[]={'I','\'','m',' ','C','o','o','r','d','i','n','a','t','o','r'};

void setup(){

	DSerial.begin(9600);
	DSerial.println("");
	DSerial.println("Start..");

	xbee.begin(9600);
}

void loop() {

sendZBTxRequest(remoteAddress64_BRD, msg, sizeof(msg));
DSerial.println("ZBTxRequest sent!");

CoordinatorRX(2000);
CoordinatorRX(2000);

delay(1000);
}
