# TinyHead

This code is a subset of [the RadioHead library](http://www.airspayce.com/mikem/arduino/RadioHead/)
Please send the money, beer, fame and credits to them.

The version of TinyHead will follow the Radiohead version, I will not update the code for changes to RadioHead other than RH_ASK and it's dependencies.

## Intro
The ATtiny85 is a great chip but it has limited memory. RadioHead is a great libray but it is large and only supported by some 'cores' and not by my favorite ATtiny core by [Dr. Azzy](https://github.com/SpenceKonde/ATTinyCore).

This is why I took only what I need from the RadioHead library and made it into a library for the Arduino IDE.

**Caution**  
ATTiny85 has only 2 timers, one (timer 0) usually used for millis() and one (timer 1) for PWM analog outputs. The RH_ASK Driver library, when built for ATTiny85, takes over timer 0, which prevents use of millis() etc but does permit analog outputs. This will affect the accuracy of millis() and time measurement.

## How
- Use [this](https://github.com/SpenceKonde/ATTinyCore) core
- Only works with ASK
- Use the examples
- ATTiny must run at 8MHz

The hardware I use is from Aliexpress, I have used many different 433MHz boards ranging from 40 cents to 2 dollars.  
I also buy coil antenna's from Aliexpress, and I used self-made whip antenna's and also made my own coil antenna's.  
To increase range, pump up the Volume (volts) or use a long range transmitter, from Aliexpress again.  
I run my ATtiny85 on a salvaged LiPo 18650.