#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
Stepper myStepper2(stepsPerRevolution, 2,3,4,5);
     // KN1 UP MOTORS 1
     //KN2 MOTORS -1 DOWN
     // KN3 -1 1 LEFT
     // KN4 1 -1 RIGHT
int kn1;
int kn2;
int kn3;
int kn4;
int step1;
int step2;

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(12, INPUT);
  pinMode(A1, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A2, OUTPUT);
}
void loop(){
  // initialize the serial port:

  myStepper.setSpeed(666);           

  digitalWrite(A2, HIGH);
  Serial.print(digitalRead(7));
  Serial.print("     ");
  Serial.print(digitalRead(6));
  Serial.print("     ");
  Serial.print(digitalRead(12));
  Serial.print("     ");
  Serial.print(digitalRead(A1));
  Serial.print("     ");
  Serial.print(step1);
  Serial.print("     ");
  Serial.println(step2);
  
  if(digitalRead(7) == 1){
    delay(10);
    if(digitalRead(7) == 1){
  // step one step:
kn1 = 1;}}
 else 
 kn1 = 0;
 if(digitalRead(6) == 1){
 delay(10);
 if(digitalRead(6) == 1){
  // step one step:
  kn2 = 1;}}
  else
  kn2 = 0;
  
 if(digitalRead(12) == 1){
   delay(10);
     if(digitalRead(12) == 1){
  // step one step:
     kn3 = 1;
     delay(10);}}
   else 
   kn3 = 0;
 if(digitalRead(A1) == 1){
   delay(10);
     if(digitalRead(A1) == 1){
  // step one step:
     kn4 = 1;
     delay(10);}}
   
  else{
    analogWrite(8, LOW);
    analogWrite(9,LOW);
    analogWrite(10, LOW);
    analogWrite(11, LOW);
    analogWrite(2, LOW);
    analogWrite(3, LOW);
    analogWrite(4, LOW);
    analogWrite(5, LOW);}
    
    
  if(kn1 == 1 || kn4==1){
    step1 = 1;}
    
  if(kn1 == 1 || kn3 == 1){
    step2 = -1;}
  
  if(kn2 == 1 || kn3 == 1){
  step1 = 1;}
  
  if(kn2 == 1 || kn4 == 1){
    step2 = -1;}
  
  myStepper.step(step1);
  myStepper2.step(step2);
  
  }
