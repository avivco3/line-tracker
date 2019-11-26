//////////// https://github.com/avivco3/line-tracker
//////////// https://www.youtube.com/watch?v=PXVEEIyCvOU

 //////////// lcd code
 #include <LiquidCrystal.h>
LiquidCrystal lcd(31, 30, 26,27, 28, 29);

// Change following variables as per your need
char * LargeText = "  Hello world!   ";
int iLineNumber = 1;   
// Line number to show your string (Either 0 or 1)
int iCursor = 0;

 ///////// drive code
  int vSpeed = 110;                      
  int turn_speed =230;       // 0 - 255  max
  int t_p_speed = 125;
  int stop_distance = 15;
  int turn_delay = 12;

//HC-SR04 Sensor connection
  const int trigPin = 11;
  const int echoPin = 12;

  //leds
  const int RedLed = 32;
  const int BlueLed = 33;

//L293 Connection   
  const int motorA1      = 3;  
  const int motorA2      = 4; 
  const int motorAspeed  = 5;
  const int motorB1      = 7; 
  const int motorB2      = 8; 
  const int motorBspeed  =6;

//Sensor Connection
  const int left_sensor_pin =9;
  const int right_sensor_pin =10;

  
  int turnspeed;
  int left_sensor_state;
  int right_sensor_state;

  long duration;
  int distance;

void setup() {
  
 ///////// drive code
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 

   pinMode(BlueLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
    
    lcd.begin(16, 2);
  Serial.begin(9600);
   UpdateLCDDisplay() ;

  delay(500);                              
   //////////// lcd code
   lcd.begin(16,2);
    digitalWrite (BlueLed,HIGH);
  digitalWrite(RedLed,HIGH); 
  LargeText = " start serching!   ";
   UpdateLCDDisplay() ;

  delay(500);
 
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);

left_sensor_state = digitalRead(left_sensor_pin);
right_sensor_state = digitalRead(right_sensor_pin);



if(right_sensor_state == HIGH && left_sensor_state == LOW)
{
  Serial.println("turning right");

  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);
  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, turn_speed);

  delay(turn_delay); 
  }
if(right_sensor_state == LOW && left_sensor_state == HIGH)
{
  Serial.println("turning left");
  
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, turn_speed);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
  }

if(right_sensor_state == LOW && left_sensor_state == LOW)
{
  Serial.println("going forward");

  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
  LargeText = "------^^**^^----";
 UpdateLCDDisplay() ;

  delay(turn_delay);
  
  }

if(right_sensor_state == HIGH && left_sensor_state == HIGH)    // אם שני החיישנים לא מזהים הרובוט עוצר וממתיך 5 שניות
{ 
  Serial.println("stop");
  
  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, 0);
   LargeText = "   Finish !   ";
  UpdateLCDDisplay() ;
delay(10000);
 }
if(right_sensor_state == HIGH && left_sensor_state == HIGH)
{ 
  Serial.println("stop");
  
  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, 0);
delay(5000);
  }

  if(distance < stop_distance) {
  LargeText = "   SAKANA   ";
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);delay(250);
  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, 0); delay(300);
  UpdateLCDDisplay() ;delay(1500); 
   LargeText = "   calling to vera   ";
   UpdateLCDDisplay() ;delay(1500);

    
                                       //// The Chuckleke Flicker
  for(i=0;i<5;i++){
  digitalWrite (BlueLed,LOW);
  digitalWrite(RedLed,HIGH);delay(300); 
  digitalWrite (BlueLed,HIGH);
  digitalWrite(RedLed,LOW);delay(300); 
  }

  
  digitalWrite (BlueLed,HIGH);
  digitalWrite(RedLed,HIGH); 
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  analogWrite (motorAspeed, t_p_speed);
  analogWrite (motorBspeed, t_p_speed);delay(900);
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  analogWrite (motorAspeed, t_p_speed);
  analogWrite (motorBspeed, t_p_speed);delay(800);
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);delay(900);
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);delay(700);
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);delay(650);
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  left_sensor_state == HIGH;

  while(left_sensor_state == LOW){

  left_sensor_state = digitalRead(left_sensor_pin);
  right_sensor_state = digitalRead(right_sensor_pin);
  Serial.println(" SAKANA");
 
}

  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);
  delay(100);
  
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  delay (500);
     digitalWrite (BlueLed,LOW);
  digitalWrite(RedLed,LOW); 

  }
}
void UpdateLCDDisplay()
{
  int iLenOfLargeText = strlen(LargeText);                                            // Calculate lenght of string.
  if (iCursor == (iLenOfLargeText - 1) )                                              // Reset variable for rollover effect.
  {
    iCursor = 0;
  }
  //lcd.clear();
  lcd.setCursor(0,iLineNumber);
  
  if(iCursor < iLenOfLargeText - 16)                                                  // This loop exicuted for normal 16 characters.
  {
    for (int iChar = iCursor; iChar < iCursor + 16 ; iChar++)
    {
      lcd.print(LargeText[iChar]);
    }
  }
  else
  {
    for (int iChar = iCursor; iChar < (iLenOfLargeText - 1) ; iChar++)                //  This code takes care of printing charecters of current string.
    {
      lcd.print(LargeText[iChar]);
    }
    for (int iChar = 0; iChar <= 16 - (iLenOfLargeText - iCursor); iChar++)           //  Reamining charecter will be printed by this loop.
    {
      lcd.print(LargeText[iChar]);   
    }
  }
  iCursor++;
}
© 2019 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
Pricing
API
Training
Blog
About
