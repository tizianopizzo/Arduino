// Crepuscolare con LDR e tre LED

int foto;
int ledVerde = 8;
int ledGiallo = 9;
int ledRosso = 10;

void setup() {
  Serial.begin(9600);
  pinMode(ledVerde,OUTPUT);
  pinMode(ledGiallo,OUTPUT);
  pinMode(ledRosso,OUTPUT);

}

void loop() {
  foto=analogRead(A0);
  Serial.println(foto);
  if (foto> 550) {
    digitalWrite(ledVerde,HIGH);
    digitalWrite(ledGiallo,HIGH);
    digitalWrite(ledRosso,HIGH);
  }
  else if (foto>400) {
    digitalWrite(ledVerde,LOW);
    digitalWrite(ledGiallo,HIGH);
    digitalWrite(ledRosso,HIGH);
  }
  else if (foto > 250) {
    digitalWrite(ledVerde,LOW);
    digitalWrite(ledGiallo,LOW);
    digitalWrite(ledRosso,HIGH);
  }
  else if (foto> 85) {
    digitalWrite(ledVerde,LOW);
    digitalWrite(ledGiallo,LOW);
    digitalWrite(ledRosso,LOW);
  }
delay(250);
}

