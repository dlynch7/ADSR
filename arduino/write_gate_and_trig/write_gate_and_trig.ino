/* This program is designed to write GATE and TRIGGER CV signals for
 * use with Jonathan Jacky's ADSR circuit.
 * (see http://www.yusynth.net/archives/Electronics/J-Jacky-ADSR-1980.pdf)
 * 
 * This program uses a pair of 1x100 arrays of 1s and 0s to generate 
 * GATE and TRIG signals.
 * 
 * The next step is to write a program that generates GATE and TRIG signals
 * from a button press. When you write that program and build the circuit
 * for the momentary pushbutton, don't forget a pullup/pulldown resistor!
 * 
 * This program was written on 12/31/2016 by Dan Lynch
 */

int gateArray[100] = {
  1,1,1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1,1,1,
  1,1,1,1,1,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  1,1,1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1,1,1,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0
  };

int trigArray[100] = {
  0,1,1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1,1,1,
  0,1,1,1,1,1,1,1,1,1,
  1,1,1,1,1,0,1,1,1,1,
  1,1,1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1,1,1
  };

int lookup = 0; //varaible for navigating through the arrays

#define GATEpin 5
#define TRIGpin 10
#define readpin 0

void setup() {
  // put your setup code here, to run once:
  pinMode(GATEpin, OUTPUT);
  pinMode(TRIGpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adsr_raw = 0;
  float adsr_vol = 0.0;
  for (lookup = 0; lookup < 100; lookup++)
      {
        digitalWrite(GATEpin, gateArray[lookup]);
        digitalWrite(TRIGpin, trigArray[lookup]);
        adsr_raw = analogRead(readpin);
        adsr_vol = adsr_raw * (5.0 / 1023.0);
//        Serial.print(lookup);
//        Serial.print("--GATE: ");
//        Serial.print(gateArray[lookup]);
//        Serial.print(" , TRIG: ");
//        Serial.print(trigArray[lookup]);
//        Serial.print(", ADSR voltage: ");
        Serial.println(adsr_vol);
        delay(10);
      }
}
