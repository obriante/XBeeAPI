#ifndef XBEEAPI_H_
#define XBEEAPI_H_

#include <XBee.h>

void sendZBTxRequest(XBeeAddress64 remoteAddress64, uint8_t *payload, int length);
void sendAtCommandRequest(uint8_t *cmd);
void sendAtCommandRequest(uint8_t *cmd, uint8_t *value, int vlength);
void sendRemoteAtCommandRequest(uint16_t remoteAddress16, uint8_t *cmd, uint8_t *value, int vlength);
void sendRemoteAtCommandRequest(uint16_t remoteAddress16, uint8_t *cmd);

/*
 * return:
 *
 * 1 ZB_RX_RESPONSE
 * 2 ZB_TX_STATUS_RESPONSE
 * 3 MODEM_STATUS_RESPONSE
 * 4 REMOTE_AT_COMMAND_RESPONSE
 * 5 ZB_IO_SAMPLE_RESPONSE
 * 0 Other
 * -1 Timeout
 */
int recvAll(int timeout);

/*
 * return:
 *
 * 1 ZB_RX_RESPONSE
 * 2 ZB_TX_STATUS_RESPONSE
 * 3 MODEM_STATUS_RESPONSE
 * 4 REMOTE_AT_COMMAND_RESPONSE
 * 0 Other
 */
int recvAll();

boolean recvZBRxResponse();
boolean recvZBTxStatusResponse();
boolean recvModemStatusResponse();
boolean recvRemoteAtCommandResponse();
boolean recvZBRxIoSampleResponse();
boolean recvAtCommandResponse();

boolean recvZBRxResponse(int timeout);
boolean recvZBTxStatusResponse(int timeout);
boolean recvModemStatusResponse(int timeout);
boolean recvRemoteAtCommandResponse(int timeout);
boolean recvZBRxIoSampleResponse(int timeout);
boolean recvAtCommandResponse(int timeout);

ZBRxResponse getZBRxResponse();
ZBTxStatusResponse getZBTxStatusResponse();
ModemStatusResponse getModemStatusResponse();
RemoteAtCommandResponse getRemoteAtCommandResponse();
ZBRxIoSampleResponse getZBRxIoSampleResponse();
AtCommandResponse getAtCommandResponse();


#endif /* XBEEAPI_H_ */
