#include <MIDI.h>

byte noteON = 144;//note on command
int analogPin0 = A0;
int analogPin1 = A1;
int analogPin2 = A2;
int analogVal0 = 0;
int analogVal1 = 0;
int analogVal2 = 0;
byte val0;
byte val1;
byte val2;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  
  analogVal0 = analogRead(analogPin0);
  analogVal1 = analogRead(analogPin1);
  analogVal2 = analogRead(analogPin2);//read data from different pins
  //we have to scale the sensor data to fit between 0 and 127 (this is the range of MIDI notes)
  val0 = map(analogVal0, 0, 900, 40, 90);//use the 0-900 range I measured
  MIDImessage(noteON, val0, 100);
  delay(100);
  val1 = map(analogVal1, 0, 900, 40, 90);
  MIDImessage(noteON, val1, 50);
  delay(100);
  val2 = map(analogVal2, 0, 900, 40, 90);
  MIDImessage(noteON, val2, 100);
  delay(100);

}

//send MIDI message
void MIDImessage(byte command, byte data1, byte data2) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}
