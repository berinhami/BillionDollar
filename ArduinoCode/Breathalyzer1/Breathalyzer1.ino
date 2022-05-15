const int AOUTpin=0;//the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the alcohol sensor goes into digital pin D8 of the arduino
const int ledPin=13;//the anode of the LED connects to digital pin D13 of the arduino

float printbacvalue;
int limit;
int value;
int value1;
int value2;
int value3;
int value4;
int avgvalue;
float bacvalue;
bool isblowing;

void setup() {
Serial.begin(9600);
pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
pinMode(ledPin, OUTPUT);//sets the pin as an output of the arduino
Serial.println("Calibrating, do not blow yet.");
delay(1000);
value= analogRead(AOUTpin);
delay(500);
value1= analogRead(AOUTpin);
delay(500);
value2= analogRead(AOUTpin);
delay(500);
value3= analogRead(AOUTpin);
delay(500);
value4= analogRead(AOUTpin);
avgvalue = (value+value1+value2+value3+value4)/5;
}

void loop()
{
value= analogRead(AOUTpin)-avgvalue;//reads the analaog value from the alcohol sensor's AOUT pin
bacvalue = (value+.25)/2625;
Serial.println(bacvalue);
if(bacvalue<0.03)
{
    if(bacvalue>-5){
      printbacvalue = 0;
      }
}
if(value > avgvalue + 20){
  isblowing == true;
  Serial.println(printbacvalue);
}else{
  Serial.println("Start Blowing");
}
if(value < avgvalue - 20){
   isblowing == true;
   Serial.println(printbacvalue);
}else{
  Serial.println("Start Blowing");
}


delay (500);
}
