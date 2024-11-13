
void setup(){
  Serial.begin(9600); //apro la comunicazione seriale
}

void loop() {
  int numero=0; //dichiaro la variabile
  for(numero=0; numero<=10; numero++) //aumento il numero di uno
  {
    Serial.println(numero); //invio il numero al monitor seriale
    delay(500); //attesa tra gli aumenti di numero
  }
  delay(1000); //attende un secondo prima di decrementare i numeri
  
  for(numero=10; numero>=0; numero--) //diminuisce il numero di uno
  {
    Serial.println(numero); //invio il numero al monitor seriale
    delay(500); //attesa tra le diminuizioni di numeri
  }
  Serial.println("Conteggio eseguito con successo!");
  delay(3000); //aspetta tre secondi prima di ricominciare
}

