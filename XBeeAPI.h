
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

#ifndef XBEEAPI_H_
#define XBEEAPI_H_

#include <XBee.h>

void sendZBTxRequest(XBeeAddress64 remoteAddress64, uint8_t * payload, int length);
void sendAtCommandRequest(uint8_t * cmd);
void sendAtCommandRequest(uint8_t * cmd, uint8_t * value, int vlength);
void sendRemoteAtCommandRequest(uint16_t remoteAddress16, uint8_t * cmd, uint8_t * value, int vlength);
void sendRemoteAtCommandRequest(uint16_t remoteAddress16, uint8_t * cmd);

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
