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
    lvlC= lvlC + 2;
  }

  //This allows the player to chose if they want to continue the game.
  if (DOWNFlag) {
    delay(10);
    Serial.println(modeC);
    DOWNFlag = 0;
    modeC--;
  }
}