#define boton 2 // definir los pines para que sea mas comodo
#define rojo 3
#define amarillo 4
#define azul 5
#define verde 6

bool botonpresionado = true;
int ledActual = rojo; 


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

    if(digitalRead(boton) == HIGH){  // si la lectura del boton es que esta apretado
      if(botonpresionado){ // si el boton esta presionado
        botonpresionado = false; //establecer la variable de qqe el boton esta presionado en falso
        digitalWrite(rojo, LOW); // apagar todos los leds
        digitalWrite(amarillo, LOW);
        digitalWrite(azul, LOW);
        digitalWrite(verde, LOW);
        if(ledActual == verde){ // chequear cual es el led actual y prender el siguiente
          ledActual = rojo;
        }
        else if(ledActual == azul){
          ledActual = verde;
        }
        else if(ledActual == amarillo){
          ledActual = azul;
        }
        else if(ledActual == rojo){
          ledActual = amarillo;
        }

        digitalWrite(ledActual, HIGH); // prender el led actual
      }
    }
    else{
      botonpresionado = true; //establecer la variable de qqe el boton esta presionado en verdadero
    }
}
