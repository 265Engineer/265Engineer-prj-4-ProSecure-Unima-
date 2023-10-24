
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
      
    else if (incomingData == "313002119008")
    {      Serial.println( "ACCOUNT NUMBER FOR :  ");
       Serial.println("LAST NAME   : MVULA ");
       
      Serial.println("FIRST NAME  : ENOCK ");
      Serial.println("TITLE       : STUDENT ");
      
      Serial.print("ACC. NUMBER : ");
      
      Serial.println(incomingData);
       digitalWrite(doorState, HIGH);
           delay(5000);
           
     }
    else if (incomingData == "BSC/ELE/25/19")
    {      Serial.println( " WELCOME ");
      Serial.println("LAST NAME   : CHAPOTERO ");
       
      Serial.println("FIRST NAME  : LAYSEN ");
        Serial.println("TITLE  :  STUDENT ");
      
      Serial.print("REG. NUMBER : ");
      
      Serial.println(incomingData);
       digitalWrite(doorState, HIGH);
           delay(5000);
           
     }
       else if (incomingData == "BSC/ELE/23/19")
    {
            Serial.println( " WELCOME ");
            
      Serial.println("LAST NAME   : CHIKWEMBANI ");
       
      Serial.println("FIRST NAME  :  DUMISANI ");
      
       Serial.println("TITLE  :  STUDENT ");
      
      Serial.print("REG. NUMBER : ");
      
      Serial.println(incomingData);
     }
     else if (incomingData == "BSC/ACT/HON/20/19")
    {
            Serial.println( "WELCOME ");
            
      Serial.println("LAST NAME   : MESHACH ");
       
      Serial.println("FIRST NAME  :  KAYINGA ");
      
       Serial.println("TITLE  :  STUDENT ");
      
      Serial.print("REG. NUMBER : ");
      
      Serial.println(incomingData);

       digitalWrite(doorState, HIGH);
           delay(5000);
           
     }
     
     else if (incomingData == "313201119020")
    {
            Serial.println( "ACCOUNT NUMBER FOR :  ");
            
      Serial.println("LAST NAME   :  MESHACH ");
       
      Serial.println("FIRST NAME  :  KAYINGA ");
      
      Serial.println("TITLE       :  STUDENT ");
      
      Serial.print("ACC. NUMBER :  ");
      
      Serial.println(incomingData);
       digitalWrite(doorState, HIGH);
           delay(5000);
           
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
