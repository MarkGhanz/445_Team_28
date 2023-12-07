#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x24, 16, 2);
RH_ASK driver;
// RH_ASK driver(2000,PIN_PB0, 0, 0);
// RH_ASK driver(2000, 4, 5, 0); // ESP8266 or ESP32: do not use pin 11 or 2
// RH_ASK driver(2000, 3, 4, 0); // ATTiny, RX on D3 (pin 2 on attiny85) TX on D4 (pin 3 on attiny85), 
// RH_ASK driver(2000, PD14, PD13, 0); STM32F4 Discovery: see tx and rx on Orange and Red LEDS

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
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  lcd.home();
  lcd.print("S");
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)) // Non-blocking
  {
	  // int i;
    uint16_t du = atoi(buf);
    Serial.print(du);
    Serial.println();
	  // Message with a good checksum received, dump it.
	  // driver.printBuffer("Got:", buf, buflen);
    if (du > 20000){
      du -= 20000;
      lcd.setCursor(0,1);
      lcd.print("T3:");
      lcd.setCursor(3,1);
    }
    else if (du > 10000)
    {
      du -= 10000;
      lcd.setCursor(8,0);
      lcd.print("T2:");
      lcd.setCursor(11,0);
    }
    else
    {
      lcd.print("T1:");
      lcd.setCursor(3,0);
    }
    // lcd.setCursor(3, 0);
    float di = (du*.0332)/2;
    if (di < 30.5){
      lcd.print("HIGH");
    }
    else if( di < 61.0)
    {
      lcd.print("MED ");
    }
    else
    {
      lcd.print("LOW ");
    }
    lcd.home();
  }
}
