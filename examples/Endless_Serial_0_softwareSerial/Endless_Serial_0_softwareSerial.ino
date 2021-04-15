/*
  Infinite loop serial test

  Receives from the Serial Monitor on the hardware serial 0 port and sends back. 
  The serial 0 Tx signal is also fed to a softwareSerial Rx pin.
  When the software serial receives it writes again from hadware Serial 0. 
  Hence it loops endlessly whatever you type in the Serial Monitor

  The circuit:
  - On the 644/1284 Regular or Power variants
  - A cable connected betwwen pin "1" (hardware serial TX) and pin "8" (software serial Rx
  - Serial Monitor open on Serial port 0

*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(8,9); // RX, TX

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  // reads from softwareSerial port, sends to hardware serial port 0:
  if (mySerial.available()) {
    int inByte = mySerial.read();
    Serial.write(inByte);
  }

  // reads from hardware serial port 0, sends to serialMonitor and softwareSerial port:
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial.write(inByte);
  }
}
