/*
 * XbeeAPI.cpp
 *
 *  Created on: Oct 21, 2012
 *      Author: kmonkey
 */

#include "XBeeAPI.h"
//#include "XBeeAPIDebug.h"


extern	XBee	xbee;
//extern	SoftwareSerial	DSerial;

void sendZBTxRequest(XBeeAddress64 remoteAddress64, uint8_t *payload, int length){

	ZBTxRequest zbTX = ZBTxRequest(remoteAddress64, payload, length);
	xbee.send(zbTX);
}

void sendAtCommandRequest(uint8_t *cmd){

	AtCommandRequest atRequest = AtCommandRequest(cmd);
	xbee.send(atRequest);

}

void sendAtCommandRequest(uint8_t *cmd, uint8_t *value, int vlength){

	AtCommandRequest atRequest = AtCommandRequest(cmd, value, sizeof(vlength));
	xbee.send(atRequest);
}

void sendRemoteAtCommandRequest(uint16_t remoteAddress16, uint8_t *cmd, uint8_t *value, int vlength){

	RemoteAtCommandRequest remoteAT = RemoteAtCommandRequest(remoteAddress16, cmd, value, sizeof(vlength));
	xbee.send(remoteAT);
}

void sendRemoteAtCommandRequest(uint16_t remoteAddress16, uint8_t *cmd){

	RemoteAtCommandRequest remoteAT = RemoteAtCommandRequest(remoteAddress16, cmd);
	xbee.send(remoteAT);
}

/*
 * return:
 *
 * 1 ZB_RX_RESPONSE
 * 2 ZB_TX_STATUS_RESPONSE
 * 3 MODEM_STATUS_RESPONSE
 * 4 REMOTE_AT_COMMAND_RESPONSE
 * 5 ZB_IO_SAMPLE_RESPONSE
 * 6 AT_RESPONSE
 * 0 Other
 * -1 None
 */
int _recvAll(){

	uint8_t api_id=xbee.getResponse().getApiId();

	if (api_id == ZB_RX_RESPONSE)
		return 1;

	else if (api_id == ZB_TX_STATUS_RESPONSE)
		return 2;

	else if (api_id == MODEM_STATUS_RESPONSE)
		return 3;

	else if (api_id  == REMOTE_AT_COMMAND_RESPONSE)
		return 4;

	else if (api_id == ZB_IO_SAMPLE_RESPONSE)
		return 5;

	else if(api_id == AT_RESPONSE)
		return 6;

	else
		return 0;

	return -1;
}


/*
 * return:
 *
 * 1 ZB_RX_RESPONSE
 * 2 ZB_TX_STATUS_RESPONSE
 * 3 MODEM_STATUS_RESPONSE
 * 4 REMOTE_AT_COMMAND_RESPONSE
 * 5 ZB_IO_SAMPLE_RESPONSE
 * 6 AT_RESPONSE
 * 0 Other
 * -1 Timeout
 */
int recvAll(int timeout){
	if(xbee.readPacket(timeout))
		if (xbee.getResponse().isAvailable())
			return _recvAll();

	return -1;
}

/*
 * return:
 *
 * 1 ZB_RX_RESPONSE
 * 2 ZB_TX_STATUS_RESPONSE
 * 3 MODEM_STATUS_RESPONSE
 * 4 REMOTE_AT_COMMAND_RESPONSE
 * 5 ZB_IO_SAMPLE_RESPONSE
 * 6 AT_RESPONSE
 * 0 Other
 * -1 None
 */
int recvAll(){
	xbee.readPacket();
	return _recvAll();
}

/*
 * api_id:
 *
 * 1 ZB_RX_RESPONSE
 * 2 ZB_TX_STATUS_RESPONSE
 * 3 MODEM_STATUS_RESPONSE
 * 4 REMOTE_AT_COMMAND_RESPONSE
 * 5 ZB_IO_SAMPLE_RESPONSE
 * 6 AT_RESPONSE
 * 0 Other
 * -1 Timeout
 */
