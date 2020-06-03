/*
  AHMAD SIRAJ MY
  QUESTION B
  SUN TRACKER
*/

#include <Servo.h>

int LDR1 = 0;
int LDR2 = 0;
int pos  = 0;
int llc  = 0;
Servo servo_9;

void setup()
{
  pinMode(A0, INPUT); // LDR1 is at A0
  pinMode(A1, INPUT); // LDR2 is at A1
  Serial.begin(9600);
  servo_9.attach(9); //servo motor attached to 9
}

void loop()
{
  if (pos <= 180) {
    CCW(); // it will start rotating 
  }
  else {
    CW(); // it will start rotating oppositely
  }
}

void CCW() {
    for (pos = llc; pos <= 180 || LDR1 == LDR2; pos += 1) {
    read();
    servo_9.write(pos); // movement yay
    llc = pos;
    if (LDR1 == LDR2) {
      break;
    }
    delay(20); // Wait for 15 millisecond(s)
  }
}

void CW() {
    for (pos = llc; pos >= 0 || LDR1 == LDR2; pos -= 1) {
    read();
    servo_9.write(pos); // movement yayy
    llc = pos;
    if (LDR1 == LDR2) {
      break;
    }
    delay(20); // Wait for 15 millisecond(s)
  }
}

void read() {
    LDR1 = analogRead(A0); // read the value from LDR1
    LDR2 = analogRead(A1); // read the value from LDR2
}
