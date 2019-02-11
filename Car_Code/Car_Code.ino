#include <Servo.h>

String inData;
String command;
String dg;
int value;
boolean com = true;

#define steering 3
#define LSPWM 5
#define RSPWM 6
#define forwardL 7
#define backwardL 8
#define forwardR 12
#define backwardR 13

Servo steer;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial connection started, waiting for instructions...");
  steer.attach(steering);
  pinMode(forwardL, OUTPUT);
  pinMode(forwardR, OUTPUT);
  pinMode(backwardL, OUTPUT);
  pinMode(backwardR, OUTPUT);
}

void right(float spd) {
  spd = spd / 100;

  if (spd > 0) {
    // make car move forward at speed
    analogWrite(RSPWM, 255 * spd);
    digitalWrite(forwardR, HIGH);
    digitalWrite(backwardR, LOW);
  } else if (spd < 0) {
    // make car move backward at speed
    spd = spd * -1;
    analogWrite(RSPWM, 255 * spd);
    digitalWrite(forwardR, LOW);
    digitalWrite(backwardR, HIGH);
  } else {
    // make car stop moving
    analogWrite(RSPWM, 0);
    digitalWrite(forwardR, LOW);
    digitalWrite(backwardR, LOW);
  }
}

void left(float spd) {
  spd = spd / 100;

  if (spd > 0) {
    // make car move forward at speed
    analogWrite(LSPWM, 255 * spd);
    digitalWrite(forwardL, HIGH);
    digitalWrite(backwardL, LOW);
  } else if (spd < 0) {
    // make car move backward at speed
    spd = spd * -1;
    analogWrite(LSPWM, 255 * spd);
    digitalWrite(forwardL, LOW);
    digitalWrite(backwardL, HIGH);
  } else {
    // make car stop moving
    analogWrite(LSPWM, 0);
    digitalWrite(forwardL, LOW);
    digitalWrite(backwardL, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) { //While connected to bluetooth
    char received = Serial.read();

    if (received == '*')
    {
      Serial.println("Arduino Received: "); //prints what arduino receives
      Serial.println(inData);

      if (com) { //sets sensor variable
        command = inData;
        com = false;
      } else { //sets command variable
        value = inData.toInt();
        com = true;
      }

      if (command[0] == 'M' && com) { //Figures out the sensor and command
        if (command[1] == 'R') {
          right(value);
        }
        if (command[1] == 'L') {
          left(value);
        }
        if (command[1] == 'S') {
          steer.write(value);
        }
        command = "";
        value = 0;
      }

      inData = ""; // Clear received buffer
    } else {

      inData += received;
      
    }
  }
}
