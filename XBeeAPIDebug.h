/*
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
