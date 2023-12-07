#include <VirtualWire.h>
#include "tinysnore.h"

#define MSG  4
#define TRIG 2
#define ECHO 3
uint16_t du;
char buf[17];

void setup() {
  // put your setup code here, to run once:
  vw_setup(2000);
  pinMode(ECHO,INPUT);
  pinMode(MSG,OUTPUT);
  pinMode(TRIG,OUTPUT);
  vw_set_tx_pin(MSG);
  vw_set_tx_header_to(0x00);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG,LOW);
  delayMicroseconds(1000);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(1000);
  digitalWrite(TRIG,LOW);
  du = pulseIn(ECHO,HIGH);
  // du += 10000;
  itoa(du,buf,10); // "10xxx" "20xxx" "xxx"
  send(buf);
  snore(30000); // 360000000 4294967295
}


void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(MSG, LOW);
}

