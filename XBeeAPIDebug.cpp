
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

#include "XBeeAPIDebug.h"
#include "XBeeAPI.h"

extern SoftwareSerial DSerial;
extern XBee xbee;


void
printXBeeAddress64(XBeeAddress64 address)
{
  DSerial.print("64-bit XBee Address : 0x");
  DSerial.print(address.getMsb(), HEX);
  DSerial.println(address.getLsb(), HEX);
}

void
printXBeeAddress16(uint16_t address)
{
  DSerial.print("16-bit XBee Address: 0x");
  DSerial.println(address, HEX);

}

void
printApiID()
{
  uint8_t api_id = xbee.getResponse().getApiId();

  if (api_id > 0) {
    DSerial.print("Api ID: 0x");
    DSerial.println(api_id, HEX);
    DSerial.println(" ");
  }
}


void
printRemoteAtCommandResponse(RemoteAtCommandResponse response)
{

  printXBeeAddress64(response.getRemoteAddress64());
  printXBeeAddress16(response.getRemoteAddress16());

  DSerial.print("Remote AT Command RX Packet: ");
  DSerial.print((char *)response.getCommand());
  DSerial.println(" ");

  DSerial.print("Response: ");
  if (response.isOk())
    DSerial.println("OK");

  else if (response.isError())
    DSerial.println("ERROR");


  uint8_t *value = response.getValue();

  DSerial.print("Value: ");
  for (int i = 0; i <= response.getFrameDataLength(); i++)
    DSerial.print((char)value[i]);
  DSerial.println(" ");

  DSerial.print("Value: ");
  for (int i = 0; i <= response.getFrameDataLength(); i++) {
    DSerial.print("0x");
    DSerial.print(value[i], HEX);
    DSerial.print(" ");
  }

  DSerial.println(" ");

}

void
printAtCommandResponse(AtCommandResponse response)
{

  DSerial.print("AT Command: ");
  DSerial.print((char *)response.getCommand());
  DSerial.println(" ");

  DSerial.print("Response: ");

  if (response.isOk())
    DSerial.println("OK");

  else if (response.isError())
    DSerial.println("ERROR");

  uint8_t *value = response.getValue();
  int vLength = response.getFrameDataLength();

  DSerial.print("Value: ");

  for (int i = 0; i <= response.getFrameDataLength(); i++)
    DSerial.print((char)value[i]);

  DSerial.println(" ");

  DSerial.print("Value: ");
  for (int i = 0; i <= response.getFrameDataLength(); i++) {
    DSerial.print("0x");
    DSerial.print(value[i], HEX);
    DSerial.print(" ");
  }

  DSerial.println(" ");


}

void
printModemStatusResponse(ModemStatusResponse response)
{

  DSerial.print("Modem Status RX Packet: ");

  if (response.getStatus() == ASSOCIATED)
    DSerial.println("ASSOCIATED");

  else if (response.getStatus() == DISASSOCIATED)
    DSerial.println("DISASSOCIATED");

  else
    DSerial.println("OTHER");

}

void
printZBTxStatusResponse(ZBTxStatusResponse response)
{

  printXBeeAddress16(response.getRemoteAddress());

  DSerial.print("TX Status Packet: ");

  if (response.getDeliveryStatus() == SUCCESS)
    DSerial.println("SUCCESS");

  else
    DSerial.println("ERROR");

}

void
printZBRxResponse(ZBRxResponse response)
{

  printXBeeAddress64(response.getRemoteAddress64());
  printXBeeAddress16(response.getRemoteAddress16());

  DSerial.print("RX packet: ");


  if (response.getOption() != ZB_PACKET_ACKNOWLEDGED)
    DSerial.println(" ACKNOWLEDGED");

  uint8_t *rxData = response.getData();
  int rxLength = response.getDataLength();

  DSerial.print("Payload Length: ");
  DSerial.println(rxLength);
  DSerial.println(" ");

  DSerial.print("Payload: ");

  for (int i = 0; i <= rxLength; i++)
    DSerial.print((char)rxData[i]);
  DSerial.println(" ");

  DSerial.print("Value: ");
  for (int i = 0; i <= rxLength; i++) {
    DSerial.print("0x");
    DSerial.print(rxData[i], HEX);
    DSerial.print(" ");
  }

  DSerial.println(" ");
}

void
printZBRxIoSampleResponse(ZBRxIoSampleResponse response)
{

  printXBeeAddress64(response.getRemoteAddress64());
  printXBeeAddress16(response.getRemoteAddress16());

  DSerial.println("RX I/O Sample packet: ");

  if (response.containsAnalog()) {
    DSerial.print("Analog Mask: ");
    DSerial.println(response.getAnalogMask(), HEX);
    DSerial.println(" ");
    for (int i = 0; i <= 7; i++) {
      DSerial.print("Pin ");
      DSerial.print(i);
      DSerial.print(": ");
      DSerial.println(response.getAnalog(i));
    }
  } else if (response.containsDigital()) {
    DSerial.print("Digital Mask Msb: ");
    DSerial.println(response.getDigitalMaskMsb());
    DSerial.print("Digital Mask Lsb: ");
    DSerial.println(response.getDigitalMaskLsb());

    for (int i = 0; i <= 7; i++) {
      DSerial.print("Pin ");
      DSerial.print(i);
      DSerial.print(": ");

      if (response.isDigitalOn(i))
        DSerial.println("High");
      else
        DSerial.println("Low");
    }
  } else {
    DSerial.println("Unknown Content!");
  }
}
