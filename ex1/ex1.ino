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


}

void loop() {
  // Logica del programa

  if(digitalRead(boton) == HIGH){  // si la lectura del boton es que esta apretado
    digitalWrite(rojo, HIGH); //prender cada uno de los pines
    delay(1000);
    digitalWrite(rojo, LOW);
    digitalWrite(amarillo, HIGH);
    delay(1000);
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, HIGH);
    delay(1000);
    digitalWrite(azul, LOW);
    digitalWrite(verde, HIGH);
    delay(1000);
    digitalWrite(verde, LOW);
  }
  else{
    digitalWrite(rojo, LOW); //apagar cada uno de los pines
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, LOW);
    digitalWrite(verde, LOW);
  }

}
