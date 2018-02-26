
int motorPin1 = 3; // pin 2 on L293D IC
int motorPin2 = 4; // pin 7 on L293D IC
int enablePin = 5; // pin 1 on L293D IC
int state;
int flag=0;

void setup() 
{ 
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(enablePin, OUTPUT);
    digitalWrite(enablePin, HIGH);
    Serial.begin(9600);
}
 
void loop() 
{
     if(Serial.available() > 0)
    {     
      state = Serial.read();   
      flag=0;
    }     
        analogWrite(enablePin,255);
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, HIGH); 
        flag=1;
}
