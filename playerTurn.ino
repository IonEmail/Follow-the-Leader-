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