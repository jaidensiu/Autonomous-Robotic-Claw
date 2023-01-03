#include <NewPing.h>      // include the NewPing library for this program
#define VCC_PIN 13
#define TRIGGER_PIN 12    // sonar trigger pin will be attached to Arduino pin 12
#define ECHO_PIN 11       // sonar echo pint will be attached to Arduino pin 11
#define GROUND_PIN 10
#define MAX_DISTANCE 200  // maximum distance set to 200 cm
#include <Servo.h>          // include the servo library for this program
Servo myservo;              // create servo object to control a servo
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // initialize NewPing

void setup()                 // do these things once
{
  Serial.begin(9600);        // set data transmission rate to communicate with computer
  pinMode(8, INPUT_PULLUP);  // pin 8 forced to HIGH when there is no external input
  myservo.attach(9);         // attaches the servo on pin 9 to the servo object
  myservo.write(60);         // tells servo to go to 60 degree position

  pinMode(ECHO_PIN, INPUT) ;  
  pinMode(TRIGGER_PIN, OUTPUT) ;
  pinMode(GROUND_PIN, OUTPUT);    // tell pin 10 it is going to be an output
  pinMode(VCC_PIN, OUTPUT);       // tell pin 13 it is going to be an output
  digitalWrite(GROUND_PIN, LOW);  // tell pin 10 to output LOW (OV, or ground)
  digitalWrite(VCC_PIN, HIGH) ;   // tell pin 13 to output HIGH (+5V)
}

void loop()                 //do these things forever
{
  int DISTANCE_IN_CM = sonar.ping_cm();   // read the sonar sensor, using a variable
  Serial.print("Ping: ");                 // print “Ping: " on the computer display
  Serial.print(DISTANCE_IN_CM);           // print the value of the variable next
  Serial.println("cm");                   // print "cm" after that, then go to next line
  
  if ((DISTANCE_IN_CM > 14 && DISTANCE_IN_CM < 24) || (DISTANCE_IN_CM > 40)) // as long as distance is between 14 and 24cm non-inclusive or > 40cm
  {
    myservo.write(240);     // servo position is approxmately at position 170 degrees
  }
  else
  {
    myservo.write(0);       // otherwise, servo position is approximately at position 0 degrees
  }
  
  delay(3000);              // waits for 3.0 second before re-doing the loop

}
