// Case zero: This section will display a loading screen that allows the player time to get ready for the game.
//          Once the player is ready, they must press button A in order to start the game.
//          Upon pressing button A, the loading screen will complete its cycle then move onto the next case.
void loading() {
  //This will display general inputs that can be made
  if(con0 == 0){
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
      CircuitPlayground.setPixelColor(i, j*.5, j*.5, 0);
      delay(1);
    }
  }

  for (int i = 0; i < 10 && breakOUT == 0; i++) {
    for (int j = 255; j > 0 && breakOUT == 0; j--) {
      CircuitPlayground.setPixelColor(i, j*.5, j*.5, 0);
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