//Case one and three: This section will display a quick timer/countdown until the start of the game. Once done, it will move to the next case.
void timer(int r, int g){
  //This will display a loading screen that plays before the game starts.
for (int i = 0; i < 5 && breakOUT == 0; i++) {

    for (int j = 0; j < 150 && breakOUT == 0; j++) {
      CircuitPlayground.setPixelColor(i, j*r, j*g, 0);
      CircuitPlayground.setPixelColor(i + 5, j*r, j*g, 0);
      delay(1);
    }
  }
  CircuitPlayground.clearPixels();
  modeStep++;
}