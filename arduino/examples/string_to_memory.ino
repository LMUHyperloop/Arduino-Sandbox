#include <Wire.h>
#include "Adafruit_FRAM_I2C.h"

/* Example code for the Adafruit I2C FRAM breakout */
/* Author: Anthony Keba */

/* Connect SCL    to analog 5 for Uno, D21 for Mega
   Connect SDA    to analog 4 for Uno, D20 for Mega
   Connect VDD    to 5.0V DC
   Connect GROUND to common ground */

Adafruit_FRAM_I2C fram     = Adafruit_FRAM_I2C();
uint16_t          framAddr = 0;

void setup(void) {
  Serial.begin(9600);

  if (fram.begin()) {  // you can stick the new i2c addr in here, e.g. begin(0x51);
    Serial.println("Found I2C FRAM");
  } else {
    Serial.println("I2C FRAM not identified ... check your connections?\r\n");
    Serial.println("Will continue in case this processor doesn't support repeated start\r\n");
  }




  // Read the first byte
  uint8_t test = fram.read8(0x0);
  Serial.print("Restarted "); Serial.print(test); Serial.println(" times");
  // Test write ++
  if (test == 255) {
    test = 0;
  }
  fram.write8(0x0, test + 1);






  // dump the first 100 bytes of memory!
  uint8_t value;
  String message = "The higher we soar the smaller we appear to those who cannot fly.";
  // message = "Hello, world!";

  uint8_t charMessage[message.length() + 1]; // Array is length +1 because strings use a "00" character to show when it ends. We should capture that in our array
  message.toCharArray(charMessage, sizeof(charMessage)); // first param of toCharArray is the buffer it will be stored in

  
  for (uint16_t a = 0; a < sizeof(charMessage); a++) { // writes each character of the array to the FRAM chip
    fram.write8(a + 1, charMessage[a]);
  }
  
  for(uint16_t block = 0; block < 16; block++){  //outer loop, to go through 16 blocks of memory
    Serial.print("0x"); Serial.print(block, HEX); //begin each line with a header showing the memory address
    if(block < 16) Serial.print("0");
    Serial.print(": "); // finish printing header
    for(uint16_t row = 0; row < 16; row++){ // inner loop going through each 16 bytes of the block
      value = fram.read8((block * 16) + row); // read from FRAM at block * 32 (bytes in a row) + row
      Serial.print(value, HEX);
      if(value < 16) Serial.print('0'); //if the value is only one hex char, append a 0 so everything lines up.
    }
    Serial.print("    ");
    for(uint16_t row = 0; row < 32; row++){
      value = fram.read8((block * 32) + row); 
      Serial.print(char(value)); //attempt to interpret the bytes as ASCII
    }
    
    Serial.println();
  }
}

void loop(void) {

}
