//ESEMPIO AUTORITENUTA
//---Pizzo Tiziano programmer---

int pulsante; //imposto la variabile del pulsante
int memoria=0; // imposto il valore iniziale della variabile di memoria

void setup() {
  pinMode(12,OUTPUT); //collego un led al 12
  pinMode(11,OUTPUT); //collego l'altro led all'11
  pinMode(10,INPUT); // collego il pulsante al 10
}
//il pulsante lo devo collegare con una resistenza di pull down da 10kohm

void loop() {
  pulsante=digitalRead(10);
  if ((pulsante==HIGH) and (memoria==0)) {
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    memoria=1;
    delay(500);
  }
  else if ((pulsante==HIGH) and (memoria==1)) {
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    memoria=0;
    delay(500);
  }
}

