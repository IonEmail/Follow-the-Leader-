/*Welcome to Follow the Leader!
This game uses the buttons and the switch as inputs.
It will output to the 10 LEDs and even play a tune! It will also output to the serial monitor.

Basic rules:
The game will display a pattern to the 10 LEDs
Upon your turn, you must match that pattern using a combination of inputs.
At the end of your turn, the 10 LEDs will display the pattern you must match and your own pattern.
the goal is match 10 correct LEDs.

In depth rules:
Inputs: button A will move down through the LEDs
         button B will move up through the LEDs
         sliding the switch to the left will lock in an answer, to the right will allow you to make another selection
This game use a switch and cases to run through the game.
Cases:
Case zero: This section will display a loading screen that allows the player time to get ready for the game.
         Once the player is ready, they must press button A in order to start the game.
         Upon pressing button A, the loading screen will complete its cycle then move onto the next case.
Case one: This section will display a quick timer/countdown until the start of the game. Once done, it will move to the next case.
Case two: This section will display the pattern that the player must duplicate. Once the pattern is complete, it will move onto the next case.
Case three: This section will display a quick timer/countdown until the start of the players turn. Once done, it will move to the next case.
Case four: This section is where the player duplictes the pattern. Using button A and B, they will move through the LEDs until they land on their desired LED.
          To pick this LED, they must slide the switch to the left, a selection will be made when the all 10 LEDs light up blue, the players selection will light up red.
          To make another selection, the player must slide the switch to the right, this will turn off all blue LEDs and return the player to the selection stage.
          The game will move on once the player has made the same number of choices as the pattern they must duplicate, it will then move onto the next case.
Case five: This section will display the pattern that they player must duplicate and the pattern the player made.
         The games pattern will show up as red, while players pattern will show up blue. A correct answer will show up green.
         This section will also score the player. The score will be determined by the correct number of selections the player made, adding one point for every correct answer.
         Once done, it will move onto the next case.
Case six:   The score will be displayed onto the 10 LEDs, the number of LEDs that light up will be equal to the players score.
           The player then can choose to play again, increasing the difficulty (adding more LEDs to the pattern). The score will be saved.
           Once the player has input 10 correct LEDs (by playing the game multiple times), the game will move onto the next case.
Case seven: This section will display a winners pattern and play a tune. The game will restart after the cycle is comlete.*/


#include <Adafruit_CircuitPlayground.h>
//varibales need throughout the code
int lvlPick;
int modeStep = 0;
int swiPick = 0;
int selECT = 0;
int playerScore;
int currentLVL;
int lvlC = 3;


int con0 = 0;
int con7 = 0;


// arrays needed to store game data
int Game[100] = {};
int Player[100] = {};

//varibales needed for implementation of controls
int switchC = 7;
int swiFlag = 0;
int switchval = 0;
int buttonAPin = 4;
int buttonBPin = 5;
int UPFlag = 0;
int DOWNFlag = 0;
volatile int modeC = 0;     //used in the switch, allows to pick which case to use.
volatile int breakOUT = 0;  //*******ONLY for breaking out of loops********

//general setup
void setup() {
  delay(2000);
  CircuitPlayground.begin();

  //needed for button usages
  pinMode(buttonAPin, INPUT_PULLDOWN);
  pinMode(buttonBPin, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(switchC), swi, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonAPin), UP, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonBPin), DOWN, FALLING);
}

//UP function sets the state of a flag. Used to determine which input was used
void UP() {
  UPFlag = 1;
}

//DOWN function sets the state of a flag. Used to determine which input was used
void DOWN() {
  DOWNFlag = 1;
}

//swi function sets the state of a flag. Used to determine which input was used
void swi() {
  swiFlag = 1;
}

// main body of code.
//This game uses a switch and cases to move through portions of the game.
void loop() {


    switch (modeStep) {
    case 0:
      loading();
      break;
    case 1:
      timer(1, 0);
      break;
    case 2:
      LEDpickingV4(lvlC);
      break;
    case 3:
      timer(0, 1);
      break;
    case 4:
      playerTurn(lvlC);
      break;
    case 5:
      scoring(lvlC);
      break;
    case 6:
      end();
      break;
    case 7:
      winner();
      break;
    default:
      break;
  }


  delay(10);

}
