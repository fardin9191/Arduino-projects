#include <SoftwareSerial.h>

// Define the pins
#define ENA 10
#define IN1 9
#define IN2 8
#define IN3 6
#define IN4 5
#define ENB 3
#define A 4
#define B 7
#define C 11

// Define Bluetooth commands
//const char forward = 'F';
//const char back = 'B';
//const char left = 'L';
//const char right = 'R';
//const char FL = 'G'; //forward left
//const char BL = 'H'; //backward left
//const char FR = 'I'; //forward right
//const char BR = 'J'; //backward right

// Define Motor function
void wheel(int LEFT, int RIGHT);


void setup() {
  // set the data rate for the SoftwareSerial port
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
    if ((digitalRead(A)== HIGH)&&(digitalRead(B)==HIGH)&&(digitalRead(C)==HIGH)) //Forward 111
      wheel(1, 1);
    else if ((digitalRead(A)== LOW)&&(digitalRead(B)==HIGH)&&(digitalRead(C)==HIGH))  //Backward 011
      wheel(-1, -1);
    else if ((digitalRead(A)== HIGH)&&(digitalRead(B)==HIGH)&&(digitalRead(C)==LOW))  //Left 110
      wheel(-1, 1);
    else if ((digitalRead(A)== HIGH)&&(digitalRead(B)==LOW)&&(digitalRead(C)==HIGH))  //Righ 101
      wheel(1, -1);
    else if ((digitalRead(A)== LOW)&&(digitalRead(B)==LOW)&&(digitalRead(C)==LOW))  //Stop 000
      wheel(0, 0);
}
