// A simple example of a transmitter. Taken from the original RadioHead library.
// All credits and free beer to: https://www.airspayce.com/mikem/arduino/RadioHead/

#include <Arduino.h>
#include <RH_ASK.h>

#define RADIOHEAD_BAUD 2000 // Transmission Speed
#define RADIOHEAD_TX_PIN 1  // Pin of the 433MHz transmitter
#define RADIOHEAD_RX_PIN -1 // Pin of the 433MHz receiver (here not used)

RH_ASK driver(RADIOHEAD_BAUD, RADIOHEAD_RX_PIN, RADIOHEAD_TX_PIN);

void setup() {
    driver.init();
}

void loop() {
    const char *msg = "hello"; // "Just say hello" ~Rene Froger

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(200);
}
