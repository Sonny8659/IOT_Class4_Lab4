#include <Arduino.h>
#include <SparkFun_APDS9960.h>
#include <SPI.h>

SparkFun_APDS9960 apds = SparkFun_APDS9960();
int isr_flag = 0;
const int RELAY = 15;

void handleGesture(){
  if (apds.isGestureAvailable()){
    switch ( apds.readGesture()){
      case DIR_UP:
        Serial.println("UP");
        digitalWrite(RELAY, ON);
        break;
      case DIR_DOWN :
        Serial.println("DOWN");
        digitalWrite(RELAY, OFF);
        break;
      case DIR_RIGHT:
        Serial.println("RIGHT");
        break;
      case DIR_LEFT:
        Serial.println("LEFT");
        break;
      default : 
        Serial.println("NONE");
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(RELAY,OUTPUT);
  Serial.println("Stating APDS-9960 Gesture");
  if( apds.init()){
    Serial.println("APDS--9960 initialization complete");
  } else {
    Serial.println("Something went wrong during APDS-9960 init!");
  }

  if( apds.enableGestureSensor(true)){
    Serial.println("Gesture Sensor is now running");
  } else {
    Serial.println("Something went wrong during gesture sensor init!");
  }
}


void loop() {
  handleGesture();
}
