
int motorPin2 = 4; // pin 7 on L293D IC
int enablePin = 5; // pin 1 on L293D IC
int state;
int flag=0;
int speed=0;//makes sure that the serial only prints once the state
 
void setup() 
{
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(enablePin, OUTPUT);
    // sets enablePin high so that motor can turn on:
    digitalWrite(enablePin, HIGH);
    Serial.begin(9600);
}


void loop() {
    //if some date is sent, reads it and saves in state
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   
    // if the state is '0' the DC motor will turn off
    if (state == '0') 
    {
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
        if(flag == 0){
          Serial.println("Motor: off");
          flag=1;
        }
    }
    // if the state is '1' the motor will turn right
    else if (state == '1') {
        speed=Serial.read();
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        analogWrite(motorPin2, speed); // set pin 7 on L293D high
        if(flag == 0){
          Serial.println("Motor: right");
          flag=1;
        }
    }
    // if the state is '2' the motor will turn left
    else if (state == '2') {
         speed=Serial.read();
        digitalWrite(motorPin1, speed); // set pin 2 on L293D high
        digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
        if(flag == 0){
          Serial.println("Motor: left");
          flag=1;
        }
    }
}
