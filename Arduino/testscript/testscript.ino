/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int forward = 2;
int left = 3;
int right = 4;
int stay = 5;
int back = 6;

int incomingByte;    // a variable to read incoming serial data into

int command;

void serialEvent()
{
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    if (incomingByte == 'W') {
      command = 1;
    } else if (incomingByte == 'X') {
      command = 2;
    } else if (incomingByte == 'S') {
      command = 3;
    } else if (incomingByte == 'Q') {
      command = 4;
    } else if (incomingByte == 'E') {
      command = 5;
    } else if (incomingByte == 'A') {
      command = 6;
    } else if (incomingByte == 'D') {
      command = 7;
    } else if (incomingByte == 'Z') {
      command = 8;
    } else if (incomingByte == 'C') {
      command = 9;
    } else if (incomingByte == 'L') {
      command = 8;
    } else {
      command = 0;
    }
  }
}

// the setup routine runs once when you press reset:
void setup() { 
  Serial.begin(115200);
  // initialize the digital pin as an output.
  pinMode(forward, OUTPUT);     
  pinMode(left, OUTPUT);     
  pinMode(right, OUTPUT);     
  pinMode(stay, OUTPUT);     
}

void reset() {
  digitalWrite(forward, LOW); 
  digitalWrite(left, LOW); 
  digitalWrite(right, LOW); 
  digitalWrite(stay, LOW);
  digitalWrite(back, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  
  //command = -1;
  switch(command){
    case 0:
    //digitalWrite(led, LOW);
    command = -1;
        break;
    case 1: //W
      digitalWrite(left, LOW); 
      digitalWrite(right, LOW); 
      digitalWrite(stay, LOW); 
      digitalWrite(forward, HIGH);
      digitalWrite(back, LOW); 
      command = 0;
      break;
    case 2: //X
  digitalWrite(left, LOW); 
  digitalWrite(right, LOW); 
  digitalWrite(stay, LOW); 
  digitalWrite(forward, LOW);
  digitalWrite(back, HIGH);  
    command = 0;
        break;
    case 3: //S
      digitalWrite(left, LOW); 
      digitalWrite(right, LOW); 
      digitalWrite(forward, LOW); 
      digitalWrite(stay, HIGH);
      digitalWrite(back, LOW); 
      command = 0;
        break;
    case 4: //Q

    command = 0;
        break;
    case 5:  //E 
    command = 0;
        break;
    case 6:  //A
  digitalWrite(right, LOW); 
  digitalWrite(forward, LOW); 
  digitalWrite(stay, LOW); 
    digitalWrite(left, HIGH);
    digitalWrite(back, LOW); 
    command = 0;
        break;
    case 7:  //D
  digitalWrite(left, LOW); 
  digitalWrite(forward, LOW); 
  digitalWrite(stay, LOW); 
    digitalWrite(right, HIGH);
    digitalWrite(back, LOW); 
    command = 0;
        break;
    case 8: //Z
    command = 0;
        break;
    case 9: //C

    command = 0;
        break;
  }
  //delay(20);
}
