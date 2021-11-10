//Variables globales
String textoRecibido = "0";
double pesoCilindro = 0.0;
double pesoTotal = 10.0;
double pesoTiempo = 0.0;

//Conexión de los pines del led RGB
const int luzRoja = 11;
const int luzVerde = 10;
const int luzAzul = 9;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);
  pinMode(luzRoja, OUTPUT);
  pinMode(luzVerde, OUTPUT);
  pinMode(luzAzul, OUTPUT);
}

void loop() {
  //Si se detecta que se puede mandar informacion
  if(Serial.available() > 0){ 

    //Coloca la luz del led en verde
    colorRGB(0, 255, 0);
    
    //Lee cual es el tipo de balón a pesar
    textoRecibido = Serial.readString();

    //Pasa la cadena de caracteres a un numero de punto flotante para poder hacer las operaciones de calculo
    pesoCilindro = textoRecibido.toDouble();

    //Le resta el peso del balon al peso que toma el sensor de peso
    pesoTiempo = pesoTotal - pesoCilindro;
    
    //Mientras el peso del balon sea mayor o igual a 0, se mantendra activa la aplicacion
    while(pesoTiempo >= 0){

      //Manda a la aplicacion cuanto peso tiene el balon actualmente
      Serial.print(pesoTiempo);

      //Espera un segundo
      delay(1000);

      //Calcula el peso actual de gas en el cilindro
      pesoTiempo -= 0.1;
    }
  }
  else{
    //Si no se ha leido nada, se activara una luz roja
    colorRGB(255,0,0);
  }
}

//Funcion para cambiar los valores de color en el led
void colorRGB(int rojo, int verde, int azul){
  analogWrite(luzRoja, rojo);
  analogWrite(luzVerde, verde);
  analogWrite(luzAzul, azul);
}
