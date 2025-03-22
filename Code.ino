Code Attachments 
The following is the partial / subset of the code. Code of some module(s) have been wilfully 
supressed.  
A.1 Code for ESP32 
#define BLYNK_TEMPLATE_ID "TMPL3PrW5WIGm" 
#define BLYNK_TEMPLATE_NAME "Home Automation" 
#define BLYNK_AUTH_TOKEN "Jruuh0aMOP7TSA8LUJgHL9ax06rJfa6G" 
// Comment this out to disable prints and save space 
#define BLYNK_PRINT Serial 
#include <WiFi.h> 
#include <WiFiClient.h> 
#include <BlynkSimpleEsp32.h> 
char auth[] = "Jruuh0aMOP7TSA8LUJgHL9ax06rJfa6G";//Enter your Auth token 
char ssid[] = "Agni Wireless";//Enter your WIFI name 
char pass[] = "123tisha";//Enter your WIFI password 
BlynkTimer timer; 
#define button1_pin 26 
#define button2_pin 25 
#define button3_pin 33 
#define button4_pin 32 
#define relay1_pin 13 
#define relay2_pin 12 
#define relay3_pin 14 
20 
ECL405 22256(ECE) 
#define relay4_pin 27 
int relay1_state = 0; 
int relay2_state = 0; 
int relay3_state = 0; 
int relay4_state = 0; 
//Change the virtual pins according the rooms 
#define button1_vpin    
V1 
#define button2_vpin    
#define button3_vpin    
#define button4_vpin    
V2 
V3  
V4 
//------------------------------------------------------------------------------ 
// This function is called every time the device is connected to the 
Blynk.Cloud 
// Request the latest state from the server 
BLYNK_CONNECTED() { 
Blynk.syncVirtual(button1_vpin); 
Blynk.syncVirtual(button2_vpin); 
Blynk.syncVirtual(button3_vpin); 
Blynk.syncVirtual(button4_vpin); 
} 
//-------------------------------------------------------------------------- 
// This function is called every time the Virtual Pin state change 
//i.e when web push switch from Blynk App or Web Dashboard 
BLYNK_WRITE(button1_vpin) { 
relay1_state = param.asInt(); 
digitalWrite(relay1_pin, relay1_state); 
} 
//-------------------------------------------------------------------------- 
BLYNK_WRITE(button2_vpin) { 
relay2_state = param.asInt(); 
digitalWrite(relay2_pin, relay2_state); 
} 
//-------------------------------------------------------------------------- 
BLYNK_WRITE(button3_vpin) { 
relay3_state = param.asInt(); 
digitalWrite(relay3_pin, relay3_state); 
} 
//-------------------------------------------------------------------------- 
21 
ECL405 22256(ECE) 
 
ECL405 22256(ECE) 
  
22 
BLYNK_WRITE(button4_vpin) { 
  relay4_state = param.asInt(); 
  digitalWrite(relay4_pin, relay4_state); 
} 
//-------------------------------------------------------------------------- 
 
void setup() 
{ 
  // Debug console 
  Serial.begin(115200); 
  //-------------------------------------------------------------------- 
  pinMode(button1_pin, INPUT_PULLUP); 
  pinMode(button2_pin, INPUT_PULLUP); 
  pinMode(button3_pin, INPUT_PULLUP); 
  pinMode(button4_pin, INPUT_PULLUP); 
  //-------------------------------------------------------------------- 
  pinMode(relay1_pin, OUTPUT); 
  pinMode(relay2_pin, OUTPUT); 
  pinMode(relay3_pin, OUTPUT); 
  pinMode(relay4_pin, OUTPUT); 
  //-------------------------------------------------------------------- 
  //During Starting all Relays should TURN OFF 
  digitalWrite(relay1_pin, HIGH); 
  digitalWrite(relay2_pin, HIGH); 
  digitalWrite(relay3_pin, HIGH); 
  digitalWrite(relay4_pin, HIGH); 
  //-------------------------------------------------------------------- 
 Blynk.begin(auth, ssid, pass, "blynk.cloud", 80); 
  // You can also specify server: 
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80); 
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080); 
  //-------------------------------------------------------------------- 
  Blynk.virtualWrite(button1_vpin, relay1_state); 
  Blynk.virtualWrite(button2_vpin, relay2_state); 
  Blynk.virtualWrite(button3_vpin, relay3_state); 
  Blynk.virtualWrite(button4_vpin, relay4_state); 
  //-------------------------------------------------------------------- 
} 
 
void loop() 
{ 
  Blynk.run(); 
  timer.run(); 
 
ECL405 22256(ECE) 
  
23 
  // You can inject your own code or combine it with other sketches. 
  // Check other examples on how to communicate with Blynk. Remember 
  // to avoid delay() function! 
 
  listen_push_buttons(); 
} 
 
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
 MMMMMMMMMMMM 
void listen_push_buttons(){ 
    //-------------------------------------------------------------------------- 
    if(digitalRead(button1_pin) == LOW){ 
      delay(200); 
      control_relay(1); 
      Blynk.virtualWrite(button1_vpin, relay1_state); //update button state 
    } 
    //-------------------------------------------------------------------------- 
    else if (digitalRead(button2_pin) == LOW){ 
      delay(200); 
      control_relay(2); 
      Blynk.virtualWrite(button2_vpin, relay2_state); //update button state 
    } 
    //-------------------------------------------------------------------------- 
    else if (digitalRead(button3_pin) == LOW){ 
      delay(200); 
      control_relay(3); 
      Blynk.virtualWrite(button3_vpin, relay3_state); //update button state 
    } 
    //-------------------------------------------------------------------------- 
    else if (digitalRead(button4_pin) == LOW){ 
      delay(200); 
      control_relay(4); 
      Blynk.virtualWrite(button4_vpin, relay4_state); //update button state 
    } 
    //-------------------------------------------------------------------------- 
} 
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
 MMMMMMMMMMMM 
 
