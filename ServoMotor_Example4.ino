// zoomkat 12-13-11 serial servo (2) test
// for writeMicroseconds, use a value like 1500
// for IDE 1.0
// Powering a servo from the arduino usually DOES NOT WORK.
// two servo setup with two servo commands
// send eight character string like 15001500 or 14501550
// use serial monitor to test

#include <Servo.h>
String readString, servo1, servo2;
Servo myservo1;  // create servo object to control a servo 
//Servo myservo2;

void setup() {
  Serial.begin(9600);
  //myservo1.attach(9, 544, 2400);  //the pin for the servo control + default values
  myservo1.attach(9, 1500, 2500);  //the pin for the servo control 
  //myservo2.attach(7);
  Serial.println("two-servo-test-1.0"); // so I can keep track of what is loaded
}


void loop() {

  while (Serial.available()) {
    delay(3);  //delay to allow buffer to fill 
    if (Serial.available() >0) {
      char c = Serial.read();  //gets one byte from serial buffer
      readString += c; //makes the string readString
    } 
  }

  if (readString.length() >0) {
      Serial.println(readString); //see what was received
      
      // expect a string like 07002100 containing the two servo positions      
      servo1 = readString.substring(0, 4); //get the first four characters
      //servo2 = readString.substring(4, 8); //get the next four characters 
      
      Serial.println(servo1);  //print to serial monitor to see parsed results
      //Serial.println(servo2);

      int n1 = servo1.toInt();
      //int n2 = servo2.toInt();

      Serial.println("the numbers are :");
      Serial.println(n1);  //print to serial monitor to see number results
      //Serial.println(n2);

      myservo1.write(n1);      
      //myservo1.writeMicroseconds(n1); //set servo position 
      //myservo2.writeMicroseconds(n2);
    readString="";
  } 
}
