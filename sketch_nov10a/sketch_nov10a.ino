#include <VirtualWire.h>

// #define TRIG 2
#define MSG 4
// #define ECHO A3
// int du;
// char buf[8];

void setup() {
  // put your setup code here, to run once:
  vw_setup(1000);
  // pinMode(ECHO,INPUT);
  pinMode(MSG,OUTPUT);
  // pinMode(TRIG,OUTPUT);
  vw_set_tx_pin(MSG);
}

void loop() {
  // put your main code here, to run repeatedly:
  // send("T1");
  // digitalWrite(TRIG,LOW);
  // delayMicroseconds(200);
  // digitalWrite(TRIG,HIGH);
  // delayMicroseconds(1000);
  // digitalWrite(TRIG,LOW);
  // du = pulseIn(ECHO,HIGH);
  // Serial.print(du);
  // dtostrf(du,0,3,buf);
  // itoa(du,buf,10); // "1: xxx" "2: xxx"
  // Base station: "1: xxx*.0343/2"
  send("Y");
  delay(100000); // 360000000 4294967295
}


void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
}

