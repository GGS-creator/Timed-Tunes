#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"
unsigned long sec=10;
unsigned long min=0;
unsigned long hour=0;//uses long because int cant store that much data

TMRpcm tmrpcm;

void setup()
{
tmrpcm.speakerPin=9;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
// tmrpcm.setVolume(5);
//   tmrpcm.play("acdc.wav");// Plays ACDC Black In Black
}

void loop() {
  //put your main code here, to run repeatedly:
  unsigned long secMillis = sec * 1000UL;//c    
  unsigned long minMillis = min * 60UL * 1000UL;   
  unsigned long hourMillis = hour * 60UL * 60UL * 1000UL; 
  unsigned long d = secMillis + minMillis + hourMillis; 
  delay(d);//delays for that amount of time
  tmrpcm.setVolume(4);
  tmrpcm.play("acdc.wav");// Plays ACDC Black In Black
  
}
