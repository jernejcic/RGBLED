RGBLED
======

Class to control RGB LED's with Arduino's and other microcontrollers.

# Button Controls

|MODE|NAME|A1 - RED|A2 - GREEN|A3 - BLUE|A0 - FUNC|LED|
|----|----|--|--|--|--|---|
| * | UNIVERSAL |  |  |  | SINGLE CLICK to wake up.  DOUBLE CLICK to change LED channel.  HOLD 3 seconds to skip to next Master Mode (MM). | OFF when no user interaction present for 60 seconds |
| 0 | DEFAULT | Same as mode 1 |||  |  |
| 1 (MM) | INCREMENT | Increment channel brightness ||| SINGLE CLICK to change to DECREMENT mode | Fading RED from OFF to HIGH |
| 2 | DESCREMENT | Decrement channel brightness ||| SINGLE CLICK to change to BRIGHTNESS mode | Fading RED from HIGH to OFF |
| 3 | BRIGHTNESS | Increment brightness of all channels | Decrement brightness of all channels |  | SINGLE CLICK to change to INCREMENT mode | PULSE same color as the current output |
| 4 (MM) | WHITE | Increment brightness | Decrement brightness |  |  | PULSE WHITE |
| 5 (MM) | CYCLE | Increment brightness | Decrement brightness |  |  | CYCLE colors |
