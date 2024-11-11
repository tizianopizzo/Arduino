#include <Servo.h>
#include <Ultrasonic.h>
#include <LiquidCrystal.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     11

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

LiquidCrystal lcd(35, 33, 31, 29, 27, 25); 
//Piedini display:
//VSS gnd
//VDD 5v
//V0 contrasto
//RS 12
//RW gnd
//E 11
//D4 5
//D5 4
//D6 3
//D7 2
//A luminosità
//K gnd

Servo esc;


int MdxAvanti = 53;
int MdxIndietro = 51;
int MsxAvanti = 49;
int MsxIndietro = 47;

int y_mot = 0; //variabile da associare ad uno switch,
//che quando è a 0 rende sordi i motori


int contrasto = 3;
int luminosita = 2;

int x=0; //variabile per far la rotazione alternata

int m=0;

int baf=0; //variabile dei baffetti microswitch

int in_pot; //ingresso potenziometro per l'esc
int out_pwm; //uscita per l'esc

void giro_dx() {
  //   Serial.println("giro DX");


  digitalWrite(MdxAvanti,LOW);
  digitalWrite(MdxIndietro,LOW);
  digitalWrite(MsxAvanti,LOW);
  digitalWrite(MsxIndietro,LOW);
  delay(500);
  digitalWrite(MdxAvanti,LOW);
  digitalWrite(MdxIndietro,HIGH);
  digitalWrite(MsxAvanti,LOW);
  digitalWrite(MsxIndietro,HIGH);
  delay(850);
  digitalWrite(MdxAvanti,LOW);
  digitalWrite(MdxIndietro,HIGH);
  digitalWrite(MsxAvanti,HIGH);
  digitalWrite(MsxIndietro,LOW);
  delay(500);
}

void giro_sx() {

  // Serial.println("giro SX");


  digitalWrite(MdxAvanti,LOW);
  digitalWrite(MdxIndietro,LOW);
  digitalWrite(MsxAvanti,LOW);
  digitalWrite(MsxIndietro,LOW);
  delay(500);
  digitalWrite(MdxAvanti,LOW);
  digitalWrite(MdxIndietro,HIGH);
  digitalWrite(MsxAvanti,LOW);
  digitalWrite(MsxIndietro,HIGH);
  delay(850);
  digitalWrite(MdxAvanti,HIGH);
  digitalWrite(MdxIndietro,LOW);
  digitalWrite(MsxAvanti,LOW);
  digitalWrite(MsxIndietro,HIGH);
  delay(500);
}

void setup(){
 
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  esc.attach(7);


  pinMode(MdxAvanti,OUTPUT);
  pinMode(MdxIndietro, OUTPUT);
  pinMode(MsxAvanti, OUTPUT);
  pinMode(MsxIndietro, OUTPUT);

  pinMode(contrasto,OUTPUT);
  pinMode(luminosita,OUTPUT);

  pinMode(10,INPUT); //input dei microswitch
  
  pinMode(9, INPUT); // input dello switch


}

void loop(){

   m=digitalRead(9); //variabile dello switch
  in_pot=analogRead(A9);  //potenziometro sul pin A9
  out_pwm= map(in_pot,0,1023,0,179);
  // analogWrite(out_pwm, 4); //pwm esc sul pin 4
  esc.write(out_pwm);
  float temp;
  temp=analogRead(8);
  float temperatura;
  temperatura= ((temp * 500) / 1024);


  analogWrite(contrasto,90); //imposto il contrasto tramite un pwm (pin V0)
  analogWrite(luminosita,175); //imposto la retroilluminazione tramite pwm (pin A)


  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);


  // Serial.print(" CM: ");
  // Serial.println(cmMsec);

  lcd.print("Dist:");
  lcd.print(cmMsec);
  lcd.print(" ");
  lcd.print(out_pwm);
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.print(temperatura);
  lcd.print(" ");
  lcd.print(baf);
  delay(100);
  lcd.clear();

  baf=digitalRead(10);
  
 // Serial.println(baf);

 // Serial.println(out_pwm);

 
 //  Serial.println(m);
   
    if (m==0)
   {
    m=digitalRead(9);
  digitalWrite(MdxAvanti,LOW);
  digitalWrite(MdxIndietro,LOW);
  digitalWrite(MsxAvanti,LOW);
  digitalWrite(MsxIndietro,LOW);
   }
     
    if(cmMsec>38)  {

      //   Serial.println("no ostacolo");
      
     
      digitalWrite(MdxAvanti,HIGH);
      digitalWrite(MdxIndietro,LOW);
      digitalWrite(MsxAvanti,HIGH);
      digitalWrite(MsxIndietro,LOW);
      }

    
    
    

    else if ((cmMsec<=38) && (x==0) && (m==1)  || (baf==1)){
     
      giro_sx();
      x=1;
      
    }
    else if ((cmMsec<=38) && (x==1)&& (m==1)  || (baf==1)) {
      
       m=digitalRead(9);
      giro_dx();
      x=0;
      
    }
    //else if ((cmMsec > 2000) and (cmMsec<38)) {
    //  giro_dx();
    //  }
    
  //  Serial.println(m);
   
   
   if (m==0)
   {
    m=digitalRead(9);
  digitalWrite(MdxAvanti,LOW);
  digitalWrite(MdxIndietro,LOW);
  digitalWrite(MsxAvanti,LOW);
  digitalWrite(MsxIndietro,LOW);
   }
   
  }








