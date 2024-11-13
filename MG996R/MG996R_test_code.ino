#include <Servo.h>

Servo myServo; // create a Servo object

void motorTurn(Servo servo, int pos, bool isPostive);

void setup() {
  Serial.begin(9600);
  myServo.attach(9); // attach the servo on pin 9 to the servo object
}

void loop(){
motorTurn(myServo, 180, true);
motorTurn(myServo, 180, false);
}

void motorTurn(Servo servo, int pos, bool isPostive){
  if(isPostive){
    for (int angle = 0; angle <= pos; angle += 1) { // increment angle by 1, 正轉
      myServo.write(angle); // set the servo position
      delay(15); // wait for the servo to reach the position
    }
  }else{
    for (int angle = pos; angle >= 0; angle -= 1) {
      myServo.write(angle);
      delay(15);
    }
  }
}