#include "Keyboard.h"
#define mode usb
#define debug 1
#define bouncetime 50
enum modes {serial, usb};
bool newPress;
//               s6,s5,s4,s3,s2,s1,ENT,DEL
byte pinMap[] = {4 , 5, 6, 7, 8, 9, 16, 10 };
byte keyMap[] = {

  B000000,
  97, B100000,//a
  98, B110000,//b
  99, B100100,//c
  100, B100110,//d
  101, B100010,//e
  102, B110100,//f
  103, B110110,//g
  104, B110010,//h
  105, B010100,//i
  106, B010110,//j
  107, B101000,//k
  108, B111000,//l
  109, B101100,//m
  110, B101110,//n
  59, B110111,//ñ
  111, B101010,//o
  112, B111100,//p
  113, B111110,//q
  114, B111010,//r
  115, B011100,//s
  116, B011110,//t
  117, B101001,//u
  118, B111001,//v
  119, B010111,//w
  120, B101101,//x
  121, B101111,//y
  122, B101011,//z
  35, B001111,//#
  42, B110001,//(
  40, B001110,//)
  44, B010000,//,
  60, B011000,//;
  62, B010010,//:
  46, B001000,//.
  63, B001100,//-
  64, B011001,//"
  95, B010001,//?
  33, B011010,//!
};

void setup() {
  if (debug)
    Serial.begin(115200);
  if (mode == usb)
    Keyboard.begin();
  for (int i = 0; i <= 7; i++) {
    pinMode(pinMap[i], INPUT_PULLUP);
    //digitalWrite(pinMap[i], HIGH);
  }
}

void loop() {
  char character = readKeys();

  if (newPress && character != 0) {
    if (mode == usb)
      Keyboard.print(character);
    else if (mode == serial)
      Serial.print(character);
    newPress = 0;
  }
  
  if (newPress) newPress = 0;
}
