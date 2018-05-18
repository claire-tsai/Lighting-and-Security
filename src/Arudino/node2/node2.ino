// Declare Constants
#define smoke_pin 3		//Digital IO PIN3
#define BT_RxD 10
#define BT_TxD 11

// Declare Serial port
#include <SoftwareSerial.h>
SoftwareSerial BT(BT_RxD,BT_TxD); 

// Declare Variables
int smoke_state=0;  /* Holds the last state of the switch */
char smoke=0;

void setup()   
{
  Serial.begin(9600);
  BT.begin(19200);
}
void loop()  
{
  smoke_state = digitalRead(smoke_pin);
  if(smoke_state=HIGH) smoke = 'l'; 
  else if(smoke_state=LOW) smoke = 'h';
  Serial.print(smoke);  
  BT.write(smoke);
}

