int blupiu=7; //variabile dell'anodo dei led blu
int blumeno=6; //variabile del catodo dei led blu    

int verdipiu=5; //variabile catodo rossi, anodo verdi
int verdimeno=4; //variabile anodo rossi, catodo verdi

int bluState = LOW;
int verdiState = LOW;

unsigned long previousBlupiu = 0 ; //memorizzazione del tempo precedente
unsigned long intervalBlupiu = 300; //intervallo lampeggio

unsigned long previousVerdipiu = 0 ; //memorizzazione del tempo precedente
unsigned long intervalVerdipiu = 1000; //intervallo lampeggio

void setup(){
  pinMode(blupiu,  OUTPUT);
  pinMode(blumeno,  OUTPUT);
  pinMode(verdipiu,  OUTPUT);
  pinMode(verdimeno,  OUTPUT);
}

void loop() {
  digitalWrite(blumeno,LOW); //setto a zero i catodi dei led
  digitalWrite(verdimeno,LOW);  //setto a zero i catodi dei led

  unsigned long currentMillis = millis();


  if (currentMillis - previousBlupiu > intervalBlupiu) {
    previousBlupiu = currentMillis; //salva l'ultima accensione
    
    if (bluState == LOW) 
      bluState = HIGH;
    else bluState = LOW;
    
    digitalWrite(blupiu, bluState);
  }

  if (currentMillis - previousVerdipiu >intervalVerdipiu) {
    previousVerdipiu = currentMillis; //salva l'ultima accensione
   
    if(verdiState == LOW)
       verdiState = HIGH;
    else verdiState = LOW;
    
    digitalWrite(verdipiu,verdiState);
  }

}

