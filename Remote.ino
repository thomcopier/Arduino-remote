/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
const int buttonYellow = 2;
const int buttonGreen = 3;
const int buttonRed = 4;
const int SwitchBL = 5;
const int SwitchBML = 6;
const int SwitchBMR = 7;
const int SwitchBR = 8;
const int SwitchTR = 9;
const int SwitchTML = 10;
const int SwitchTMR = 11;
const int buttonStickRight =12;
const int buttonStickLeft = 13;

const int pinStickLeftX = 2;
const int pinStickLeftY = 3;
const int pinStickLeftZ = 4;
const int pinStickRightX = 0;
const int pinStickRightY = 1;
const int pinStickRightZ = 5;

int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
int buttonState7 = 0;
int buttonState8 = 0;
int buttonState9 = 0;
int buttonState10 = 0;
int buttonState11 = 0;
int buttonState12 = 0;
int buttonState13 = 0;

int StickLeftX = 0;
int StickLeftY = 0;
int StickLeftZ = 0;
int StickRightX = 0;
int StickRightY = 0;
int StickRightZ = 0;

int newStickLeftX = 0;
int newStickLeftY = 0;
int newStickLeftZ = 0;
int newStickRightX = 0;
int newStickRightY = 0;
int newStickRightZ = 0;

float Alpha = 0.7;

int MiddleLX;
int MiddleLY;
int MiddleLZ;
int MiddleRX;
int MiddleRY;
int MiddleRZ;

String text = "";

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  MiddleLX = analogRead(pinStickLeftX);
  MiddleLY = analogRead(pinStickLeftY);
  MiddleLZ = analogRead(pinStickLeftZ);
  MiddleRX = analogRead(pinStickRightX);
  MiddleRY = analogRead(pinStickRightY);
  MiddleRZ = analogRead(pinStickRightZ);

  StickLeftX = MiddleLX;
  StickLeftY = MiddleLY;
  StickLeftZ = MiddleLZ;
  StickRightX = MiddleRX;
  StickRightY = MiddleRY;
  StickRightZ = MiddleRZ;
  
  pinMode(buttonStickLeft, INPUT);
  pinMode(buttonStickRight, INPUT);
  pinMode(buttonGreen, INPUT);
  pinMode(buttonRed, INPUT);
  pinMode(buttonYellow, INPUT);
  pinMode(SwitchTML, INPUT);
  pinMode(SwitchTMR, INPUT);
  pinMode(SwitchTR, INPUT);
  pinMode(SwitchBL, INPUT);
  pinMode(SwitchBML, INPUT);
  pinMode(SwitchBMR, INPUT);
  pinMode(SwitchBR, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  text = "";
  // read the input on analog pin 0:
  buttonState2 = digitalRead(buttonYellow);
  text += "buttons: Yellow: ";
  if(buttonState2 == HIGH){
    text += "1; ";
  }else{
    text += "0; ";  
  }
  buttonState3 = digitalRead(buttonGreen);
  text += "Green: ";
  if(buttonState3 == HIGH){
    text += "1; ";
  }else{
    text += "0; ";  
  }
  buttonState4 = digitalRead(buttonRed);
  text += "Red: ";
  if(buttonState4 == HIGH){
    text += "1; ";
  }else{
    text += "0; ";  
  }
  buttonState5 = digitalRead(SwitchBL);
  text += "Switches: BL: ";
  if(buttonState5 == HIGH){
    text += "1; ";
  }else{
    text += "0; ";  
  }
  buttonState6 = digitalRead(SwitchBML);
  text += "BML: ";
  if(buttonState6 == HIGH){
    text += "1; ";
  }else{
    text += "0; ";  
  }
  buttonState7 = digitalRead(SwitchBMR);
  text += "BMR: ";
  if(buttonState7 == HIGH){
    text += "1; ";
  }else{
    text += "0; ";  
  }
  buttonState8 = digitalRead(SwitchBR);
  text += "BR: ";
  if(buttonState8 == HIGH){
    text += "1; ";
  }else{
    text += "0; ";  
  }
  buttonState9 = digitalRead(SwitchTR);
  text += "TR: ";
  if(buttonState9 == HIGH){
    text += "1; ";
  }else{
    text += "0; ";  
  }
  buttonState10 = digitalRead(SwitchTML);
  text += "TML: ";
  if(buttonState10 == HIGH){
    text += "1; ";
  }else{
    text += "0; ";  
  }
  buttonState11 = digitalRead(SwitchTMR);
  text += "TMR: ";
  if(buttonState11 == HIGH){
    text += "1; ";
  }else{
    text += "0; ";  
  }
  buttonState12 = digitalRead(buttonStickRight);
  text += "Sticks: Right: ";
  if(buttonState12 == HIGH){
    text += "1; ";
  }else{
    text += "0; ";  
  }
  buttonState13 = digitalRead(buttonStickLeft);
  text += "Left: ";
  if(buttonState13 == HIGH){
    text += "1; ";
  }else{
    text += "0; ";  
  }
  newStickLeftX = analogRead(pinStickLeftX);
  newStickLeftY = analogRead(pinStickLeftY);
  newStickLeftZ = analogRead(pinStickLeftZ);
  newStickRightX = analogRead(pinStickRightX);
  newStickRightY = analogRead(pinStickRightY);
  newStickRightZ = analogRead(pinStickRightZ);

  if(StickLeftX > MiddleLX){
    StickLeftX = Alpha * map(newStickLeftX, MiddleLX+1, 1023, -1, -256) + (1 - Alpha)*StickLeftX;
    }
  else{
    StickLeftX = Alpha * map(newStickLeftX, 0, MiddleLX, 256, 0) + (1 - Alpha)*StickLeftX;
    }

  if(StickLeftY > MiddleLY){
    StickLeftY = Alpha * map(newStickLeftY, MiddleLY+1, 1023, -1, -256) + (1 - Alpha)*StickLeftY;
    }
  else{
    StickLeftY = Alpha * map(newStickLeftY, 0, MiddleLY, 256, 0) + (1 - Alpha)*StickLeftY;
    }

  if(StickLeftZ > MiddleLZ){
    StickLeftZ = Alpha * map(newStickLeftZ, MiddleLZ+1, 1023, 1, 256) + (1 - Alpha)*StickLeftZ;
    }
  else{
    StickLeftZ = Alpha * map(newStickLeftZ, 0, MiddleLZ, -256, 0) + (1 - Alpha)*StickLeftZ;
    }

  if(StickRightX > MiddleRX){
    StickRightX = Alpha * map(newStickRightX, MiddleRX+1, 1023, 1, 256) + (1 - Alpha)*StickRightX;
    }
  else{
    StickRightX = Alpha * map(newStickRightX, 0, MiddleRX, -256, 0) + (1 - Alpha)*StickRightX;
    }

  if(StickRightY > MiddleRY){
    StickRightY = Alpha * map(newStickRightY, MiddleRY+1, 1023, 1, 256) + (1 - Alpha)*StickRightY;
    }
  else{
    StickRightY= Alpha * map(newStickRightY, 0, MiddleRY, -256, 0) + (1 - Alpha)*StickRightY;
    }
    
  text += "Left: X:";
  text += StickLeftX;
  text += "; Y:";
  text += StickLeftY;
  text += "; Z:";
  text += StickLeftZ;
  text += "; Right: X:";
  text += StickRightX;
  text += "; Y:";
  text += StickRightY;
  text += "; Z:";
  text += StickRightZ;
  Serial.println(text);
  delay(1);
}
