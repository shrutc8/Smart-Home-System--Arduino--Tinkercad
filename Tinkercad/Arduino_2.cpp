#include <Keypad.h>

// Define the keymap
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connect the rows and columns to these Arduino pins
byte rowPins[ROWS] = {13, 12, 11, 10};
byte colPins[COLS] = {9, 8, 7, 6};

// Create the Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//Define necessary variables 

//Set Motion Sensor at Foyer to have a value of 0
int PIRF = 0; 

//Make the security system start to be true 
bool startSecurity = true; 

// Variable to store entered password
String enteredPassword = ""; 

// The password is 1234 
const String correctPassword = "1234"; 

void setup()
{
  //Use serial monitor for debugging
  Serial.begin(9600);
  
  //Define pin mode variables (output/ input) 
  
  pinMode(2, OUTPUT); // LED 
  pinMode(3, OUTPUT); // BUZZER
  pinMode(4, INPUT);  // MOTION DETECTOR
  pinMode(5, OUTPUT); // LED
}

void loop()
{
  //Get the motion detected in the foyer from pin 4
  PIRF = digitalRead(4);
  
  //Get each character from the keypad
  char key = keypad.getKey();

  //Check if the sensor detected motion
  if (PIRF == 1) {
    
    //change the value of startSecurity to false since motion
    //is now detected, starting the alarm system
    startSecurity = false; 
  } 
 
  //check if the security system started
  if (startSecurity == false)
  {
    // Turn on the LEDs
    digitalWrite(2, HIGH);
    digitalWrite(5, HIGH);

    // Turn on the buzzer
    tone(3, 523); // Play a tone (C5 = 523 Hz)
    
    // Wait 0.1 Secs
    delay(100); 
  
    //Turn off the LEDS (so that it will keep blinking) 
    digitalWrite(2, LOW);
    digitalWrite(5, LOW);

    //Wait 0.1 Secs
    delay(100);
    
  }
  
  // Check if security system is turned off 
   if (startSecurity == true)
  {
    //Turn off LEDs
    digitalWrite(2, LOW);
    digitalWrite(5, LOW);

    //Turn off buzzer 
    noTone(3); 
  }

  // Check for keypress
  if (key) {
    Serial.println(key); // Print the key pressed
	
    //Check if user confirmed password clicking # key
    if (key == '#') {
      
      //Check if user entered password and correct password match
      if (enteredPassword == correctPassword) {
        
        // Turn off the security system
        startSecurity = true; 
        
        // Or else keep on looping until they get it
      } else {
        Serial.println("Wrong Password. Try Again.");
      }
      
      // Clear the entered password
      enteredPassword = ""; 
      
      // Add the key to the entered password
    } else {
      enteredPassword += key; 
    }
  }
}