// #include <VirtualWire.h>
#include <LiquidCrystal_I2C.h>

// LiquidCrystal lcd(rs, rw, e, d4, d5, d6, d7);
LiquidCrystal_I2C lcd(0x24, 16, 2); // 0x24 is the I2C Address

// char msag[17];
// char msagl = 17;
// int du;
// float di;

void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600);  
  // vw_setup(2000);
  // vw_rx_start();

  lcd.begin(16,1);
  lcd.print("hello, world!");
  // lcd.init();
  // lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  // lcd.home();
}

void loop() {
  // put your main code here, to run repeatedly:
  // if (vw_get_message(msag, &msagl))
  // {
    // Serial.print("R: ");
    // lcd.print(msag);
    // du = atoi(msag);
    // for (int i = 0; i < msagl; i++)
    // {
    // Serial.write(msag[i]);
    // }
    // Serial.println();
    // if (du > 20000){
    //   du -= 20000;
    //   lcd.setCursor(0,1);
    //   lcd.print("T3:");
    //   lcd.setCursor(3,1);
    // }
    // else if (du > 10000)
    // {
    //   du -= 10000;
    //   lcd.setCursor(8,0);
    //   lcd.print("T2:");
    //   lcd.setCursor(11,0);
    // }
    // else
    // {
    //   lcd.print("T1:");
    //   lcd.setCursor(3,0);
    // }
    // // lcd.setCursor(3, 0);
    // di = (du*.0343)/2;
    // lcd.print();
    // if (di < 30.0){
    //   lcd.print("HIGH");
    // }
    // else
    // {
    //   lcd.print("MED ");
    // }
    // lcd.home();
  // }

}
