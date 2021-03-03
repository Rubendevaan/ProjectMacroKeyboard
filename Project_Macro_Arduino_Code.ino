#include <Keyboard.h>;

//RGB LED pins
const int red_light_pin = 15;
const int green_light_pin = 14;
const int blue_light_pin = 16;

//Button for RGB LED pin
const int button_pin = 10;

////Mechanical Keys in Array
int keys[] = {2, 3, 4, 5, 6, 7, 8, 9};

//Counter for RGB LED
int counter = 0;

char f13Key = KEY_F13;
char f14Key = KEY_F14;
char f15Key = KEY_F15;
char f16Key = KEY_F16;
char f17Key = KEY_F17;
char f18Key = KEY_F18;
char f19Key = KEY_F19;
char f20Key = KEY_F20;

void setup() {
  //RGB LED
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);

  //Button for LED
  pinMode(button_pin, INPUT);

  //Loop for Mechanical Keys
  for(int i = 0; i < 8; i++){
    pinMode(keys[i], INPUT_PULLUP);
  }

  //Setup keyboard
  Keyboard.begin();

  Serial.begin(9600);
}

void loop() {
  Serial.print(wiggleMode);
  
  int buttonState;
  buttonState = digitalRead(button_pin);

  //LED Profiles
  //ADD extra to if statement if you want more profiles, go to doAction() function to also add that profile to the switch statement
  if (buttonState == LOW) {
    counter++;
    delay(500);
  }
  else if (counter == 0 ) {
    RGB_color(148, 0, 211);
  }
  else if (counter == 1) {
    RGB_color(255, 0, 0);
  }
  else if (counter == 2) {
    RGB_color(0, 0, 255);
  }
  else {
    counter = 0;
  }

  //Loop to read all keys
  for (int i = 2; i < 10; ++i) {
   // check buttons
     if(readButton(i)) {
       doAction(i, counter); 
     }
   }
   //
}

//RGB function for easy RGB codes
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
{
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

//Reads Button by pin
boolean readButton(int pin) {
  //Check and debounce buttons
   if (digitalRead(pin) == 0) {
    delay(40);
    if (digitalRead(pin) == 0) {
      delay(100);
      return true;
    }
 }
   return false;
}

//Switch statements that use the counter from the LED profile and the child switch case chooses the key function
//I wired the keys wrong so the pin starts from 6 :|
void doAction(int pin, int counter) {
  switch (counter)
  {
    case 0: // F13 to F20
      switch (pin) {
        case 6:
          Keyboard.press(f13Key);
          Keyboard.releaseAll();
          break;
        case 7:
          Keyboard.press(f14Key);
          Keyboard.releaseAll();
          break;
        case 8:
          Keyboard.press(f15Key);
          Keyboard.releaseAll();
          break;
        case 9:
          Keyboard.press(f16Key);
          Keyboard.releaseAll();
          break;
        case 2:
          Keyboard.press(f17Key);
          Keyboard.releaseAll();
          break;
        case 3:
          Keyboard.press(f18Key);
          Keyboard.releaseAll();
          break;
        case 4:
          Keyboard.press(f19Key);
          Keyboard.releaseAll();
          break;
        case 5:
          Keyboard.press(f20Key);
          Keyboard.releaseAll();
          break;
      }
    break;
    case 1: 
      switch (pin) {
        case 6:
          // your task here
          break;
        case 7:
          // your task here
          break;
        case 9:
          // your task here
          break;
        case 2:
          // your task here
          break;
        case 3:
          // your task here
          break;
        case 4:
          break;
      }
      break;
    case 2:
      switch (pin) {
        case 6:
          Keyboard.println("1");
          // your task here
          break;
        case 7:
          Keyboard.println("2");
          // your task here
          break;
        case 8:
          Keyboard.println("3");
          // your task here
          break;
        case 9:
          Keyboard.println("4");
          // your task here
          break;
        case 2:
          Keyboard.println("5");
          // your task here
          break;
        case 3:
          Keyboard.println("6");
          // your task here
          break;
        case 4:
          Keyboard.println("7");
          // your task here
          break;
        case 5:
          Keyboard.println("8");
          // your task here
          break;
      }
    break;
  }
}
