#include <Ultrasonic.h>
Ultrasonic ultrasonic(13,12);
const int IN1 = 8;
const int IN2 = 7;
const int IN3 = 5;
const int IN4 = 4;
const int ENA = 10;
const int ENB = 3;
#define IR_sensor_front A0 // front sensor
#define IR_sensor_back A1 // rear senson
int distance ;
void setup() 
{
Serial.begin(9600);
delay (5000); // as per sumo compat roles
}
void loop()
{
  
 int IR_front = analogRead(IR_sensor_front);
 int IR_back = analogRead(IR_sensor_back);
 distance = ultrasonic.read();
//Debug
Serial.print("Distance in CM: ");
Serial.println(distance);
Serial.print("IR Front: ");
Serial.println(IR_front);
Serial.print("IR Back: ");
Serial.println(IR_back);
 ROTATE(200, 200); // start rotate if (distance < 20)
    STOP();
  while (distance < 20 ) {
    FORWARD(255, 255); 
    distance = ultrasonic.read();
    IR_front = analogRead(IR_sensor_front);
    IR_back = analogRead(IR_sensor_back);
    Serial.print("Distance in CM: ");
    Serial.println(distance);
    Serial.print("IR Front: ");
    Serial.println(IR_front);
    Serial.print("IR Back: ");
    Serial.println(IR_back);
  if ( IR_front > 650 || IR_back > 650 ) { break;}
  delay(10); }
  
 if (IR_front < 650 )  // < 650 means white 
   {
   STOP();
   delay (50);
   BACKWARD(255, 255);
   delay (500);
   } 
   
 if (IR_back < 650 )  //
   {
   STOP();
   delay (50);
   FORWARD(255, 255);
   delay (500);
   }
   
   
} //--------------------------------------------
void FORWARD (int SpeedR, int SpeedL){
  //When we want to let Motor To move forward,
  // just call this part on the loop section .
  //pass PWM output i.e FORWARD(250, 250); 
 analogWrite(ENA,SpeedR);
  analogWrite(ENB,SpeedL);
 digitalWrite(IN1,HIGH);
 digitalWrite(IN2,LOW);
 digitalWrite(IN3,LOW);
 digitalWrite(IN4,HIGH);
 Serial.println("FORWARD");
}//--------------------------------------------
void BACKWARD (int SpeedR, int SpeedL){
  //When we want to let Motor To move backward,
 analogWrite(ENA,SpeedR);
 analogWrite(ENB,SpeedL);
 digitalWrite(IN1,LOW);
 digitalWrite(IN2,HIGH);
 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,LOW);
 Serial.println("BACKWARD");
}//--------------------------------------------
void ROTATE (int SpeedR, int SpeedL)
{
  analogWrite(ENA,SpeedR);
 analogWrite(ENB,SpeedL);
 digitalWrite(IN1,HIGH);
 digitalWrite(IN2,LOW);
 digitalWrite(IN3,LOW);
 digitalWrite(IN4,HIGH);
 Serial.println("ROTATE");
}//--------------------------------------------
void STOP(){
  //When we want to  Motor To stop ,
  // just add this part to the loop section .
  Serial.println("RESTING, RESTING.....");
  
  analogWrite(IN1,0);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,0);
}
