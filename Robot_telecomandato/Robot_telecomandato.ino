#include <IRremote.h>

int RECV_PIN = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;

int out1 = 2;
int out2 = 3;
int out3 = 4;
int out4 = 5;

void avanti(){
 digitalWrite(out1,HIGH); 
 digitalWrite(out2,LOW); 
 digitalWrite(out3,HIGH); 
 digitalWrite(out4,LOW); 
}

void fermo(){
 digitalWrite(out1,LOW); 
 digitalWrite(out2,LOW); 
 digitalWrite(out3,LOW); 
 digitalWrite(out4,LOW); 
}

void indietro() {
 digitalWrite(out1,LOW); 
 digitalWrite(out2,HIGH); 
 digitalWrite(out3,LOW); 
 digitalWrite(out4,HIGH);  
}

void destra() {
 digitalWrite(out1,LOW); 
 digitalWrite(out2,HIGH); 
 digitalWrite(out3,HIGH); 
 digitalWrite(out4,LOW); 
}

void sinistra() {
 digitalWrite(out1,HIGH); 
 digitalWrite(out2,LOW); 
 digitalWrite(out3,LOW); 
 digitalWrite(out4,HIGH); 
}

void setup()
{
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
  
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}


void loop() {
 if (irrecv.decode(&results)) {
   // Serial.println(results.value);
  
  if (results.value == 16742535 ) {
   avanti();
      }
      else if (results.value == 16712445 ) {
        fermo();
      }
      else if (results.value == 16752735 ) {
        destra();
      }
      else if (results.value == 16728255) {
       sinistra(); 
      }
      else if (results.value == 16732335) {
       indietro(); 
      }
 
  irrecv.resume(); // Receive the next value
 }
}
