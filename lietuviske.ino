#include "Keyboard.h"
#include <Keypad.h>



const byte ROWS = 4; 
const byte COLS = 4; 
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

//char hidcode[ROWS][COLS] = {
 // { HID_KEY_0, HID_KEY_1, HID_KEY_2, HID_KEY_3 , HID_KEY_4, HID_KEY_5 },
 // { HID_KEY_0, HID_KEY_1, HID_KEY_2, HID_KEY_3 , HID_KEY_4, HID_KEY_5 },
 // { HID_KEY_0, HID_KEY_1, HID_KEY_2, HID_KEY_3 , HID_KEY_4, HID_KEY_5 },
 // { HID_KEY_0, HID_KEY_1, HID_KEY_2, HID_KEY_3 , HID_KEY_4, HID_KEY_5 },
//};


// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 16,12,11,10 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 9,7,5,3 };

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup()
{
  Keyboard.begin();

  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);*

}


void loop()
{  
  char key = kpd.getKey();
  if (key)  // Check for a valid key.
  {
    switch (key)
    {
      case '*':
       digitalWrite(LED_BUILTIN, LOW);
        break;
      case '#':
        digitalWrite(LED_BUILTIN, HIGH);
        break;
    }
    Keyboard.write(key);
    delay(4); // delay for report to send out
  }
}
