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
  digitalWrite(LED_BUILTIN, HIGH);
}


void loop()
{  
  char key = kpd.getKey();
  if (key)  // Check for a valid key.
  {
    switch (key)
    {
      case '1' :
     //   break;
      case '2' :
    //    break;
      case '3' :
    //    break;
      case '4' :
    //    break;
      case '5' :
    //    break;
      case '6' :
    //    break;
      case '7' :
    //    break;
      case '8' :
   //     break;
      case '9' :
   //     break;
      case '0' :
        Keyboard.write(key);
        break;
      case 'A' :
        // try Ą
        Keyboard.press(KEY_LEFT_CTRL);
       // Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.write('U');
        Keyboard.releaseAll();
        Keyboard.write('0');
        Keyboard.write('1');
        Keyboard.write('0');
        Keyboard.write('4');
        Keyboard.write(' ');
        // Keyboard.releaseAll();
        break;
        
      case 'B' :
        break;
      case 'C' :
        break;
      case 'D' :
        break;
      case '*':
       digitalWrite(LED_BUILTIN, LOW);
        break;
      case '#':
        digitalWrite(LED_BUILTIN, HIGH);
        break;
    }
    delay(4); // delay for report to send out
  }
}
