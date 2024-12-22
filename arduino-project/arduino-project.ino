#include <SPI.h>
#include <Wire.h>

void setup() {
  Serial.begin(19200);

  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  pinMode(SS,OUTPUT);
  Serial1.begin(9600);
  Wire.begin();
}

void loop() {

  while (Serial.available()) {
    Serial.println("input> ");

    String input = Serial.readString();
    input.trim();
    
    if (input == "uart") {
      Serial.println("in uart");
      while (!Serial.available()) {
        input = Serial.readString();
	      input.trim();

        if (input == "1"){
          // send numbers 0-9 via uart
          for (int i = 0; i < 10; i++) {
            Serial1.print(i);
          }
          Serial.println("sending uart");
        } else if (input == "back") {
          Serial.println("going back");
          break;
        }
      }
    } else if (input == "spi") {
      Serial.println("in spi");
      while (!Serial.available()) {
        input = Serial.readString();
        input.trim();

        if (input == "1") {
          // send strings "this is spi" via spi
          Serial.println("sending spi");
          String message = "this is spi";

          for (int i = 0; i < message.length(); i++) {
            byte data = message[i];
            SPI.transfer(data);
          }
        } else if (input == "back") {
          Serial.println("going back");
          break;
        }
      }
    } else if (input == "i2c") {
      while (!Serial.available()) {
        input = Serial.readString();
        input.trim();

        if (input == "1") {
          // scans for devices on i2c bus
          Serial.println("sending i2c");
 
          for (byte address = 1; address < 127; address++) {
            Wire.beginTransmission(address);
            byte error = Wire.endTransmission();
    
            if (error == 0) {
              Serial.print("Device found at address: ");
              Serial.println(address, DEC);
            }
          }
        } else if (input == "back") {
          Serial.println("going back");
          break;
        }
      }
    } else {
      Serial.println("try again");
    }
  }
}
