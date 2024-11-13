int pot; //variabile associata al potenziometro
int Rosso=3; //variabile del led Rosso
int Verde=5; //variabile del led Verde
int Giallo=4; //variabile del led Giallo

long tempo; //variabile che gestisce il tempo di accensione in millisecondi dei led verde e rosso

void setup() 
{
  pinMode(Rosso, OUTPUT);
  pinMode(Verde, OUTPUT);
  pinMode(Giallo, OUTPUT);
  Serial.begin(9600);
}


void loop() 
{
   pot=analogRead(A0); 
  Serial.print ("valore potenziometro: ");
  Serial.println(pot);

  tempo = map(pot, 0, 1023, 10000, 50000);
  Serial.print("tempo semaforo: ");
  Serial.println(tempo);
  Serial.println(" ");



  digitalWrite(Rosso,HIGH);
  delay(tempo);
  digitalWrite(Rosso,LOW);
  digitalWrite(Giallo,HIGH);
  delay((tempo/5));
  digitalWrite(Giallo,LOW);
  digitalWrite(Verde, HIGH);
  delay(tempo);
  digitalWrite(Verde, LOW);




}


