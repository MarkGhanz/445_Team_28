#include <Manchester.h>

#define RX_PIN 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  man.setupReceive(RX_PIN,MAN_2400);
  man.beginReceive();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (man.receiveComplete()) {
    uint16_t m = man.getMessage();
    Serial.print(m);
    Serial.println();
    man.beginReceive(); //start listening for next message right after you retrieve the message
  }
}
