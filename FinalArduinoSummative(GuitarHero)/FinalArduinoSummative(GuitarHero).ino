#include <Servo.h>    // Include Servo Motor library, so servo motor can be used
Servo myServo;        // Create Servo object to control the servo 

int actual = 0;       //satisfies the condition for first while loop in void loop
int trueness = 1;     //satisfies the condition for the second while loop in void loop
int dels ;            //sets the delay value for LEDs
int count;            //used in void setup for specifying which number in the array the code refers to
int ledPins [] = {8,9,10,11,12,13,14,15,16};    //LEDs connected these digital ports in order
long randNumber;       //variable declared for generating random integers
const int switchPin1 = 1 ;    //rightmost button connected to digital pin 1 (physical orientation of project: red LED should be pointed towards you)
const int switchPin2 = 2 ;    //second button from right connected to digital pin 2
const int switchPin3 = 3 ;    //third button from right connected to digital pin 3
const int switchPin4 = 4 ;     //fourth button from right connected to digital pin 4
const int switchPin5 = 5 ;      //fifth button from right connected to digital pin 5
const int switchPin6 = 6 ;    //sixth button from right connected to digital pin 6
const int switchPin7 = 30;  //seventh button from right connected to digital pin 30
const int switchPin8 = 31;  //eigth button from right connected to digital pin 31
const int switchPin9 = 32;  //leftmost button connected to digital pin 32
const int switchPin11 = 44;  //on breadboard with 3 buttons, button closest to the ground wire is connected to digital pin 44 
const int switchPin12 = 46;  //on breadboard with 3 buttons, button that is second-closest to ground wire is connected to digital pin 46
const int switchPin13 = 48;  //on breadboard with 3 buttons, button furthest from the ground wire is connected to digital pin 48
int required = 20;              //player has to get 20 points to exit while loop and win the game
int adder = 0;                  //at end of each round, this value is added to "hit" variable. This indicates amount of points player accumulates each round (which is when LED flashes on then off once)
int hit = 0;                    //total amount of points the player has accumulated
int tracker = 0;
void setup () {

  Serial.begin(9600);                       //baud rate set at 9600 for arduino to communicate with Serial monitor 
   myServo.attach(21);                      //Servo is connected to digital pin 21 
  for (count = 0; count < 9; count ++) {    //Sets all LEDs as output and low to begin with 
    pinMode (ledPins[count],OUTPUT);
    digitalWrite (ledPins[count],LOW);
  }
}

 void loop () {

 int val1 = digitalRead(switchPin1);   //declaring variable expressing whether rightmost button is high or not
 int val2 = digitalRead(switchPin2);   //declaring variable expressing whether second button from the left is high or not
  int val3 = digitalRead(switchPin3);  //declaring variable expressing whether third button from the left is high or not
 int val4= digitalRead(switchPin4);    //declaring variable expressing whether fourth button from the left is high or not
   int val5 = digitalRead(switchPin5); //declaring variable expressing whether fifth button from the left is high or not
 int val6= digitalRead(switchPin6);    //declaring variable expressing whether sixth button from the left is high or not
int val7 = digitalRead (switchPin7);   //declaring variable expressing whether seventh button from the left is high or not
int val8 = digitalRead (switchPin8);   //declaring variable expressing whether eight button from the left is high or not
int val9 = digitalRead (switchPin9);   //declaring variable expressing whether leftmost button is high or not
int val11 = digitalRead (switchPin11); //on breadboard with 3 buttons, declaring variable expressing whether button closest to ground wire is high or not
int val12 = digitalRead (switchPin12); //on breadboard with 3 buttons, declaring variable expressing whether button that is second-closest to ground wire is high or not
int val13= digitalRead (switchPin13);  //on breadboard with 3 buttons, declaring variable expressing whether button furthest from ground wire is high or not

while (actual == 0){     //displays the instructions

delay (500);
  Serial.print("Welcome to the Pro-Arduino Space Station");
      Serial.println("");  
            Serial.println("");  
                  Serial.println("");  

  Serial.println("You must start the engine and lift off");
  
    Serial.println("Instructions:");
    Serial.println("In order to do so, you can start off by choosing a level");
Serial.println("On the breadboard with 3 buttons, you can set a level for yourself");
Serial.println("the higher the level, the faster the lights will flash");
Serial.println("the button closest to ground wire initiates level 1 (slowest)");
Serial.println("the middle button initiates level 2 (medium speed)");
Serial.println("the button furthest from ground wire initiates level 3 (fastest)");
Serial.println("After choosing a level, lights will flash on and off in a random pattern");
Serial.println("");
Serial.println("");
Serial.println("The objective is to press the button when the correct light is ON");
Serial.println("for example, when the leftmost light is on, you earn a point for pressing the leftmost button");
Serial.println("When the second light from the left is on, you earn a point for pressing the second button from the left");
Serial.println("When the rightmost light is on, you earn a point for pressing the rightmost button");
Serial.println("Basically, you can compare this game to whack-a-mole, except the position of the light that flashes determines which particular button you need to press");
Serial.println("the red light is a trap: if you press fourth button from the left at the instant when red light flashes on, your point count is reduced back to 0");
Serial.println("You win after earning 20 points");
Serial.println("Not pressing a button, missing a button or pressing the wrong button when any light is on will not be counted as a penalty");
Serial.println("Once you win, motor spins and you will lift off :D");
Serial.println("");
Serial.println("");
Serial.println ("Also, if one particular button appears to act like a reset button, modify the positioning of the resisters (if resisters are too close or nearly touching) until problem is fixed");
delay (300);
actual = 1;                            //once instructions are displayed once, while loop ends, and instructions are never displayed again
trueness = 0;                          //allows program to run the next while loop
  
}

while (trueness == 0) {                //continuously executes until one of the buttons on the breadboard with three buttons is pressed
                                      //the player selects the "level of difficulty" here
val11 = digitalRead(switchPin11);     //if button closest to ground wire is pressed, "delay value" is set to 100 (easy level of difficulty) 
  if (val11 == HIGH)             
  { dels = 100;
  trueness = 1;                        //allows program to exit this while loop
  }
  
 int val12 = digitalRead (switchPin12);  //if button that is second-closest to ground wire is pressed, "delay value" is set to 81  (medium level of difficulty)
   if (val12 == HIGH)
  {dels = 81;
   trueness = 1;                       //allows program to exit this while loop
  }
  
  int val13= digitalRead (switchPin13); //if button that is furthest from ground wire is pressed, "delay value" is set to 62 (hard level of difficulty)
   if (val13== HIGH)
  { dels = 62;
   trueness = 1;                       //allows program to exit this while loop
  }
}

delay (500);
adder = 0;
  while (hit < required) {             //code in the while loop runs when player's score (hit) is smaller than 20 (required)
     randNumber = random(0, 9);        //generates a random integer between 0 and 8

while (randNumber == 0){               //if the random number is 0
  while (tracker < 11) {               //tracker is currently at 0, programs executes this loop
digitalWrite (ledPins [0],HIGH);      //rightmost LED flashes on
int val1 = digitalRead(switchPin1); 
  if (val1 == HIGH) {                  //if the rightmost button is on, adder is 1 (otherwise, adder stays at 0)
   adder = 1; 
  }    
delay (dels);                           //delay value depends on which button on the breadboard with 3 buttons the player had pressed at the beginning of the game
tracker = tracker + 1;                  //after running while loop 10 times, program exits while loop
  }  

hit = hit + adder;                      //adder is added to hit, where hit is total amount of points player has accumulated
  Serial.println(hit);                  //serial monitor will display hit, the total points the player has accumulated
    digitalWrite (ledPins[0],LOW);      //rightmost LED will turn OFF 
 
  delay (200);
    tracker = 0;                        //tracker is set to 0 again (allows program to run other nested while loops when randNumber is a different integer)
    adder = 0;                          //adder set to 0 again 
  randNumber = random(0, 9);            //another random integer is generated

} 
                                          //next few while loops perform the same basic function
                                          //exept, the random integer value is different, so a different LED flashes ON and OFF, and the player must press a different button to make adder = 1, in order to increase their total score
while (randNumber == 1){
  
while (tracker < 11) {
digitalWrite (ledPins [1],HIGH);
int val2 = digitalRead(switchPin2); 
  if (val2 == HIGH) {
   adder = 1; 
  }    
delay (dels);   
tracker = tracker + 1;
  }  

 
hit = hit + adder;
  Serial.println(hit);
    digitalWrite (ledPins[1],LOW);
 
  delay (200);
    tracker = 0;
    adder = 0;
  randNumber = random(0, 9);

}

while (randNumber == 2){
  
while (tracker < 11) {
digitalWrite (ledPins [2],HIGH);
int val3 = digitalRead(switchPin3); 
  if (val3 == HIGH) {
   adder = 1; 
  }    
delay (dels);   
tracker = tracker + 1;
  }  

 
hit = hit + adder;
  Serial.println(hit);
    digitalWrite (ledPins[2],LOW);
 
  delay (200);
    tracker = 0;
    adder = 0;
  randNumber = random(0, 9);

}
while (randNumber == 3){
  
while (tracker < 11) {
digitalWrite (ledPins [3],HIGH);
int val4 = digitalRead(switchPin4); 
  if (val4 == HIGH) {
   adder = 1; 
  }    
delay (dels);   
tracker = tracker + 1;
  }  

hit = hit + adder;
  Serial.println(hit);
    digitalWrite (ledPins[3],LOW);
 
  delay (200);
    tracker = 0;
    adder = 0;
  randNumber = random(0, 9);
} 
while (randNumber == 4){
  
while (tracker < 11) {
digitalWrite (ledPins [4],HIGH);
int val5 = digitalRead(switchPin5); 
  if (val5 == HIGH) {
   adder = 1; 
  }    
delay (dels);   
tracker = tracker + 1;
  }  

hit = hit + adder;
  Serial.println(hit);
    digitalWrite (ledPins[4],LOW);
 
  delay (200);
    tracker = 0;
    adder = 0;
  randNumber = random(0, 9);
}
while (randNumber == 5){
  
while (tracker < 11) {
digitalWrite (ledPins [5],HIGH);
int val6 = digitalRead(switchPin6); 
  if (val6 == HIGH) {
hit = 0;
  }    
delay (dels);   
tracker = tracker + 1;
  }  
  Serial.println(hit);
    digitalWrite (ledPins[5],LOW);
 
  delay (200);
    tracker = 0;
    adder = 0;
  randNumber = random(0, 9);
} 
while (randNumber == 6){
  
while (tracker < 11) {
digitalWrite (ledPins [6],HIGH);
int val7 = digitalRead(switchPin7); 
  if (val7 == HIGH) {
   adder = 1; 
  }    
delay (dels);   
tracker = tracker + 1;
  }  

hit = hit + adder;
  Serial.println(hit);
    digitalWrite (ledPins[6],LOW);
 
  delay (200);
    tracker = 0;
    adder = 0;
  randNumber = random(0, 9);
} 
while (randNumber == 7){
  
while (tracker < 11) {
digitalWrite (ledPins [7],HIGH);
int val8 = digitalRead(switchPin8); 
  if (val8 == HIGH) {
   adder = 1; 
  }    
delay (dels);   
tracker = tracker + 1;
  }  

hit = hit + adder;
  Serial.println(hit);
    digitalWrite (ledPins[7],LOW);
 
  delay (200);
    tracker = 0;
    adder = 0;
  randNumber = random(0, 9);
} 
while (randNumber == 8){
  
while (tracker < 11) {
digitalWrite (ledPins [8],HIGH);
int val9 = digitalRead(switchPin9); 
  if (val9 == HIGH) {
   adder = 1; 
  }    
delay (dels);   
tracker = tracker + 1;
  }  

hit = hit + adder;
  Serial.println(hit);
    digitalWrite (ledPins[8],LOW);
 
  delay (200);
    tracker = 0;
    adder = 0;
  randNumber = random(0, 9);
} 
  }
  
    Serial.println ("YAY, You WIN"); //serial monitor displays YAY, You WIN every 20 seconds
    
      myServo.writeMicroseconds(2000);  // servo motor spins rapidly
  delay(20000);                      


 }
 // 
