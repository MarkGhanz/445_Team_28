#include <VirtualWire.h>
#include <LiquidCrystal_I2C.h>
// #include <RH_ASK.h>
//#ifdef RH_HAVE_HARDWARE_SPI
//#include <SPI.h> // Not actually used but needed to compile
//#endif

// RH_ASK driver(1000,11,0,0);
LiquidCrystal_I2C lcd(0x24, 16, 2); // 0x24 is the I2C Address

uint8_t msag[17];
uint8_t msagl = 17;
uint16_t du;
float di;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  vw_setup(2000);
  // pinMode(PIN_PB0,INPUT);
  // vw_set_rx_pin(PIN_PB0);
  vw_rx_start();

  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  lcd.home();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (vw_get_message(msag, &msagl))
  {
    // Serial.print("R: ");
    // lcd.print(msag);
    du = atoi(msag);
    Serial.print(du);
    Serial.println();
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
    di = (du*.0343)/2;
    if (di < 30.0){
      lcd.print("HIGH");
    }
    else
    {
      lcd.print("MED ");
    }
    lcd.home();
  }

}
