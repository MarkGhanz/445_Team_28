#include <Manchester.h>
#include "tinysnore.h"

#define TX_PIN 4
#define TRIG 2
#define ECHO 3
// int du;
uint16_t data = 511;

void setup() {
  // put your setup code here, to run once:
  man.setupTransmit(TX_PIN, MAN_2400);
  pinMode(ECHO,INPUT);
  pinMode(TRIG,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(TRIG,LOW);
  // delayMicroseconds(4);
  // digitalWrite(TRIG,HIGH);
  // delayMicroseconds(20);
  // digitalWrite(TRIG,LOW);
  // du = pulseIn(ECHO,HIGH) * 10 + 1;
  man.transmit(data);
  snore(1000);
}
