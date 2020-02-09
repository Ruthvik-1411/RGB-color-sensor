int sensorPin = A0; // select the input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor
int red_light_pin =11;
int green_light_pin=10;
int blue_light_pin=9;
void setup() 
{
pinMode (A0,INPUT);
pinMode (11,OUTPUT);
pinMode (10,OUTPUT);
pinMode (9,OUTPUT);
Serial.begin(9600); //sets serial port for communication
while(! Serial); //wait until serial is ready
Serial.println (" Enter which light to glow ");
delay(2000);
}
void loop()
{
if (Serial.available())
 {
  char ch = Serial.read();
   if (ch == 'red')
    {
     RGB_color(255,0,0);//Red Led
     sensorValue = analogRead(sensorPin); // read the value from the sensor
     }
   if(ch == 'green')
   {
   RGB_color(0, 255, 0); // Green Led
   sensorValue = analogRead(sensorPin); // read the value from the sensor
   }
  if(ch =='blue')
   {
   RGB_color(0, 0, 255); // Blue Led
   sensorValue = analogRead(sensorPin); // read the value from the sensor   
   }
Serial.println(sensorValue);
analogWrite(11, map(sensorValue, 0, 1023, 0, 255));
delay(2000);  
}
if (sensorValue>408) 
{ 
Serial.println("WHITE"); 
}
else if (sensorValue<= 265 && sensorValue >202) 
{
Serial.println("RED");
} 
else if (sensorValue>=276 && sensorValue<325) 
{
Serial.println("GREEN"); 
} 
else if (sensorValue<124 && sensorValue>79) 
{
Serial.println("BLUE");   
}
else if (sensorValue<58)
{
Serial.println("DARK");
}
delay(2000);
}
void RGB_color(int red_led_value,int blue_led_value,int green_led_value)
{ 
analogWrite(red_light_pin, red_led_value); 
analogWrite(green_light_pin, green_led_value);
analogWrite(blue_light_pin, blue_led_value);
}

