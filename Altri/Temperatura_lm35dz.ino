void setup() {
  Serial.begin(9600);
}

void loop() {
  float x;
  x =analogRead(A0);
  float temperatura;
  temperatura = (( x * 500)/1024);
  Serial.println(temperatura);
  delay(1000);
}
  
