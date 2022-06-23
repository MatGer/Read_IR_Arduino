/*
 * IRremote: READ HEX CODE FROM IR RECEIVER
 * RECEIVER DATA PIN CONNECTE TO PIN 5
 */
#include <IRremote.h>
#define IR_PIN 5


IRrecv irrecv(IR_PIN);
decode_results results;

void setup() {
    pinMode(1,OUTPUT);
    pinMode(6,OUTPUT);
    Serial.begin(9600);
    Serial.println("Enabling IRin");
    irrecv.enableIRIn(); // Start the receiver
    Serial.print(F("Ready to receive IR signals at pin "));
    Serial.println(IR_PIN);

}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX);
        switch(results.value){
          case 0xE0E048B7:
            digitalWrite(6,HIGH);
            digitalWrite(1,LOW);
            delay(100);
            digitalWrite(6,LOW);
            digitalWrite(1,LOW);
            break;
          case 0xE0E008F7:
            digitalWrite(6,LOW);
            digitalWrite(1,HIGH);
            delay(100);
            digitalWrite(6,LOW);
            digitalWrite(1,LOW);
            break;
          default:
            break;
        }
        irrecv.resume(); // Receive the next value
    }
}
