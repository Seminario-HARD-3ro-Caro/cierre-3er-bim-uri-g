#define boton 2 // definir los pines para que sea mas comodo
#define rojo 3
#define amarillo 4
#define azul 5
#define verde 6

int contador = 0; // variable para guardar el valor del contador
bool botonpresionado = true; //variable para guardar si el boton esta presionado


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

        contador++; // aumentar el contador

        if (contador > 15) { // si el contador supera 15, reiniciar a 0
            contador = 0;
        }

        // mostrar el valor del contador en los LEDs
        digitalWrite(rojo, contador & 0b0001); // Este pin va a representar el bit 0 del contador por lo que se va a prender si es necesario u apagar de lo contrario
        digitalWrite(amarillo, contador & 0b0010); // Este pin va a representar el bit 1 del contador por lo que se va a prender si es necesario u apagar de lo contrario
        digitalWrite(azul, contador & 0b0100); // Este pin va a representar el bit 2 del contador por lo que se va a prender si es necesario u apagar de lo contrario
        digitalWrite(verde, contador & 0b1000); // Este pin va a representar el bit 3 del contador por lo que se va a prender si es necesario u apagar de lo contrario


      }
    }
    else{
      botonpresionado = true; //establecer la variable de que el boton esta presionado en verdadero
    }
}
