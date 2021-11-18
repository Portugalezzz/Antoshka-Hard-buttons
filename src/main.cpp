#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

//SSID of your network
char ssid[] = "******"; //SSID of your Wi-Fi router
char pass[] = "******"; //Password of your Wi-Fi router
int keyIndex = 0;

unsigned int localPort = 4000; 
char packetBuffer[255]; //buffer to hold incoming packet
char  ReplyBuffer[] = "";       // a string to send back

WiFiUDP Udp;

//input
const int buttonPin0 = D0;
const int buttonPin1 = D1;
const int buttonPin2 = D2;
const int ledpin = D8;
int buttonState0 = LOW;
int buttonState1 = LOW;
int buttonState2 = LOW;
char sendIP[] = "192.168.1.2";
int portNbr = 4001;




void setup()
{
  
  pinMode(buttonPin0, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledpin, OUTPUT);

  Serial.begin(9600);
 
  delay(100); 
  //WiFi.mode(WIFI_STA); 
  WiFi.begin(ssid, pass); 
  Serial.print("Connecting"); 
  while (WiFi.status() != WL_CONNECTED) { 
    Serial.print("."); 
    delay(200);  
  }   
  while (WiFi.waitForConnectResult() != WL_CONNECTED) { 
    Serial.println(); 
    Serial.println("Fail connecting"); 
    delay(5000); 
    ESP.restart(); 
  }   
  Serial.print("   OK  "); 
  Serial.print("Module IP: "); 
  Serial.println(WiFi.localIP());
  //printWifiStatus(); 
  // if you get a connection, report back via serial:
  Udp.begin(localPort);
} 

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

  void SendButtonNumber(char btnnmbr[])
  {
    Udp.beginPacket(sendIP, portNbr);
    Udp.write(btnnmbr);
    Udp.endPacket();
    Serial.print("Send ");
    Serial.print(btnnmbr);
    delay(5000);
  }

void loop () 
  {
   
  buttonState0 = digitalRead(buttonPin0);
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  
  if(buttonState0 == HIGH)
    {
      SendButtonNumber("0");
    }
    
  if(buttonState1 == HIGH)
    {
      SendButtonNumber("1");
    }
  if(buttonState2 == HIGH)
    {
      SendButtonNumber("2");
    }

  if (WiFi.status())
    {
      digitalWrite(ledpin, HIGH); 
    }
  else digitalWrite(ledpin, LOW); 

  

  }
