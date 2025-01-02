// C++ code
//

// Define if each button is clicked to 0 (false) 
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;


void setup()
{
  //Define all LEDs that are connected to specific pins
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(6, OUTPUT);
  
  // Allow access to serial monitor 
  Serial.begin(9600);

}

void loop()
{
  //Make the value of the buttons correspond to the pin 
  //they are connected too 
  buttonState1 = digitalRead(2); 
  buttonState2 = digitalRead(3); 
  buttonState3 = digitalRead(4); 
  
  //Check If button 1 is turned on
  if (buttonState1 == LOW)
  {
  
  //Set LEDs connected to pin 13, 12 and 11 
  //to RED COLOR (RGB: 255,0,0)
    
  analogWrite(13, 255);
  analogWrite(12, 0);
  analogWrite(11, 0);
  
  //Set LEDs connected to pin 10, 9 and 8
  //to RED COLOR (RGB: 255,0,0)
  analogWrite(10, 255);
  analogWrite(9, 0);
  analogWrite(8, 0);
    

  //Set LEDs connected to pin 7, 6 and 5 
  //to RED COLOR (RGB: 255,0,0)
  analogWrite(7, 255);
  analogWrite(6, 0);
  analogWrite(5, 0);  
  
  delay(10); // Delay a little bit to improve simulation performance
   
   // Make the other buttons turn off
   buttonState2 = HIGH; 
   buttonState3 = HIGH; 
    	
  }
  
  //Check If button 2 is turned on 
  if (buttonState2 == LOW)
  
  { 
  
  //Set LEDs connected to pin 13, 12 and 11 
  //to WHITE COLOR (WHITE: 255,255,255)  
  analogWrite(13, 255);
  analogWrite(12, 255);
  analogWrite(11, 255);

  //Set LEDs connected to pin 10, 9 and 8 
  //to WHITE COLOR (WHITE: 255,255,255)  
  analogWrite(10, 255);
  analogWrite(9, 255);
  analogWrite(8, 255);

  //Set LEDs connected to pin 7, 6 and 5
  //to WHITE COLOR (WHITE: 255,255,255)  
  analogWrite(7, 255);
  analogWrite(6, 255);
  analogWrite(5, 255);
    
  // Turn off the other buttons
  buttonState1 = HIGH; 
  buttonState3 = HIGH; 
    
    
  delay(10); // Delay a little bit to improve simulation performance

    
  }
  
  //Check if button #3 is on
  if (buttonState3 == LOW)
  
  { 
  
  //Turn off LEDS in pin 13,12,11
  analogWrite(13, 0);
  analogWrite(12, 0);
  analogWrite(11, 0);
  
  //Turn off LEDS in pin 13,12,11
  analogWrite(10, 0);
  analogWrite(9, 0);
  analogWrite(8, 0);
  
  //Turn off LEDS in pin 13,12,11
  analogWrite(7, 0);
  analogWrite(6, 0);
  analogWrite(5, 0);
  
  //Turn off other buttons
  buttonState1 = HIGH; 
  buttonState2 = HIGH; 
    
  }
  
  
}