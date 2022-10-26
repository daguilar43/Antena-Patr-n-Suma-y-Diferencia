/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int signal = 3;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  
  pinMode(signal, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(signal, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(5);               // wait for a second
  digitalWrite(signal, LOW);    // turn the LED off by making the voltage LOW
  delay(15);               // wait for a second
}
