#define boton 2 // definir los pines para que sea mas comodo
#define rojo 3
#define amarillo 4
#define azul 5
#define verde 6



void setup() {
  // Configuración del arduino
  // configurar los pines
  pinMode(boton, INPUT); // configurar el boton como entrada
  pinMode(rojo, OUTPUT); // configurar los leds como salida
  pinMode(amarillo, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  Serial.begin(9600); // iniciar la comunacion en el puerto serie


}


void loop() {
    if(Serial.available()){ // si hay datos en el puerto serie
      int numero = Serial.parseInt(); // leer el numero
      if(numero > 15){ // si el numero es mayor a 15
        Serial.println("Error"); // mostrar un mensaje de error
      }
      else{
        digitalWrite(rojo, numero & 0b0001); // Este pin va a representar el bit 0 del contador por lo que se va a prender si es necesario u apagar de lo contrario
        digitalWrite(amarillo, numero & 0b0010); // Este pin va a representar el bit 1 del contador por lo que se va a prender si es necesario u apagar de lo contrario
        digitalWrite(azul, numero & 0b0100); // Este pin va a representar el bit 2 del contador por lo que se va a prender si es necesario u apagar de lo contrario
        digitalWrite(verde, numero & 0b1000); // Este pin va a representar el bit 3 del contador por lo que se va a prender si es necesario u apagar de lo contrario
      }
    }
    

}
