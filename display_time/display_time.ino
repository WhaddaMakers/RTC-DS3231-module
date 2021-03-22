/*

Prints the current time in serial monitor using getXXX functions


Based on DS3231_set.pde
by Eric Ayars
4/11

Added printing back of time stamps and increased baud rate
(to better synchronize computer and RTC)
Andy Wickert
5/15/2011

Added help text and changed baudrate to standard 9600
Whadda (Velleman)
22/03/2021

*/

#include <DS3231.h>
#include <Wire.h>

DS3231 clock;

bool century = false;
bool h12Flag;
bool pmFlag;

void setup() {
	// Start the serial port
	Serial.begin(9600);

  Serial.println("Whadda RTC DS3231 MODULE TIME READOUT PROGRAM");
  Serial.println("=============================================");
  Serial.println();

  Serial.println("Time will be displayed in the following format: YY-(M)M-(D)D (H)H-(M)M-(S)S");
  Serial.println();
	// Start the I2C interface
	Wire.begin();
}

void loop() {
  delay(1000);
      Serial.print(clock.getYear(), DEC);
      Serial.print("-");
      Serial.print(clock.getMonth(century), DEC);
      Serial.print("-");
      Serial.print(clock.getDate(), DEC);
      Serial.print(" ");
      Serial.print(clock.getHour(h12Flag, pmFlag), DEC); //24-hr
      Serial.print(":");
      Serial.print(clock.getMinute(), DEC);
      Serial.print(":");
      Serial.println(clock.getSecond(), DEC);
}
