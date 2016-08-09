#include <Servo.h>
char recievedByte;
int basePin = 6;
int bottomPin = 5;
int middlePin = 3;
int manipulatorPin = 9;
int fullForward = 180;
int threequarterForward = 158; 
int halfForward = 135;
int onequarterForward = 113;
int stopPower = 90;
int onequarterBackward = 68;
int halfBackward = 45;
int threequarterBackward = 23;
int fullBackward = 0;
int servoStep = 1;

Servo baseVic;
Servo bottomVic;
Servo middleServo;
Servo manipulator;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  baseVic.attach(basePin);
  bottomVic.attach(bottomPin);
  middleServo.attach(middlePin);
  manipulator.attach(manipulatorPin);
}

void loop() {
 // put your main code here, to run repeatedly:
  if (Serial.available()>0){
      recievedByte = Serial.read();
    //baseMotor movement
    if (recievedByte == 'I'){
      baseVic.write(onequarterForward);
    }
    if (recievedByte == 'J'){
      baseVic.write(onequarterBackward);
    }
    if (recievedByte == 'K'){
      baseVic.write(stopPower);
    }
    //lower DoF movement
    if (recievedByte == 'R'){
      bottomVic.write(halfForward);
    }
    if (recievedByte == 'S'){
      bottomVic.write(stopPower);
    }
    if (recievedByte == 'T'){
      bottomVic.write(halfBackward);
    }
    //middle DoF movement
    if (recievedByte == 'O'){
      middleServo.write((middleServo.read()+servoStep));
    }
    if (recievedByte == 'Q'){
      middleServo.write((middleServo.read()-servoStep));
    }
    //manipulator movement
    if (recievedByte == 'A'){
      manipulator.write(100);
    }
    if (recievedByte == 'B'){
      manipulator.writeMicroseconds(1530);
    }
    if (recievedByte == 'C'){
      manipulator.write(80);
    } 
  }
}
