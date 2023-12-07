// A simple example of a receiver. Taken from the original RadioHead library.
// All credits and free beer to: https://www.airspayce.com/mikem/arduino/RadioHead/

#include <Arduino.h>
#include <RH_ASK.h>

#define RADIOHEAD_BAUD 2000 // Transmission Speed
#define RADIOHEAD_TX_PIN -1 // Pin of the 433MHz transmitter (here not used)
#define RADIOHEAD_RX_PIN  1 // Pin of the 433MHz receiver

RH_ASK driver(RADIOHEAD_BAUD, RADIOHEAD_RX_PIN, RADIOHEAD_TX_PIN);

void setup() {
    driver.init();
}

void loop() {
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) { // Non-blocking
        int i;

        // Message with a good checksum received, dump it.
        driver.printBuffer("Got:", buf, buflen);
    }
}
