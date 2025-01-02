// C++ code
//

// Value to see if switch if on or off
int switchValue = 0; 

//Define each pins and if they are inputs or outputs 

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, INPUT);

}

void loop()
{
    //Make the value of the switch, the value that comes from pin 2
    switchValue = digitalRead(2);
 
  //Check if switch is turned on
  if (switchValue == 1) 
  {
     //If switch is on then turn on LEDS on bottom row
     digitalWrite(13, HIGH);
     digitalWrite(12, HIGH);
     digitalWrite(11, HIGH);
     digitalWrite(10, HIGH);
    
     // Wait 0.1 Secs
     delay (100);
     
     //If switch is on then turn on LEDS on top row
     digitalWrite(7, HIGH);
     digitalWrite(6, HIGH);
     digitalWrite(5, HIGH);
     digitalWrite(4, HIGH);
    
     //Wait 0.75 Secs
     delay (750);
    
     //Turn off the LEDS to look cool 
     digitalWrite(13, LOW);
     digitalWrite(12, LOW);
     digitalWrite(11, LOW);
     digitalWrite(10, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     digitalWrite(4, LOW); 
     
     //Wait 0.2 secs
     delay(200); 
    
     //Turn few random LEDS on
     digitalWrite(13, HIGH);
     digitalWrite(12, HIGH);
     digitalWrite(5, HIGH);
     digitalWrite(4, HIGH);
    
     //Wait 0.15 secs
     delay (150); 
     
     //Turn few random LEDS on
     digitalWrite(7, HIGH);
     digitalWrite(6, HIGH);
     digitalWrite(11, HIGH);
     digitalWrite(10, HIGH);
    
     //Wait 0.2 secs
     delay (200); 
  } 
  
  
  //Check if pin is turned off
  else
  { 
     //Turn LEDS on the bottom row off
     digitalWrite(13, LOW);
     digitalWrite(12, LOW);
     digitalWrite(11, LOW);
     digitalWrite(10, LOW);
 
     //Wait 0.05 secs
     delay(50); 
    
     //Turn LEDS on top row off
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     digitalWrite(4, LOW); 
  }
  
  
}