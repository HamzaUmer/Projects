#define BLYNK_PRINT Serial


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "37f52415dcfc4306b46ffdabbc0077a5";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Xperia X";
char pass[] = "hhua0107";
;

// Hardware Serial on Mega, Leonardo, Micro...
//#define EspSerial Serial

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);
const int motorplus=4;
const int motorminus=5;
int DC_Fan=6;
int BULB=7;
BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
BLYNK_WRITE(V1) 

   {
         //Clockwise
        digitalWrite(motorplus, LOW);
        digitalWrite(motorminus, HIGH);
   }
  
BLYNK_WRITE(V2) 

   {
         //antiClockwise
        analogWrite(motorplus, HIGH);
        digitalWrite(motorminus, LOW);
   }
  
  BLYNK_WRITE(V3) 

   {
         //stop
        digitalWrite(motorplus, LOW);
        digitalWrite(motorminus, LOW);
   }
   BLYNK_WRITE(V4) 
   {
    //BULB ON
    digitalWrite(BULB, HIGH);
   }
   
     BLYNK_WRITE(V5) 
   {
    //BULB_Off
    digitalWrite(BULB, LOW);
   }
        BLYNK_WRITE(V6) 
   {
    //DC FAN ON
    digitalWrite(DC_Fan, HIGH);
   }
         BLYNK_WRITE(V7) 
   {
    //DC FAN OFF
    digitalWrite(DC_Fan, LOW);
   }
   BLYNK_WRITE(V8) 
   {
    //DC FAN off
    digitalWrite(DC_Fan, LOW);
    //BULB off
    digitalWrite(BULB, LOW);
    //MOTOR OFF
       digitalWrite(motorplus, LOW);
      digitalWrite(motorminus, LOW);
   }
        
void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(motorplus,OUTPUT);
   pinMode(motorminus,OUTPUT);
   pinMode(BULB,OUTPUT);
   pinMode(DC_Fan,OUTPUT);
  
  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, wifi, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second

}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
