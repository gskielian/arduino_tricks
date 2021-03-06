int trig_pin = 6;
int echo_pin = 7;
long cm;
long duration;
long distance;

void setup()  /*this runs once after power-on */
{
 pinMode(trig_pin, OUTPUT);
 pinMode(echo_pin, INPUT);   
 Serial.begin(9600);
}


void loop() /*this runs after setup() and keeps running until powerdown or completion conditions are met */ 
{
 Serial.println(get_distance());   /*print out the sensor reading in centimeters*/
}

long get_distance()
{
  delay(10);  
  /*trigger the device*/
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);  

/*count the time between sending and receiving becasue this is going to be the basis for our conversion to distance */  
  duration = pulseIn(echo_pin, HIGH);

/*convert the time in milliseconds to distance in centimeters */
  cm = duration/27/2; /*we devide the result by two to because the observed length of the ping actually represents
  the distance to and from the sensed object*/ 
  return cm;
}
