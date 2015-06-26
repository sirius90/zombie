#include <Bridge.h>

const int pin0 = 3;
const int pin1 = 4;
const int pin2 = 5;
const int pin3 = 6;

char D10value[3];
char D11value[3];
char D12value[3];
char D13value[3];

int button0Value = 0;
int button1Value = 0;
int button2Value = 0;
int button3Value = 0;

void setup() {
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  Bridge.begin();
}


void loop() {
  Bridge.get("D10",D10value,3);
  Bridge.get("D11",D11value,3);
  Bridge.get("D12",D12value,3);
  Bridge.get("D13",D13value,3);
  
  //Bridge.get(key,buffer,buffer_length);
 button0Value = atoi(D10value);//A3
 button1Value = atoi(D11value);//E3
 button2Value = atoi(D12value);//A2
 button3Value = atoi(D13value);//E2

if ((button0Value || button1Value || button2Value || button3Value) == 0 )
{
    digitalWrite(pin0, LOW);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
  
}

  if (button0Value == 1)    //Left Forward A3
  {
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
  }
 
  if (button1Value == 1)    //Right Forward E3
  {
    digitalWrite(pin0, LOW);
    digitalWrite(pin1, HIGH);
  }
  if (button2Value == 1)     //Left Backward A2
  {
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, LOW);
  }
  if (button3Value == 1)    //Right Backward E2
  {
    digitalWrite(pin0, HIGH);
    digitalWrite(pin1, LOW);
  }

  delay(10);  

}
