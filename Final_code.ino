#include <Servo.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

Servo ebr;
Servo ebl;
Servo jaw;
int trigPin = 9;
int echoPin = 8;
int a = 0;
int count = 0;
long distance;
long duration;
int initial1 = 90;
int final1 = 105;
int initial2 = 105;
int final2 = 90;
const int TOUCH_SENSOR  = 2;
// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 11; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 10; // Connects to module's TX 
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
DFRobotDFPlayerMini player;

void setup()
{
  Serial.begin(9600);
  softwareSerial.begin(9600);
  player.begin(softwareSerial); 
  ebr.attach(7);
  ebl.attach(6);
  jaw.attach(5);  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(TOUCH_SENSOR, INPUT);
  //player.volume(50);
}

void loop()
{
  ultra_sonic();

  if(distance <=10) 
  {
    if (a == 0 )
    {
      Serial.println("Hello All! Welcome to UIC. It's a lovely day. How about a few knock-knock jokes!");
      player.play(2);
      movement1();
      a = 1;
    }
    
  }
  
  int rand_num = random(4,10);
  if(digitalRead(TOUCH_SENSOR) == HIGH)
  {
    Serial.println(rand_num);
    a = 0;    
    player.play(3);
    knock_knock();
    delay(4000);
    //R2D2
    if(rand_num == 4)
    {
      player.play(4);
      r2d2();
      delay(1000);
      player.play(1);
      laugh();
      delay(2000);
    }

    //Thank
    if(rand_num == 5)
    {
      player.play(5);
      thank();
      delay(1000);
      player.play(1);
      laugh();
      delay(2000);
    }

    //Yeah
    if(rand_num == 6)
    {
      player.play(6);
      yeah();
      delay(1000);
      player.play(1);
      laugh();
      delay(2000);
    }

    //WHO
    if(rand_num == 7)
    {
      player.play(7);
      who();
      delay(1000);
      player.play(1);
      laugh();
      delay(2000);
    }

    //Owls_say
    if(rand_num == 8)
    {
      player.play(8);
      owls_say();
      delay(1000);
      player.play(1);
      laugh();
      delay(2000);
    }

    //Hawaii
    if(rand_num == 9)
    {
      player.play(9);
      hawaii();
      delay(1000);
      player.play(1);
      laugh();
      delay(2000);
    }
  }
}

//ULTRASONIC SENSOR
void ultra_sonic()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);
}

//Intro
void movement1()
{
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(100);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(100);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
  //all
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(100);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(100);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(400);
  //Welcome to
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(100);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(100);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(200);
  //UIC
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(200);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(1600);
  //Its a
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(200);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(100);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(200);
  //lovely day
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(300);
  //How about
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(200);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(100);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(200);
  //a few
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(200);
  //knock knock jokes
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(200);
}

void knock_knock()
{
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(175);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(100);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(175);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(100);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(175);
}

void r2d2()
{
  delay(5000);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(200);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
}

void thank()
{
  delay(3000);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(200);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
}

void yeah()
{
  delay(3700);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(200);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(200);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
}

void who()
{
  delay(3500);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(200);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(800);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(100);
}

void owls_say()
{
  delay(3800);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(250);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(250);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(250);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(250);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(250);
}

void hawaii()
{
  delay(4900);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(250);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(250);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(250);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(250);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(250);
}

void laugh()
{
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(100);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(50);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(100);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(50);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(100);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(50);
  ebr.write(initial1);
  ebl.write(initial2);
  jaw.write(initial1);
  delay(100);
  ebr.write(final1);
  ebl.write(final2);
  jaw.write(final1);
  delay(50);
}