/*
 * XBeeAPIDebug.h
 *
 *  Created on: Oct 21, 2012
 *      Author: kmonkey
 */

#ifndef XBEEAPIDEBUG_H_
#define XBEEAPIDEBUG_H_

#include <XBee.h>
#include <SoftwareSerial.h>

void printXBeeAddress64(XBeeAddress64 address);
void printXBeeAddress16(uint16_t address);

void printApiID();

void printRemoteAtCommandResponse(RemoteAtCommandResponse response);
void printAtCommandResponse(AtCommandResponse response);
void printModemStatusResponse(ModemStatusResponse response);
void printZBTxStatusResponse(ZBTxStatusResponse response);
void printZBRxResponse(ZBRxResponse response);
void printZBRxIoSampleResponse(ZBRxIoSampleResponse response);


#endif /* XBEEAPIDEBUG_H_ */
