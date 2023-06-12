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