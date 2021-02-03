int IN1 = 5;    
int IN2 = 4;    
int ENA = 3;    
int LED = 1;
int i=0;
int x=0;

void setup(){
 
 pinMode (ENA, OUTPUT); 
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 Serial.begin(9600);
}

void loop(){

int sensorValue = analogRead(A0);
   
  Serial.println(sensorValue);
  delay(1);


if (sensorValue>0 && sensorValue<=512){

while (i<=240){
  analogWrite (ENA,i);
  i+=10;
  delay(1000);
  }
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (LED,HIGH);
}

if (sensorValue>512 && sensorValue<=1023){
while (x<=240){
  analogWrite (ENA,x);
  x+=10;
  delay(1000);
  }
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (LED,HIGH);
}

}
