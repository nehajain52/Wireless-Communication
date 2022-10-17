#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <printf.h>

RF24 radio(2,15);   // declaring CE and CSN pins
String text;
const byte address[] = "00001"; 
void setup() {
  Serial.begin(9600);
  radio.begin();  // initializes the operations of the chip
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();    
  printf_begin();

  radio.printDetails();
}
                                                                          

void loop() {
  while(Serial.available()>0) //Get values from user
  { 
           text = Serial.readString();   
  }
  //const char text[]="Hey";
  radio.write(&text,sizeof(text));
  text="";
  delay(1000); 
}
