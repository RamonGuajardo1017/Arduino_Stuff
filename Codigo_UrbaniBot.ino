//Código creado por Luis Ramón Guajardo
//Young minds arroz primero
//      -----------------------------------------------------------------------------------
//     | Primero vamos a definir los pines donde van a estar conectados nuestros motores   |
//     | izqA e izqB representan las terminales IN1 e IN3 en el puente H, respectivamente  |
//     | derA i derB representan las terminales IN2 e IN4 en el puente H, respectivamente  |
//     | izq va a controlar el "sentido de giro" izquierdo de los motores A y B            |
//     | der va a controlar el "sentido de giro" derecho de los motores A y                |
//      -----------------------------------------------------------------------------------
int izqA = 5; //Los numeros a los que la variable es igual representan el pin de arduino al que se conectarán
int izqB = 4;
int derA = 7;
int derB= 8;

//      ---------------------------------------------------------------------------------------------------------
//     | Ahora vamos a definir los pines que le corresponden a los puertos del módulo de grabación y audio       |
//     | La terminal REC estará en el pin 10~ con señal PWM, esta va a ejecutar la acción de grabar sonido       |
//     | La terminal PLAYE estará conectada al pin 11~ con señal PWM, ejecutará la acción de reproducir el audio |
//      ---------------------------------------------------------------------------------------------------------
int REC = 10;
int PLAY = 11;


//      ---------------------------------------------------------------------------------------------------
//     | Ahora vamos a definir la configuración general del robot                                          |
//     | Iniciaremos el monitor serial en 9600 baudios, ya que este recibirá la señal del módulo Bluetooth |
//     | Todas las variables relacionadas a los motores serán interpretadas como una "salida" o respuesta  |
//      ---------------------------------------------------------------------------------------------------
void setup(){
  Serial.begin(9600);
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
}


//      ---------------------------------------------------------------------
//     | Ahora definiremos las acciones que el robot repetirá constantemente |
//      ---------------------------------------------------------------------
void loop() {

   char estado = Serial.read(); // Guardaremos la señal que esté enviando el módulo Bluetooth en una variable llamada estado de tipo caracter (un sólo dígito/letra)

  if(estado=='B'){           // Boton BACKWARDS - El módulo Bluetooth envía una señal "B" que es recibida por el Arduino
    Serial.write("B");
    digitalWrite(derB,HIGH);  //Configuramos el sentido de las llantas de tal manera en que ambas estén girando para atrás
    digitalWrite(izqB,LOW);
    digitalWrite(derA,LOW);
    digitalWrite(izqA,HIGH);   
  }
  
  if(estado=='D'){          // Boton DERECHA - El módulo Bluetooth envía una señal "D" que es recibida por el Arduino
    Serial.write("D");
    digitalWrite(derB,HIGH);
    digitalWrite(izqB,LOW);
    digitalWrite(derA,HIGH);
    digitalWrite(izqA,LOW);
       
  }
  if(estado=='S'){         // Boton STOP - El módulo Bluetooth envía una señal "S" que es recibida por el Arduino
    Serial.write("S");
    digitalWrite(derB,LOW);
    digitalWrite(izqB,LOW);
    digitalWrite(derA,LOW);
    digitalWrite(izqA,LOW);

  }
   if(estado=='I'){          // Boton IZQUIERDA - El módulo Bluetooth envía una señal "I" que es recibida por el Arduino
    digitalWrite(derB,LOW);
    digitalWrite(izqB,HIGH);
    digitalWrite(derA,LOW);
    digitalWrite(izqA,HIGH);
 
  } 
  
  if(estado=='A'){          // Boton AVANZAR - El módulo Bluetooth envía una señal "A" que es recibida por el Arduino
   digitalWrite(derB,LOW);
    digitalWrite(izqB,HIGH);
    digitalWrite(derA,HIGH);
    digitalWrite(izqA,LOW);     
  }

 // Si el estado recibido es "H", se ejecutará la acción digital que reproducirá el sonido del robot (previamente grabado), después se apagará para que se pueda volver a repetir otra vez
  if(estado=='H'){
    digitalWrite(PLAY,HIGH);
    digitalWrite(PLAY,LOW);
      }
}

