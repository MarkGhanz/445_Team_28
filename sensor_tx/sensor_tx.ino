#include <tinysnore.h>

#include <RHCRC.h>
#include <RHGenericDriver.h>
#include <RH_ASK.h>
#include <RadioHead.h>

// ask_transmitter.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module
// Tested on Arduino Mega, Duemilanova, Uno, Due, Teensy, ESP-12

#define TRIG 2
#define ECHO 3
char buf[17];
RH_ASK driver(2000,0,4,0);

void setup()
{
#ifdef RH_HAVE_SERIAL
    Serial.begin(9600);	  // Debugging only
#endif
    if (!driver.init())
#ifdef RH_HAVE_SERIAL
         Serial.println("init failed");
#else
	;
#endif
pinMode(TRIG, OUTPUT);
pinMode(ECHO, INPUT);
}

void loop()
{
    digitalWrite(TRIG,LOW);
    delayMicroseconds(10);
    digitalWrite(TRIG,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG,LOW);
    uint16_t du = pulseIn(ECHO,HIGH);
    if (du >= 10000)
    {
      du = 9999;
    }
    // For T1, comment out this line.
    // For T2, uncomment this line and write du += 10000
    // For T3, uncomment this line and write du += 20000
    // du += 10000;
    itoa(du,buf,10); // "10xxxx" "20xxxx" "xxxx"
    driver.send((uint8_t *)buf, strlen(buf));
    driver.waitPacketSent();
    snore(60000);
}
