#include <Wire.h>
#include <CytronMotorDriver.h>

#define PWM_RIGHT 10 //bleu
#define PWM_LEFT 9 //vert

#define DIR_RIGHT 7 //marron
#define DIR_LEFT 8 //orange

CytronMD motor_right(PWM_DIR, PWM_RIGHT, DIR_RIGHT);  // PWM 1 = Pin 3, DIR 1 = Pin 4.
CytronMD motor_left(PWM_DIR, PWM_LEFT, DIR_LEFT);  // PWM 1 = Pin 3, DIR 1 = Pin 4.
void setup() {
  Serial.begin(9600);
  //Wire.begin(ADDR_ARDUINO);//adresse i2c en 8
  //Wire.onReceive(recv);
  
}
bool isBetween(int min, int val, int max)
{
    if(val < min || val > max)
       return false;
    return true;
}
void loop() {
  motor_right.setSpeed(128);   // Motor 1 runs forward at 50% speed.
  motor_left.setSpeed(128);   // Motor 1 runs forward at 50% speed.
  delay(1000);

  motor_right.setSpeed(255);   // Motor 1 runs forward at full speed.
  motor_left.setSpeed(255);   // Motor 1 runs forward at 50% speed.
  delay(1000);

  motor_right.setSpeed(0);     // Motor 1 stops.
  motor_left.setSpeed(0);
  delay(1000);

  motor_right.setSpeed(-128);  // Motor 1 runs backward at 50% speed.
  motor_left.setSpeed(-128);  // Motor 1 runs backward at 50% speed.
  delay(1000);


}
