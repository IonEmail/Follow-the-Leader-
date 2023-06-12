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