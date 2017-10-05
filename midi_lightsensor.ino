/*
 * Creation & Computation - Digital Futures, OCAD University
 * Instructors: Kate Hartman / Nick Puckett
 *
 * Group members: Roxolyana Shepko-Hamilton, Savaya Shinkaruk, Yiyi Shao
 *
 * we start from the example code from: http://www.instructables.com/id/Arduino-Sensors-and-MIDI/
 */



#include <MIDI.h>

byte noteON = 144;//note on command
int analogPin0 = A0;//the analog input pin the light sensor1 is attached to 
int analogPin1 = A1;//the analog input pin the light sensor2 is attached to 
int analogPin2 = A2;//the analog input pin the light sensor3 is attached to 
int analogVal0 = 0;
int analogVal1 = 0;
int analogVal2 = 0;//analog values from there sensors
byte val0; 
byte val1; 
byte val2; //3 MIDI Message that have been mapped

void setup() {
  Serial.begin(9600); 
}

void loop() {
  
  analogVal0 = analogRead(analogPin0);
  analogVal1 = analogRead(analogPin1);
  analogVal2 = analogRead(analogPin2);//read data from 3 different pins
  //we have to scale the sensor data to fit between 0 and 127 (this is the range of MIDI notes)
  val0 = map(analogVal0, 0, 900, 40, 90);//Mapping the value which is 0-900 range I measured
  MIDImessage(noteON, val0, 100);
  delay(100);//hold notes for 100ms
  val1 = map(analogVal1, 0, 900, 40, 90);//Mapping the value which is 0-900 range I measured
  MIDImessage(noteON, val1, 50);
  delay(100);//hold notes for 100ms
  val2 = map(analogVal2, 0, 900, 40, 90);//Mapping the value which is 0-900 range I measured
  MIDImessage(noteON, val2, 100);
  delay(100);//hold notes for 100ms

}

//send MIDI message
void MIDImessage(byte command, byte data1, byte data2) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}