ECL405 22256(ECE) 
  
24 
 
 
 
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
 MMMMMMMMMMMM 
void control_relay(int relay){ 
  //------------------------------------------------ 
  if(relay == 1){ 
    relay1_state = !relay1_state; 
    digitalWrite(relay1_pin, relay1_state); 
    Serial.print("Relay1 State = "); 
    Serial.println(relay1_state); 
    delay(50); 
  } 
  //------------------------------------------------ 
  else if(relay == 2){ 
    relay2_state = !relay2_state; 
    digitalWrite(relay2_pin, relay2_state); 
    delay(50); 
  } 
  //------------------------------------------------ 
  else if(relay == 3){ 
    relay3_state = !relay3_state; 
    digitalWrite(relay3_pin, relay3_state); 
    delay(50); 
  } 
  //------------------------------------------------ 
  else if(relay == 4){ 
    relay4_state = !relay4_state; 
    digitalWrite(relay4_pin, relay4_state); 
    delay(50); 
  } 
  //------------------------------------------------ 
} 
 
 
A.2    Code for NodeMCU 
#define BLYNK_TEMPLATE_ID "TMPL30Go70Zcd" 
#define BLYNK_TEMPLATE_NAME "Home Security System" 
#define BLYNK_AUTH_TOKEN "UHQDcFacRZPWJqzrdedBjiGtPZMkFSVn" 
#include <LiquidCrystal_I2C.h> 
#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 
#include <DHT.h> 
//Initialize the LCD display 
LiquidCrystal_I2C lcd(0x27, 16, 2); 
char auth[] = "UHQDcFacRZPWJqzrdedBjiGtPZMkFSVn";//Enter your Auth token 
char ssid[] = "Agni Wireless";//Enter your WIFI name 
char pass[] = "123tisha";//Enter your WIFI password 
DHT dht(D3, DHT11); //(sensor pin,sensor type) 
BlynkTimer timer; 
bool pirbutton = 0; 
// Define component pins 
#define Buzzer D0 
#define MQ2 A0 
#define trig D4 
#define echo D5 
#define PIR D6 
#define relay1 D7 
#define relay2 D8 
//Get buttons values 
BLYNK_WRITE(V0) { 
pirbutton = param.asInt(); 
} 
void setup() { 
Serial.begin(9600); 
lcd.begin(16,2); 
lcd.backlight(); 
pinMode(Buzzer, OUTPUT); 
pinMode(PIR, INPUT); 
pinMode(trig, OUTPUT); 
pinMode(echo, INPUT); 
Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80); 
dht.begin(); 
25 
ECL405 22256(ECE) 
 
ECL405 22256(ECE) 
  
26 
  lcd.setCursor(0, 0); 
  lcd.print("Home Automation"); 
  lcd.setCursor(4, 1); 
  lcd.print("System"); 
  delay(4000); 
  lcd.clear(); 
 
//Call the functions 
  timer.setInterval(100L, gassensor); 
  timer.setInterval(100L, DHT11sensor); 
  timer.setInterval(100L, pirsensor); 
  timer.setInterval(100L, ultrasonic); 
} 
 
//Get the MQ2 sensor values 
void gassensor() { 
  int value = analogRead(MQ2); 
  Serial.println(value); 
  value = map(value, 0, 1024, 0, 100); 
  if (value <= 55) { 
    digitalWrite(Buzzer, LOW); 
  } else if (value > 55) { 
    Blynk.logEvent("Warning! Gas leak detected"); 
    digitalWrite(Buzzer, HIGH); 
  } 
  Blynk.virtualWrite(V1, value); 
  lcd.setCursor(0, 0); 
  lcd.print("G:"); 
  lcd.print(" "); 
  lcd.print(value); 
 
} 
 
//Get the DHT11 sensor values 
void DHT11sensor() { 
  float h = dht.readHumidity(); 
  float t = dht.readTemperature(); 
 
  if (isnan(h) || isnan(t)) { 
    Serial.println("Failed to read from DHT sensor!"); 
    return; 
  } 
  Blynk.virtualWrite(V2, t); 
  Blynk.virtualWrite(V3, h); 
 
ECL405 22256(ECE) 
  
27 
 
  lcd.setCursor(8, 0); 
  lcd.print("T:"); 
  lcd.print(t); 
 
  lcd.setCursor(0, 1); 
  lcd.print("H:"); 
  lcd.print(h); 
 
} 
 
//Get the PIR sensor values 
void pirsensor() { 
  bool value = digitalRead(PIR); 
  if (pirbutton == 1) { 
    if (value == 0) { 
      digitalWrite(Buzzer, LOW); 
    } else if (value == 1) { 
      Blynk.logEvent("Warning! Please check your security system"); 
      digitalWrite(Buzzer, HIGH); 
    } 
  } 
} 
 
//Get the ultrasonic sensor values 
void ultrasonic() { 
  digitalWrite(trig, LOW); 
  delayMicroseconds(4); 
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 
  long t = pulseIn(echo, HIGH); 
  long cm = t / 29 / 2; 
  Blynk.virtualWrite(V4, cm); 
 
  lcd.setCursor(8, 1); 
  lcd.print("W:"); 
  lcd.print(cm); 
  lcd.print("  "); 
} 
 
void loop() { 
  Blynk.run();//Run the Blynk library 
timer.run();//Run the Blynk timer
