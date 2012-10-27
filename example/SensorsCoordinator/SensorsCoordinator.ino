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
