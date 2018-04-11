/*This is the code for element14 IoT on wheels design contest traffic predictor project
 *https://www.element14.com/community/roadTestReviews/2651/l/digilent-arty-s7-dev-board-xilinx-spartan-7-review
 * 
 * Author : Dixon Selvan
 * Date   : April 11, 2018
 * Project: Home Automation
 * 
 * Hardware components
 * -----------------------------------
 * 1. Digilent Arty S7
 * 2. Arduino UNO
 * 3. 4 Relay module
 * 4. HC-05 Bluetooth module - x2
 * 
 * Arduino UNO    |   Bluetooth module
 * ------------------------------------
 *      5V        |         5V
 *      Gnd       |         Gnd
 *      TX        |         RX
 *      RX        |         TX
 *  
 * Arduino UNO    |   4 Relay module
 * ------------------------------------
 *      5V        |         5V
 *      Gnd       |         Gnd
 *      D4        |         IN1
 *      D5        |         IN2  
 *      D6        |         IN1
 *      D7        |         IN1
  */
  
#define relay1 4 //Defining relays to their digital pins
#define relay2 5
#define relay3 6
#define relay4 7 
int cmd = 0;    //Variable to hold the serial input from the master

void setup() {
  // put your setup code here, to run once:
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  //initialising serial
  Serial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  // enter the loop only when user inputs a value
  if(Serial.available() > 0){
    cmd = Serial.parseInt();
   
    // the value 11 refers as 1 - Relay1 and 1 - ON and in the case of 10 it refers as 1 - Relay1 and 0 - OFF
    if(cmd==11)
    {
      digitalWrite(relay1, LOW); //LOW turns ON the relay and HIGH turns OFF the relay
      Serial.println("Relay 1 turned ON!");
      delay(10);
    }
    else if(cmd==10)
    {
      digitalWrite(relay1, HIGH);
      Serial.println("Relay 1 turned OFF!");
      delay(10);
    }
    else if(cmd==21)
    {
      digitalWrite(relay2, LOW); //LOW turns ON the relay and HIGH turns OFF the relay
      Serial.println("Relay 2 turned ON!");
      delay(10);
    }
    else if(cmd==20)
    {
      digitalWrite(relay2, HIGH);
      Serial.println("Relay 2 turned OFF!");
      delay(10);
    }
    else if(cmd==31)
    {
      digitalWrite(relay3, LOW); //LOW turns ON the relay and HIGH turns OFF the relay
      Serial.println("Relay 3 turned ON!");
      delay(10);
    }
    else if(cmd==30)
    {
      digitalWrite(relay3, HIGH);
      Serial.println("Relay 3 turned OFF!");
      delay(10);
    }
    else if(cmd==41)
    {
      digitalWrite(relay4, LOW); //LOW turns ON the relay and HIGH turns OFF the relay
      Serial.println("Relay 4 turned ON!");
      delay(10);
    }
    else if(cmd==40)
    {
      digitalWrite(relay4, HIGH);
      Serial.println("Relay 4 turned OFF!");
      delay(10);
    }
  }
}
