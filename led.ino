const int pin_led = 2;
const int pin_led2 = 4;
const int pin_led3 = 7;
int contador = 0;

void setup() {
Serial.begin(9600);
pinMode(pin_led,OUTPUT);
pinMode(pin_led2,OUTPUT);
pinMode(pin_led3,OUTPUT);

//Serial.println("Hola mundo jaja");
}

void loop() {

 delay(500); 
if (contador==0){
  digitalWrite(pin_led,HIGH);
  delay(500);
  digitalWrite(pin_led,LOW);
  contador +=1;
}

delay(500);
if (contador==1){
  digitalWrite(pin_led2,HIGH);
  delay(500);
  digitalWrite(pin_led2,LOW);
  contador +=1;
}

delay(500);
if (contador==2){
  digitalWrite(pin_led3,HIGH);
  delay(500);
  digitalWrite(pin_led3,LOW);
  contador=0;
}
}
