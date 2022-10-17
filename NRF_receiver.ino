#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>
#include <printf.h>

#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(2,15); // declaring CE and CSN pins
const byte address[] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin(); // initializes the operations of the chip
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  printf_begin();

  radio.printDetails();
}


void loop() {
  if(radio.available()){
    char text[32] = "emp";
    radio.read(&text,sizeof(text));
    Serial.print(text);
  }
}
