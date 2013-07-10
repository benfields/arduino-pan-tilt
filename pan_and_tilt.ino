// created by ben fields
// uses the two potentiometers in a joystick to control servos used to pan and tilt an object

#include <Servo.h>  // includes the servo library

Servo servoone;  // creates servo object to control a servo 
Servo servotwo;  // creates servo object to control a servo
 
int potpinone = 0;  // analog pin used to connect the first potentiometer
int potpintwo = 1;  // analog pin used to connect the second potentiometer
int val;    // variable to read the value from the analog pin 
 
void setup() //tells the arduino what is attached to where
{ 
  servoone.attach(9);  // attaches the servo on pin 9 to the servo object 
  servotwo.attach(8);  // attaches the servo on pin 8 to the servo object
} 
 
void loop() // this will be repeated forever
{ 
  val = analogRead(potpinone);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  servoone.write(val);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 
  val = analogRead(potpintwo);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  servotwo.write(val);                  // sets the servo position according to the scaled value 
  delay(15); 
}
