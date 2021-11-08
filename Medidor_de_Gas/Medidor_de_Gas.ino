#include <SoftwareSerial.h>

SoftwareSerial BT1(0,1);

int pesoBalon;
int pesoTotal = 10;
double pesoTiempo;

int luzRoja = 11;
int luzVerde = 10;
int luzAzul = 9;

void setup() {
  BT1.begin(9600);
  Serial.begin(9600);
  pinMode(luzRoja, OUTPUT);
  pinMode(luzVerde, OUTPUT);
  pinMode(luzAzul, OUTPUT);
}

void loop() {
  if(Serial.available() > 0){ 
    colorRGB(0, 255, 0);
    
    pesoBalon = Serial.read();
    pesoTiempo = pesoTotal - pesoBalon;
    
    while(pesoTiempo >= 0){
      Serial.println(pesoTiempo);
      delay(1000);
      pesoTiempo -= 1;
    }

      exit(0);
  
  }
  else{
    colorRGB(255,0,0);
  }
}

void colorRGB(int rojo, int verde, int azul){
  analogWrite(luzRoja, rojo);
  analogWrite(luzVerde, verde);
  analogWrite(luzAzul, azul);
}
