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

// Case zero: This section will display a loading screen that allows the player time to get ready for the game.
//          Once the player is ready, they must press button A in order to start the game.
//          Upon pressing button A, the loading screen will complete its cycle then move onto the next case.
void loading() {
  //This will display general inputs that can be made
  if (con0 == 0) {
    Serial.println("Ensure this is visable!!");
    Serial.println("\n\n\n\n\n\n\n\n\n\n\n");
    Serial.println("Would you like to play?");
    Serial.println("Press button A for YES.");
    Serial.println("Press button B for NO.");
    con0++;
  }

  // The following code will display a pattern onto the screen, this acts as a loading bar
  for (int i = 0; i < 10 && breakOUT == 0; i++) {

    for (int j = 0; j < 255 && breakOUT == 0; j++) {
      CircuitPlayground.setPixelColor(i, j * .5, j * .5, 0);
      delay(1);
    }
  }

  for (int i = 0; i < 10 && breakOUT == 0; i++) {
    for (int j = 255; j > 0 && breakOUT == 0; j--) {
      CircuitPlayground.setPixelColor(i, j * .5, j * .5, 0);
      delay(1);
    }
  }

  if (UPFlag) {
    delay(10);
    Serial.println(modeC);
    UPFlag = 0;
    modeStep = 1;
    swiPick = 0;
  }

  if (DOWNFlag) {
    delay(10);
    Serial.println(modeC);
    DOWNFlag = 0;
    modeC--;
  }
}

//Case one and three: This section will display a quick timer/countdown until the start of the game. Once done, it will move to the next case.
void timer(int r, int g) {
  //This will display a loading screen that plays before the game starts.
  for (int i = 0; i < 5 && breakOUT == 0; i++) {

    for (int j = 0; j < 150 && breakOUT == 0; j++) {
      CircuitPlayground.setPixelColor(i, j * r, j * g, 0);
      CircuitPlayground.setPixelColor(i + 5, j * r, j * g, 0);
      delay(1);
    }
  }
  CircuitPlayground.clearPixels();
  modeStep++;
}

//Case two: This section will display the pattern that the player must duplicate. Once the pattern is complete, it will move onto the next case.
void LEDpickingV4(int lvl) {

  delay(1000);

  //This for loop will randomize what LED will be used in the pattern, it stores the values into an array.
  for (int i = 0; i < lvl; i++) {
    int randNUM = random(10);
    Game[i] = randNUM;
  }


  //This for loop will display the pattern that is stored in the array.
  for (int j = 0; j < lvl; j++) {
    CircuitPlayground.setPixelColor(Game[j], 255, 0, 0);
    delay(500);
    CircuitPlayground.clearPixels();
    delay(500);
  }

  delay(1000);
  modeStep++;
}

// Case four: This section is where the player duplictes the pattern. Using button A and B, they will move through the LEDs until they land on their desired LED.
//           To pick this LED, they must slide the switch to the left, a selection will be made when the all 10 LEDs light up blue, the players selection will light up red.
//           To make another selection, the player must slide the switch to the right, this will turn off all blue LEDs and return the player to the selection stage.
//           The game will move on once the player has made the same number of choices as the pattern they must duplicate, it will then move onto the next case.
void playerTurn(int ro) {

  // This checks the state of the flag.
  //If in the left position, it will display the LED selected, and add that LED to the players array.
  //If in the right position, it will allow the player to make another selection.
  if (swiFlag) {
    CircuitPlayground.clearPixels();
    delay(5);
    switchval = digitalRead(switchC);
    if (switchval) {
      selECT = 1;
      Player[swiPick] = modeC;
      Serial.print("You picked LED: ");
      Serial.println(modeC);
      swiPick++;
    } else {
      selECT = 0;
    }
    swiFlag = 0;
  }

  // This allows the player to move through the LEDs
  if (UPFlag && !selECT) {
    delay(10);
    CircuitPlayground.clearPixels();
    Serial.println(modeC);
    UPFlag = 0;
    modeC++;
  }

  // This allows the player to move through the LEDs
  if (DOWNFlag && !selECT) {
    delay(10);
    CircuitPlayground.clearPixels();
    Serial.println(modeC);
    DOWNFlag = 0;
    modeC--;
  }

  //this loops around the LED selection.
  if (modeC > 9) {
    modeC = 0;
  } else if (modeC < 0) {
    modeC = 9;
  }

  // if the switch is in the left position, it will display your selection and light up all LEDs.
  if (selECT) {
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
  } else {
    CircuitPlayground.clearPixels();
  }

  // This moves the program onto the next case once the player has picked enough LEDs
  if (swiPick > (ro - 1)) {
    delay(500);
    CircuitPlayground.clearPixels();
    modeStep++;
  }

  CircuitPlayground.setPixelColor(modeC, 0, 0, 255);
}