boolean __recvAll(int timeout, int api_id){

	unsigned long previousMillis=millis();
	unsigned long currentMillis=0;

	////DSerial.print("previousMillis: ");
	////DSerial.println(previousMillis);
	int _timeout=timeout;

	//DSerial.print("timeout: ");
	//DSerial.println(_timeout);

	int api=-1;

	while(api != api_id && _timeout > 0 ){
		//DSerial.println("While");

		if(xbee.readPacket(_timeout)){

			//DSerial.print("currentMillis: ");
			//DSerial.println(currentMillis);

			if (xbee.getResponse().isAvailable()){

				if(_recvAll()==api_id)
					return true;
			}

		}

		currentMillis=millis();
		_timeout=_timeout-((int)(currentMillis-previousMillis));
		//DSerial.print("_timeout: ");
		//DSerial.println(_timeout);
	}

	return false;
}

/*
 * api_id:
 *
 * 1 ZB_RX_RESPONSE
 * 2 ZB_TX_STATUS_RESPONSE
 * 3 MODEM_STATUS_RESPONSE
 * 4 REMOTE_AT_COMMAND_RESPONSE
 * 5 ZB_IO_SAMPLE_RESPONSE
 * 6 AT_RESPONSE
 * 0 Other
 * -1 None
 */
boolean __recvAll(int api_id){
	while(true){
			xbee.readPacket();
			if (xbee.getResponse().isAvailable()){
					if(_recvAll()==api_id)
						return true;

				}
			}


	return false;
}

ZBRxResponse getZBRxResponse(){
	ZBRxResponse response=ZBRxResponse();

	if (xbee.getResponse().getApiId() == ZB_RX_RESPONSE)
		xbee.getResponse().getZBRxResponse(response);

	return response;
}

ZBTxStatusResponse getZBTxStatusResponse(){
	ZBTxStatusResponse response=ZBTxStatusResponse();

	if (xbee.getResponse().getApiId() == ZB_TX_STATUS_RESPONSE)
		xbee.getResponse().getZBTxStatusResponse(response);

	return response;
}

ModemStatusResponse getModemStatusResponse(){
	ModemStatusResponse response=ModemStatusResponse();

	if (xbee.getResponse().getApiId() == MODEM_STATUS_RESPONSE)
		xbee.getResponse().getModemStatusResponse(response);

	return response;
}

RemoteAtCommandResponse getRemoteAtCommandResponse(){
	RemoteAtCommandResponse response=RemoteAtCommandResponse();

	if (xbee.getResponse().getApiId() == REMOTE_AT_COMMAND_RESPONSE)
		xbee.getResponse().getRemoteAtCommandResponse(response);

	return response;
}

ZBRxIoSampleResponse getZBRxIoSampleResponse(){
	ZBRxIoSampleResponse response=ZBRxIoSampleResponse();

	if (xbee.getResponse().getApiId() == ZB_IO_SAMPLE_RESPONSE)
		xbee.getResponse().getAtCommandResponse(response);

	return response;
}

AtCommandResponse getAtCommandResponse(){
	AtCommandResponse response=AtCommandResponse();

	if (xbee.getResponse().getApiId() == AT_RESPONSE)
		xbee.getResponse().getAtCommandResponse(response);

	return response;
}

boolean recvZBRxResponse(){
	if(__recvAll(1))
		return true;
	else
		return false;

}

boolean recvZBRxResponse(int timeout){
	if(__recvAll(timeout,1))
		return true;
	else
		return false;

}

boolean recvZBTxStatusResponse(){

	if(__recvAll(2))
		return true;
	else
		return false;

}

boolean recvZBTxStatusResponse(int timeout){

	if(__recvAll(timeout, 2))
		return true;
	else
		return false;

}

boolean recvModemStatusResponse(){
	if(__recvAll(3))
		return true;
	else
		return false;

}

boolean recvModemStatusResponse(int timeout){

	if(__recvAll(timeout, 3))
		return true;
	else
		return false;
}

boolean recvRemoteAtCommandResponse(){

	if(__recvAll(4))
		return true;
	else
		return false;
}

boolean recvRemoteAtCommandResponse(int timeout){

	if(__recvAll(timeout,4))
		return true;
	else
		return false;
}

boolean recvZBRxIoSampleResponse(){
	if(__recvAll(5))
		return true;
	else
		return false;

}

boolean recvZBRxIoSampleResponse(int timeout){

	if(__recvAll(timeout,5))
		return true;
	else
		return false;

}

boolean recvAtCommandResponse(){

	//DSerial.println("recvAtCommandResponse");
	if(__recvAll(6))
		return true;
	else
		return false;
}

boolean recvAtCommandResponse(int timeout){

	//DSerial.println("recvAtCommandResponse");
	if(__recvAll(timeout,6))
		return true;
	else
		return false;
}
