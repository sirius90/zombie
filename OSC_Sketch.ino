#include <Bridge.h>

const int pin2 = 2;
const int pin3 = 3;
const int pin4 = 4;
const int pin5 = 5;

char right1value[3];
char right2value[3];
char left1value[3];
char left2value[3];

int button0Value = 0;
int button1Value = 0;
int button2Value = 0;
int button3Value = 0;

void setup() {
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
//  Serial.begin(9600);
  Bridge.begin();
}


void loop() {
  //Bridge.get(key,buffer,buffer_length);
  Bridge.get("right1",right1value,3);
  Bridge.get("right2",right2value,3);
  Bridge.get("left1",left1value,3);
  Bridge.get("left2",left2value,3);
  
  
 button0Value = atoi(right1value);
 button1Value = atoi(right2value);
 button2Value = atoi(left1value);
 button3Value = atoi(left2value);
// Serial.println(button0Value);

if ((button0Value|| button1Value  || button2Value || button3Value) == 0 )
{
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      digitalWrite(pin5, LOW);
}

  if (button0Value == 1)    //Left Forward 
  {
     digitalWrite(pin2, HIGH);
     digitalWrite(pin3, LOW);
  }
 
  if (button1Value == 1)    //Right Forward
  {
     digitalWrite(pin2, LOW);
     digitalWrite(pin3, HIGH);
  }
  if (button2Value == 1)     //Left Backward
  {
    digitalWrite(pin4, HIGH);
    digitalWrite(pin5, LOW);
  }
  if (button3Value == 1)    //Right Backward
  {
    digitalWrite(pin4, LOW);
    digitalWrite(pin5, HIGH);
  }

  delay(10);  

}
