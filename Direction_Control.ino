

int motorPin1 = 3; // pin 2 on L293D IC
int motorPin2 = 4; // pin 7 on L293D IC
int enablePin = 5; // pin 1 on L293D IC
int state;
int flag=0; 

void setup() {
    // sets the pins as outputs:
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
    if (state == '0') 
    {
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
        if(flag == 0)
        {
          Serial.println("Motor: off");
          flag=1;
        }
    }
    else if (state == '1') 
    {
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin2, HIGH); // set pin 7 on L293D high
        if(flag == 0)
        {
          Serial.println("Motor: right");
          flag=1;
        }
    }
    else if (state == '2')
    {
        digitalWrite(motorPin1, HIGH); // set pin 2 on L293D high
        digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
        if(flag == 0)
        {
          Serial.println("Motor: left");
          flag=1;
        }
    }
}
