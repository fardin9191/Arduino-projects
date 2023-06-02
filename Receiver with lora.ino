#include <SPI.h>

#include <LoRa.h>
int A=3;
int B=4;
int C=5;
int D;

void setup() {

  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);

  Serial.begin(9600);

  while (!Serial);


  Serial.println("LoRa Receiver");


  if (!LoRa.begin(433E6)) {

    Serial.println("Starting LoRa failed!");

    while (1);

  }
}


void loop() {

  // try to parse packet

  int packetSize = LoRa.parsePacket();

  if (packetSize) {

    // received a packet

    //Serial.print("Received packet '");
    // read packet
    while (LoRa.available()) {
      D=LoRa.read();
      Serial.print(D);
      Serial.print("\n");
      
      if(D==83) //Stop 000
      {
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
      }
      else if(D==70) //Forward 111
      {
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
      }
      else if(D==66) //Backward 011
      {
        digitalWrite(A,LOW);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
      }
      else if(D==76) //Left 110
      {
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,LOW);
      }
      else if(D==82) //Right 101
      {
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,HIGH);
      }
      else
      {
        //digitalWrite(A,LOW);
        //digitalWrite(B,LOW);
        //digitalWrite(C,LOW);
      }


    }


    // print RSSI of packet

    //Serial.print("' with RSSI ");

    //Serial.println(LoRa.packetRssi());

  }
  // Stop = 83, Forward = 70, Backward = 66, Left = 76, Right = 82

}

