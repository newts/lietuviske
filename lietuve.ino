#include "DigiKeyboard.h"

//
#define BUTTON_Y 2
#define BUTTON_N 0

#define LED_BUILTIN 1

void setup() {
  // don't need to set anything up to use DigiKeyboard
  pinMode(BUTTON_Y, INPUT_PULLUP);
  pinMode(BUTTON_N, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}



int tick;
void loop() {
  int timeout = 0;
  
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);

#if 0
  if (!digitalRead(BUTTON_Y)) {
    DigiKeyboard.delay(1); // debouce
    while (!digitalRead(BUTTON_Y)) {
      if (++timeout > 20000) {
        break;
      }
      DigiKeyboard.delay(2);Y
    }
    DigiKeyboard.print("Y");
  }

  timeout = 0;

  if (!digitalRead(BUTTON_N)) {
    DigiKeyboard.delay(1); // debouce
    while (!digitalRead(BUTTON_N)) {
      if (++timeout > 20000) {
        break;
      }
      DigiKeyboard.delay(2);
    }
    DigiKeyboard.print("N");
  }
#endif

#define KEY_DOT 0x37 // Keyboard . and >
#define KEY_COMMA 0x36 // Keyboard , and <

 DigiKeyboard.sendKeyStroke (KEY_DOT, MOD_ALT_RIGHT);
  DigiKeyboard.write ('c');
  
 DigiKeyboard.sendKeyStroke (KEY_COMMA, MOD_ALT_RIGHT);
  DigiKeyboard.write ('e');

  // blink
  if (++tick & 4) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  // Type out this string letter by letter on the computer (assumes US-style
  // keyboard)
  //  DigiKeyboard.println("Hello Digispark!");

  // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
  // if doing keyboard stuff because it keeps talking to the computer to make
  // sure the computer knows the keyboard is alive and connected
  DigiKeyboard.delay(5000);
}