// Case five: This section will display the pattern that they player must duplicate and the pattern the player made.
//          The games pattern will show up as red, while players pattern will show up blue. A correct answer will show up green.
//          This section will also score the player. The score will be determined by the correct number of selections the player made, adding one point for every correct answer.
//          Once done, it will move onto the next case.
void scoring(int lvl) {

  //This section of the code uses a for loop to compare values in two arrays.
  CircuitPlayground.clearPixels();
  delay(1000);
  for (int i = 0; i < lvl; i++) {
    if (Game[i] == Player[i]) {
      CircuitPlayground.setPixelColor(Game[i], 0, 255, 0);
      CircuitPlayground.playTone(1000, 100);
      CircuitPlayground.playTone(600, 200);
      CircuitPlayground.playTone(1000, 100);
      CircuitPlayground.playTone(800, 200);
      Serial.println("Correct!");
      delay(1000);
      CircuitPlayground.clearPixels();
      delay(1000);
      playerScore++;
    } else {
      CircuitPlayground.setPixelColor(Game[i], 255, 0, 0);
      CircuitPlayground.setPixelColor(Player[i], 0, 0, 255);
      CircuitPlayground.playTone(100, 800);
      delay(1000);
      CircuitPlayground.clearPixels();
      delay(1000);
      Serial.println("NOPE");
    }
  }
  modeStep++;
}

// Case six:   The score will be displayed onto the 10 LEDs, the number of LEDs that light up will be equal to the players score.
//            The player then can choose to play again, increasing the difficulty (adding more LEDs to the pattern). The score will be saved.
//            Once the player has input 10 correct LEDs (by playing the game multiple times), the game will move onto the next case.
void end() {

  //This displays the what the player can input
  if (con7 == 0) {
    CircuitPlayground.clearPixels();
    Serial.print("LEVEL: ");
    Serial.println(currentLVL);
    Serial.print("Your score: ");
    Serial.println(playerScore);
    Serial.println("Do you want to continue?");
    Serial.println("Press button A for YES.");
    Serial.println("Press button B for NO.");
    con7++;
  }

  //This displays the players score on the 10 LEDs
  for (int j = 0; j < playerScore; j++) {
    CircuitPlayground.setPixelColor(j, 255, 255, 50);
    delay(50);
  }

  //This checks if the player has won the game.
  if (playerScore == 10 || playerScore > 10) {
    modeStep++;
  }

  //This allows the player to chose if they want to continue the game.
  if (UPFlag) {
    delay(10);
    Serial.println(modeC);
    UPFlag = 0;
    modeStep = 1;
    swiPick = 0;
    lvlC = lvlC + 2;
  }

  //This allows the player to chose if they want to continue the game.
  if (DOWNFlag) {
    delay(10);
    Serial.println(modeC);
    DOWNFlag = 0;
    modeC--;
  }
}

//Case seven: This section will display a winners pattern and play a tune. The game will restart after the cycle is comlete.
void winner() {
  int ranHLG1 = random(190);
  int ranHLG2 = random(230);
  int ranHLG3 = random(80);

  for (int i = 0; i < 10 && breakOUT == 0; i++) {
    ranHLG1 = random(240);
    ranHLG2 = random(230);
    ranHLG3 = random(80);
    for (int j = 0; j < ranHLG3 && breakOUT == 0; j++) {

      CircuitPlayground.setPixelColor(i, ranHLG1, ranHLG3, j);
      delay(2);
    }
    CircuitPlayground.playTone(1000, 40);
    CircuitPlayground.playTone(600, 80);
    CircuitPlayground.playTone(1000, 40);
    CircuitPlayground.playTone(800, 80);
  }

  for (int i = 0; i < 10 && breakOUT == 0; i++) {
    for (int j = 0; j < 255 && breakOUT == 0; j++) {

      CircuitPlayground.setPixelColor(i, ranHLG1 - j, ranHLG3 - j, 255 - j);
      delay(2);
    }
    CircuitPlayground.playTone(1000, 50);
    CircuitPlayground.playTone(600, 100);
  }

  modeStep = 0;
  playerScore = 0;
  lvlC = 3;
}