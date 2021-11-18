#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

//SSID of your network
char ssid[] = "*****"; //SSID of your Wi-Fi router
char pass[] = "*****"; //Password of your Wi-Fi router
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



void setup()
{
  
  pinMode(buttonPin0, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledpin, OUTPUT);
  //IPAddress ip(192, 168, 1, 20); 
  //IPAddress gateway(192, 175, 0, 1); 
  //IPAddress subnet(255, 255, 255, 0); 
  //IPAddress DNS(192, 175, 0, 1); 
  Serial.begin(9600);
  //WiFi.config(ip, gateway, subnet, DNS);  
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

void loop () 
  {
    /*
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remoteIp = Udp.remoteIP();
    Serial.print(remoteIp);
    Serial.print(", port ");
    Serial.println(Udp.remotePort());

    // read the packet into packetBufffer
    int len = Udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;
    }
    Serial.println("Contents:");
    Serial.println(packetBuffer);

    String str(packetBuffer);

    if(str == "hello from unity"){
      digitalWrite(ledpin, HIGH); 
    }


     buttonState = digitalRead(buttonPin0);
     if(buttonState == HIGH){
      String str1 = "Button1 pressed"; 
      str1.toCharArray(ReplyBuffer, 50); 
     }
     else{
      String str1 = "Button1 off"; 
      str1.toCharArray(ReplyBuffer, 50);
     }

     Serial.println(ReplyBuffer);
      Serial.println(Udp.remoteIP());
      Serial.println(Udp.remotePort());


    // send a reply, to the IP address and port that sent the packet
    Udp.beginPacket("192.168.1.2", 4001);
    Udp.write(ReplyBuffer);
    Udp.endPacket();
  }

  else{
      digitalWrite(ledpin, LOW);   
    }
    delay(10);
*/
  buttonState0 = digitalRead(buttonPin0);
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  
  if(buttonState0 == HIGH)
    {
    Udp.beginPacket("192.168.1.2", 4001);
    Udp.write("0");
    Udp.endPacket();
    Serial.print("Send 0");
    delay(5000);
    
    }
      
  if(buttonState1 == HIGH)
    {
    Udp.beginPacket("192.168.1.2", 4001);
    Udp.write("1");
    Udp.endPacket();
    Serial.print("Send 1");
    delay(5000);
    } 
    
  if(buttonState2 == HIGH)
    {
    Udp.beginPacket("192.168.1.2", 4001);
    Udp.write("2");
    Udp.endPacket();
    Serial.print("Send 2");
    delay(5000);
    }

  if (WiFi.status())
    {
      digitalWrite(ledpin, HIGH); 
    }
  else digitalWrite(ledpin, LOW); 

  

  }




/*
if (packetSize) {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remoteIp = Udp.remoteIP();
    Serial.print(remoteIp);
    Serial.print(", port ");
    Serial.println(Udp.remotePort());

    // read the packet into packetBufffer
    int len = Udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;
    }
    Serial.println("Contents:");
    Serial.println(packetBuffer);

    String str(packetBuffer);

    if(str == "hello from unity"){
      digitalWrite(ledpin, HIGH); 
    }


     buttonState = digitalRead(buttonPin0);
     if(buttonState == HIGH){
      String str1 = "Button1 pressed"; 
      str1.toCharArray(ReplyBuffer, 50); 
     }
     else{
      String str1 = "Button1 off"; 
      str1.toCharArray(ReplyBuffer, 50);
     }

     Serial.println(ReplyBuffer);
      Serial.println(Udp.remoteIP());
      Serial.println(Udp.remotePort());


    // send a reply, to the IP address and port that sent the packet
    Udp.beginPacket(Udp.remoteIP(), 4001);
    Udp.write(ReplyBuffer);
    Udp.endPacket();
  }

  else{
      digitalWrite(ledpin, LOW);   
    }
    delay(10);
*/

/*
  buttonState = digitalRead(buttonPin0);
  if(buttonState == HIGH)
    {
    String str1 = "Button1 pressed"; 
    str1.toCharArray(ReplyBuffer, 50); 

    //Udp.beginPacket("192.168.1.2", 4001);
    //Udp.write(ReplyBuffer);
    //Udp.write("3");
   // Udp.endPacket();
    delay(5000);
    }

  if (WiFi.status())
    {
      digitalWrite(ledpin, HIGH); 
    }
  else digitalWrite(ledpin, LOW); 
  */
