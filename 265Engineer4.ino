
#include <SoftwareSerial.h>
SoftwareSerial GM65(3,2); // RX, TX
String incomingData = "";
int doorState = 7;
void setup() {
  pinMode (doorState , OUTPUT);
 // Start serial communication with the GM65 module
  GM65.begin(9600);
    //lcd.begin(9600);
  // Start serial communication with the computer
  Serial.begin(9600);
  
}
void loop() {
 
  // Read data from the GM65 module
  if (GM65.available() > 0) {
   
    incomingData = GM65.readString();
    //Serial.println(incomingData);
    incomingData.trim();
    // Check if incomingData matches the desired value
    if (incomingData == "BSC/ELE/08/19") {
 
      Serial.println( "WELCOME ");
      Serial.println("LAST NAME   : MVULA ");
       
      Serial.println("FIRST NAME  : ENOCK ");
      Serial.println("TITLE       : STUDENT ");
      
      Serial.print("REG. NUMBER : ");
      
      Serial.println(incomingData);
           digitalWrite(doorState, HIGH);
           delay(10000);
           
      }
    else
    {
         Serial.println("");
            Serial.println("ACCESS DENIED");
               Serial.println("");
               Serial.print("USER : ");
                Serial.println(incomingData);
               Serial.println("Tried to login");
                digitalWrite(doorState, LOW);

     }
    Serial.println("");
  }
                  digitalWrite(doorState, LOW);

}
