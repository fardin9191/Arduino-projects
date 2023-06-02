
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <LoRa.h>

int counter = 0;

char *data;
float accX=0;
float accY=0;

MPU6050 mpu6050(Wire);

long timer = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setTxPower(20);
  
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();

  if(millis() - timer > 300){
    
    accX = mpu6050.getAccX();
    accY = mpu6050.getAccY();
    if(accX>0.50)
    {
      data="B";
      Serial.write('B');
      LoRa.beginPacket();
      LoRa.print("B");
      LoRa.endPacket();
    }
    else if(accX<-0.50)
    {
      data="F";
      Serial.write('F');
      LoRa.beginPacket();
      LoRa.print("F");
      LoRa.endPacket();
    }
    else if(accY<-0.50)
    {
      data="R";
      Serial.write('R');
      LoRa.beginPacket();
      LoRa.print("R");
      LoRa.endPacket();
    }
    else if(accY>0.50)
    {
      data="L";
      Serial.write('L');
      LoRa.beginPacket();
      LoRa.print("L");
      LoRa.endPacket();
    }
    else
    {
      data="S";
      Serial.write('S');
      LoRa.beginPacket();
      LoRa.print("S");
      LoRa.endPacket();
    }
    delay(200);
  }

}
