// C++ code

//Declare Variables

int LDR = 0; // Photoresistor Value 
int PIRL = 0; // Motion Sensor Value (Living Room) 


void setup()
{
  //Set up pin in A1 which coordinates to photoresistor
  pinMode(A1, INPUT); 
  
  //Set up pin 4 which coordinates to Sensor 
  pinMode(4, INPUT);
   
  //Gain acess to serial monitior to perform debugging
  Serial.begin(9600);
  
  // Set up pin to light bulb terminal 1 
  pinMode(3, OUTPUT);
  
}

void loop()
{
  //Set variable LDR to the value of the photo resistor on pin A1
  LDR = analogRead(A1);
  
  //Set variable of if there is motion of not in the living room 
  //to the pin of 4
  PIRL = digitalRead(4);
  
  //Print values to the serial monitor to debugg and locate
  //any problems (very helpful) 
  Serial.print(LDR);
  Serial.print("  ");
  Serial.println(PIRL); 
  
  //Check if photoresitor is set lower than 65% and motion detected
  if (LDR < 500 && PIRL == 1) {
    
    //Light the bulb corresponding to pin 3
    digitalWrite(3, HIGH);

    delay(1000); // Wait for 1000 millisecond(s)
  } 
  
  else {
    
    //if photoresistor is too high (too much outside light) 
    //or motion is not detected, turn of light bulb
    digitalWrite(3, LOW);
    
    delay(500); // Wait for 500 millisecond(s)
  }
  

}