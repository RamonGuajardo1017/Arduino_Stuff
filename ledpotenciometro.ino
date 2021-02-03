const int LED=3;
int i;

void setup(){
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() {

int sensorValue = analogRead(A0);
   
  Serial.println(sensorValue);
  delay(1);
  
analogWrite(LED,sensorValue);

}
