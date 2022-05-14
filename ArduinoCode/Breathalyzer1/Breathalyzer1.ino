const int AOUTpin=0;//the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the alcohol sensor goes into digital pin D8 of the arduino
const int ledPin=13;//the anode of the LED connects to digital pin D13 of the arduino

float printbacvalue;
int limit;
int value;
float bacvalue;

void setup() {
Serial.begin(9600);
pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
pinMode(ledPin, OUTPUT);//sets the pin as an output of the arduino
Serial.println("test");
}

void loop()
{
value= analogRead(AOUTpin)-250;//reads the analaog value from the alcohol sensor's AOUT pin
bacvalue = (value+.25)/2625;
Serial.println(bacvalue);
if(bacvalue<0.03)
{
    if(bacvalue>-5){
      printbacvalue = 0;
      }
}


delay (500);
}
