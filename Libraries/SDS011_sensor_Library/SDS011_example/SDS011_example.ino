// SDS011 dust sensor example
// -----------------------------
//
// By R. Zschiegner (rz@madavi.de).
// April 2016

#include <SDS011.h>
#define MOS 2
float p10,p25;
int error;

SDS011 my_sds;

void setup() {
  pinMode(MOS, OUTPUT);
  digitalWrite(MOS, HIGH);
	my_sds.begin(13,15);
	Serial.begin(9600);
}

void loop() {
	error = my_sds.read(&p25,&p10);
	if (! error) {
		Serial.println("P2.5: "+String(p25));
		Serial.println("P10:  "+String(p10));
	}
	delay(100);
}
