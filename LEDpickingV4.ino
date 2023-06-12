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