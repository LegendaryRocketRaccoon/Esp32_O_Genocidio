// Load Wi-Fi library
#include <WiFi.h>

// Network credentials Here
const char* ssid     = "R2D2";
const char* password = "Procyon Lotor";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

//variables to store the current LED states
String statePin16 = "off";

String statePin17 = "off";

String statePin18 = "off";

String statePin19 = "off";

String statePin20 = "off";

String statePin21 = "off";

String statePin22 = "off";

String statePin23 = "off";

//Output variable to GPIO pins

const int ledPin16 = 25;

const int ledPin17 = 27;

const int ledPin18 = 14;

const int ledPin19 = 26;

const int ledPin20 = 12;

const int ledPin21 = 13;

const int ledPin22 = 32;

const int ledPin23 = 33;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  
  pinMode(ledPin16, OUTPUT);      
  digitalWrite(ledPin16, 0);
        
  pinMode(ledPin17, OUTPUT);      
  digitalWrite(ledPin17, 0);
  
  pinMode(ledPin18, OUTPUT);      
  digitalWrite(ledPin18, 0);      
  
  pinMode(ledPin19, OUTPUT);      
  digitalWrite(ledPin19, 0); 
  
  pinMode(ledPin20, OUTPUT);      
  digitalWrite(ledPin20, 0);      
  
  pinMode(ledPin21, OUTPUT);      
  digitalWrite(ledPin21, 0); 
  
  pinMode(ledPin22, OUTPUT);      
  digitalWrite(ledPin22, 0);      
  
  pinMode(ledPin23, OUTPUT);      
  digitalWrite(ledPin23, 0);       

  WiFi.softAP(ssid,password);
  
  // Print IP address and start web server
  Serial.println("");
  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client

    while (client.connected() && currentTime - previousTime <= timeoutTime) {
      // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the GPIOs on and off
            if (header.indexOf("GET /16/on") >= 0) {
              statePin16 = "on";
              digitalWrite(ledPin16, HIGH);               
            } else if (header.indexOf("GET /16/off") >= 0) {
              statePin16 = "off";
              digitalWrite(ledPin16, LOW);                
            }
            
            if (header.indexOf("GET /17/on") >= 0) {
              statePin17 = "on";
              digitalWrite(ledPin17, HIGH);               
            } else if (header.indexOf("GET /17/off") >= 0) {
              statePin17 = "off";
              digitalWrite(ledPin17, LOW);                
            }

            if (header.indexOf("GET /18/on") >= 0) {
              statePin18 = "on";
              digitalWrite(ledPin18, HIGH);               
            } else if (header.indexOf("GET /18/off") >= 0) {
              statePin18 = "off";
              digitalWrite(ledPin18, LOW);                
            }
            
            if (header.indexOf("GET /19/on") >= 0) {
              statePin19 = "on";
              digitalWrite(ledPin19, HIGH);               
            } else if (header.indexOf("GET /19/off") >= 0) {
              statePin19 = "off";
              digitalWrite(ledPin19, LOW);                
            }

            if (header.indexOf("GET /20/on") >= 0) {
              statePin20 = "on";
              digitalWrite(ledPin20, HIGH);               
            } else if (header.indexOf("GET /20/off") >= 0) {
              statePin20 = "off";
              digitalWrite(ledPin20, LOW);                
            }
            
            if (header.indexOf("GET /21/on") >= 0) {
              statePin21 = "on";
              digitalWrite(ledPin21, HIGH);               
            } else if (header.indexOf("GET /21/off") >= 0) {
              statePin21 = "off";
              digitalWrite(ledPin21, LOW);                
            }

            if (header.indexOf("GET /22/on") >= 0) {
              statePin22 = "on";
              digitalWrite(ledPin22, HIGH);               
            } else if (header.indexOf("GET /22/off") >= 0) {
              statePin22 = "off";
              digitalWrite(ledPin22, LOW);                
            }
            
            if (header.indexOf("GET /23/on") >= 0) {
              statePin23 = "on";
              digitalWrite(ledPin23, HIGH);               
            } else if (header.indexOf("GET /23/off") >= 0) {
              statePin23 = "off";
              digitalWrite(ledPin23, LOW);                
            }

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            client.println("<style>html { font-family: monospace; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: yellowgreen; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 32px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: gray;}</style></head>");

            client.println("<body><h1>ESP32 Web Server</h1>");
            client.println("<p>Control LED State</p>");

            if (statePin16 == "off") {
              client.println("<p><a href=\"/16/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/16/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            if (statePin17 == "off") {
              client.println("<p><a href=\"/17/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/17/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            if (statePin18 == "off") {
              client.println("<p><a href=\"/18/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/18/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            
            if (statePin19 == "off") {
              client.println("<p><a href=\"/19/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/19/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            if (statePin20 == "off") {
              client.println("<p><a href=\"/20/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/20/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            
            if (statePin21 == "off") {
              client.println("<p><a href=\"/21/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/21/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            if (statePin22 == "off") {
              client.println("<p><a href=\"/22/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/22/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            
            if (statePin23 == "off") {
              client.println("<p><a href=\"/23/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/23/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}