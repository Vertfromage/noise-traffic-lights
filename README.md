# noise-traffic-lights
Made a noise traffic light with my kids using Arduino Nano

We started with this tutorial: https://www.diyelectronics.co.za/wiki/#Arduino/Projects/Noise_Light/Noise_light/

We changed the wiring slightly. The changes we made were: 
- Left out the buzzer. 
- Used a Arduino Nano instead of a Pro Mini. The nano already has a micro usb
- Wired 3.3v to mic and 5v to ada fruit light strip, grounded each on a seperate ground spot.

We changed the code slightly:
See code. Changes:
- Deleted code for buzzer. Who needs that?
- In order to use one neopixel strip rather than 3, I checked the documentation for adafruit neopixels here: https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use and adjusted accordingly, lots of changes there. 
- changed the colors
- added two additional conditions for extra loud and super-extra loud (I have kids) where I have 2 variations of strobe lights. 
- Adjusted the sensitivity, so that a little loud (talking in a normal voice) wasn't enough to set it off.
- moved the last delay into the last else condition, we don't need to double up on the delay, it just causes lags. 
